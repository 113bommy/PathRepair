#include <bits/stdc++.h>
using namespace std;
const long long N = 2050;
long long n, m, ans = 0;
long long f[N], dp[N], dy[N][2], vmi[N][N];
struct Node {
  long long a, d;
} t[N];
struct Data {
  long long id, tp;
} h[N];
bool cmp(const Node &a, const Node &b) { return a.a < b.a; }
bool cmp2(const Data &a, const Data &b) {
  return t[a.id].a - a.tp * t[a.id].d < t[b.id].a - b.tp * t[b.id].d;
}
long long qmin(long long a, long long b) {
  if (t[a].a - t[a].d < t[b].a - t[b].d)
    return a;
  else
    return b;
}
int main() {
  long long i, j, pos, X, R, _id, _tp, bid, btp, top;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> t[i].a >> t[i].d;
  sort(t + 1, t + n + 1, cmp);
  for (i = 1; i <= n; i++) {
    f[i] = i;
    for (j = 1; j < i; j++) {
      if (t[j].a >= t[i].a - t[i].d) f[i] = qmin(f[i], f[j]);
    }
  }
  for (i = 1; i <= n; i++) {
    vmi[i][i] = f[i];
    for (j = i + 1; j <= n; j++) {
      vmi[i][j] = qmin(vmi[i][j - 1], f[j]);
    }
  }
  m = 0;
  for (i = 1; i <= n; i++) h[++m] = (Data){i, 1}, h[++m] = (Data){i, 0};
  t[++n] = (Node){(long long)5e8, 0};
  h[++m] = (Data){n, 0};
  sort(h + 1, h + m + 1, cmp2);
  for (i = 1; i <= m; i++) dy[h[i].id][h[i].tp] = i;
  for (i = m; i >= 1; i--) {
    ans = max(ans, dp[i]);
    X = t[h[i].id].a - h[i].tp * t[h[i].id].d;
    pos = n;
    while (pos > 0 && t[pos].a >= X) pos--;
    if (pos == 0) continue;
    dp[dy[f[pos]][1]] =
        max(dp[dy[f[pos]][1]], dp[i] + t[pos].a - t[f[pos]].a + t[f[pos]].d);
    R = 0;
    _id = pos;
    _tp = 0;
    top = pos;
    for (j = pos; j >= 1; j--) {
      R = max(R, t[j].a);
      if (t[j].a < t[_id].a - _tp * t[_id].d) _id = j, _tp = 0;
      while (top > 1 && t[top - 1].a >= t[_id].a - _tp * t[_id].d) top--;
      bid = _id;
      btp = _tp;
      if (top < j) {
        if (t[vmi[top][j - 1]].a - t[vmi[top][j - 1]].d <
            t[bid].a - btp * t[bid].d)
          bid = vmi[top][j - 1], btp = 1;
      }
      if (t[j].a + t[j].d >= R) {
        dp[dy[bid][btp]] =
            max(dp[dy[bid][btp]],
                dp[i] + min(t[j].a + t[j].d, X) - t[bid].a + btp * t[bid].d);
      }
      if (t[j].a - t[j].d < t[_id].a - _tp * t[_id].d) _id = j, _tp = 1;
    }
  }
  cout << ans;
  return 0;
}
