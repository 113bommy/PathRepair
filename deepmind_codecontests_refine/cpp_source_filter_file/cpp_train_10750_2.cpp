#include <bits/stdc++.h>
using namespace std;
int a[300000];
pair<pair<int, int>, int> queries[300000];
int ans[300000];
int bit[300000];
pair<int, int> tree[1 << 20];
int lazy[1 << 20];
int build(int s, int e, int i) {
  if (s == e) {
    tree[i] = make_pair(1e9, s), lazy[i] = 0;
    return 0;
  }
  int mid = (s + e) / 2;
  build(s, mid, 2 * i + 1), build(mid + 1, e, 2 * i + 2);
  tree[i] = make_pair(1e9, s), lazy[i] = 0;
  return 0;
}
int prop(int s, int e, int i) {
  tree[i].first += lazy[i];
  if (s != e) lazy[2 * i + 1] += lazy[i], lazy[2 * i + 2] += lazy[i];
  lazy[i] = 0;
  return 0;
}
int update(int s, int e, int as, int ae, int i, int num) {
  prop(s, e, i);
  if ((s > ae) || (e < as))
    return 0;
  else if ((s >= as) && (e <= ae)) {
    lazy[i] += num;
    prop(s, e, i);
    return 0;
  }
  int mid = (s + e) / 2;
  update(s, mid, as, ae, 2 * i + 1, num),
      update(mid + 1, e, as, ae, 2 * i + 2, num);
  tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
  return 0;
}
int main() {
  int i;
  int n, q, x, y;
  scanf("%d %d", &n, &q);
  for (i = 0; i < n; i++) scanf("%d", &a[i]), a[i] = i + 1 - a[i];
  for (i = 0; i < q; i++)
    scanf("%d %d", &x, &y), queries[i] = make_pair(make_pair(x, y), i);
  sort(queries, queries + q);
  int j = q - 1, k;
  build(0, n - 1, 0);
  for (i = n - 1; i >= 0; i--) {
    if (a[i] >= 0) update(0, n - 1, i, i, 0, a[i] - (int)1e9);
    while (tree[0].first + lazy[0] <= 0) {
      int p = tree[0].second;
      update(0, n - 1, p, p, 0, 1e9);
      for (k = p + 1; k <= n; k += k & (-k)) bit[k]++;
      update(0, n - 1, p + 1, n - 1, 0, -1);
    }
    while ((j >= 0) && (queries[j].first.first == i)) {
      int a = 0;
      for (k = n - queries[j].first.second; k > 0; k -= k & (-k)) a += bit[k];
      ans[queries[j].second] = a;
      j--;
    }
  }
  for (i = 0; i < q; i++) printf("%d\n", ans[i]);
  return 0;
}
