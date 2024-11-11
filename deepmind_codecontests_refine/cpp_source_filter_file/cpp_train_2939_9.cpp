#include <bits/stdc++.h>
using namespace std;
const int N = 5050, md = 1e9 + 7;
int n, m, c[N], s[N], h[N];
int ctt[N], p[N], mxc, ans;
int tL[N], tR[N];
short totL[N][N], totR[N][N], A[N][N];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> c[i];
  for (int i = 1; i <= m; ++i) cin >> s[i] >> h[i];
  for (int i = 1; i <= n; ++i) A[c[i]][++ctt[c[i]]] = i, p[i] = ctt[c[i]];
  for (int i = 1; i <= m; ++i)
    if (ctt[s[i]] >= h[i]) {
      ++totL[s[i]][h[i]];
      ++totR[s[i]][ctt[s[i]] + 1 - h[i]];
    }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= ctt[i]; ++j) totL[i][j] += totL[i][j - 1];
    for (int j = ctt[i]; j; --j) totR[i][j] += totR[i][j + 1];
  }
  for (int t = 1; t <= n; ++t) {
    int lk = totL[c[t]][p[t]] - totL[c[t]][p[t] - 1], rk = totR[c[t]][p[t] + 1];
    if (lk == 0) continue;
    if (p[t] <= ctt[c[t]] - p[t]) --rk;
    int res = 1, tot = 0;
    if (!rk)
      res = lk, ++tot;
    else
      res = (long long)lk * rk % md, tot += 2;
    memset(tL, 0, sizeof tL);
    memset(tR, 0, sizeof tR);
    for (int i = t - 1; i; --i)
      if (!tL[c[i]]) tL[c[i]] = totL[c[i]][p[i]];
    for (int i = t + 1; i <= n; ++i)
      if (!tR[c[i]]) tR[c[i]] = totR[c[i]][p[i]];
    for (int col = 1; col <= n; ++col)
      if (col != c[t] && (tL[col] || tR[col])) {
        if (tL[col] && tR[col] && tL[col] + tR[col] > 2) {
          res = ((long long)tL[col] * tR[col] - min(tL[col], tR[col])) % md *
                res % md;
          tot += 2;
        } else {
          res = (long long)res * (tL[col] + tR[col]) % md;
          ++tot;
        }
      }
    if (tot > mxc)
      mxc = tot, ans = res;
    else if (tot == mxc)
      ans = (ans + res) % md;
  }
  int res = 1, tot = 0;
  for (int i = 1; i <= n; ++i)
    if (totR[i][1]) {
      res = (long long)res * totR[i][1];
      ++tot;
    }
  if (tot > mxc)
    mxc = tot, ans = res;
  else if (tot == mxc)
    ans = (ans + res) % md;
  cout << mxc << ' ' << ans << '\n';
  return 0;
}
