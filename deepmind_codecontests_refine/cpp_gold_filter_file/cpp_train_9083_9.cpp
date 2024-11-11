#include <bits/stdc++.h>
using namespace std;
const int maxn = 6e3 + 5;
int n, len, val[maxn], dp[maxn];
struct seg {
  int id, l, r;
} a[maxn];
vector<seg> segs[maxn + maxn];
void compress() {
  set<int> s;
  map<int, int> id;
  for (int i = 0; i <= n; i++) s.insert({a[i].l, a[i].r});
  len = 1;
  for (int x : s) id[x] = len++;
  for (int i = 0; i <= n; i++) a[i].l = id[a[i].l], a[i].r = id[a[i].r];
}
void wasp(seg cur) {
  dp[cur.l - 1] = 0;
  for (int i = cur.l; i <= cur.r; i++) {
    dp[i] = dp[i - 1];
    for (seg& t : segs[i])
      if (t.id != cur.id && t.l >= cur.l) {
        dp[i] = max(dp[i], val[t.id] + dp[t.l - 1]);
      }
  }
  val[cur.id] = dp[cur.r] + 1;
}
void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d %d", &a[i].l, &a[i].r), a[i].id = i;
  a[n] = {n, 1, int(3e5)};
  compress();
  sort(a, a + n + 1, [&](seg& x, seg& y) {
    return (x.r < y.r) || (x.r == y.r && x.l > y.l);
  });
  for (int i = 0; i <= n; i++) segs[a[i].r].emplace_back(a[i]);
  for (int i = 0; i <= n; i++) wasp(a[i]);
  printf("%d\n", val[n] - 1);
  for (int i = 0; i < len; i++) segs[i].clear();
  memset(dp, 0, sizeof(int) * (len + 1));
  memset(val, 0, sizeof(int) * n);
}
int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) solve();
  return 0;
}
