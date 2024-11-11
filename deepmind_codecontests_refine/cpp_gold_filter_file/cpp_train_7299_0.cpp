#include <bits/stdc++.h>
using namespace std;
const int K = 300005;
pair<pair<int, int>, int> sg[K];
int n, m, k, rt[K], tot, mn[K * 40], ls[K * 40], rs[K * 40];
void update(int &u, int lst, int l, int r, int pos, int val) {
  u = ++tot;
  ls[u] = ls[lst];
  rs[u] = rs[lst];
  if (l == r) {
    mn[u] = max(val, mn[lst]);
    return;
  }
  int mid = l + r >> 1;
  if (pos <= mid)
    update(ls[u], ls[lst], l, mid, pos, val);
  else
    update(rs[u], rs[lst], mid + 1, r, pos, val);
  mn[u] = min(mn[ls[u]], mn[rs[u]]);
}
int query(int u, int l, int r, int first, int second) {
  if (first <= l && r <= second) return mn[u];
  int resl = 1e9 + 5, resr = 1e9 + 5, mid = l + r >> 1;
  if (first <= mid) resl = query(ls[u], l, mid, first, second);
  if (second > mid) resr = query(rs[u], mid + 1, r, first, second);
  return min(resl, resr);
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= k; i++) {
    scanf("%d%d%d", &sg[i].first.first, &sg[i].first.second, &sg[i].second);
  }
  sort(sg + 1, sg + 1 + k,
       [](const pair<pair<int, int>, int> &a,
          const pair<pair<int, int>, int> &b) {
         return a.first.second < b.first.second;
       });
  for (int i = 1; i <= k; i++) {
    update(rt[i], rt[i - 1], 1, n, sg[i].second, sg[i].first.first);
  }
  for (int a, b, first, second, i = 1; i <= m; i++) {
    scanf("%d%d%d%d", &a, &b, &first, &second);
    int l = 0, r = k + 1, mid;
    while (l < r - 1) {
      mid = l + r >> 1;
      if (sg[mid].first.second <= second)
        l = mid;
      else
        r = mid;
    }
    query(rt[l], 1, n, a, b) >= first ? puts("yes") : puts("no");
    fflush(stdout);
  }
  return 0;
}
