#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7, maxn = 2e5 + 20;
int n, k, m, x, y, q, a[maxn], b[maxn], cnt[maxn << 2];
std::vector<int> v[maxn];
std::vector<pair<int, int> > p[maxn];
int ans[maxn];
void upd(int pos, int val = 1, int id = 1, int l = 0, int r = n) {
  if (r - l == 1) {
    cnt[id] += val;
    return;
  }
  int mid = (l + r) >> 1;
  if (pos < mid)
    upd(pos, val, id >> 1, l, mid);
  else
    upd(pos, val, id >> 1 | 1, mid, r);
  cnt[id] = cnt[id << 1] + cnt[id << 1 | 1];
}
int get(int s, int e, int id = 1, int l = 0, int r = n) {
  if (s >= r || e <= l) return 0;
  if (s <= l && e >= r) return cnt[id];
  int mid = (l + r) >> 1;
  return get(s, e, id >> 1, l, mid) + get(s, e, id >> 1 | 1, mid, r);
}
int32_t main() {
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    b[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) v[j].push_back(b[i]);
  }
  for (int i = 0; i < q; i++) {
    scanf("%d%d", &x, &y);
    x--;
    p[x].push_back(make_pair(y, i));
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j : v[a[i]])
      if (j >= i) {
        upd(j);
      }
    for (int j = a[i] * 2; j <= n; j += a[i])
      if (b[j] > i) {
        upd(b[j]);
      }
    for (int j = 0; j < p[i].size(); j++) {
      ans[p[i][j].second] = get(i, p[i][j].first);
    }
  }
  for (int i = 0; i < q; i++) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
