#include <bits/stdc++.h>
using namespace std;
bool isp[1000500];
int pr[1000500], g[1000500], F[1000500][20 + 1], n, r, k, ans, cur, cnt;
inline int rd() {
  int r;
  scanf("%d", &r);
  return r;
}
void _pre() {
  for (int _ = 2; _ <= 1000000; _++) {
    if (!isp[_]) pr[++cnt] = _;
    for (int i = 1; i <= cnt && pr[i] * _ <= 1000000; i++) {
      isp[_ * pr[i]] = 1;
      if (_ % pr[i] == 0) break;
    }
  }
  for (int _ = 2; _ <= 1000000; _++)
    if (isp[_]) {
      for (int i = 1; i <= cnt; i++)
        if (_ % pr[i] == 0) {
          g[_] = pr[i];
          break;
        }
    } else
      g[_] = _;
  for (int _ = 0; _ <= 1000000; _++) F[_][0] = 1;
  for (int _ = 1; _ <= 20; _++) F[0][_] = 2;
  for (int _ = 1; _ <= 1000000; _++)
    for (int i = 1; i <= 20; i++)
      F[_][i] = (F[_ - 1][i] + F[_][i - 1]) % 1000000007;
}
int main() {
  _pre();
  for (int T = rd(); T; T--) {
    r = rd(), n = rd(), ans = 1, cur = 0, k = 0;
    while (n != 1) {
      if (g[n] == cur) {
        k++;
      } else {
        ans = 1LL * ans * F[r][k] % 1000000007;
        cur = g[n];
        k = 1;
      }
      n /= g[n];
    }
    k ? ans = 1LL * ans * F[r][k] % 1000000007 : 0;
    printf("%d\n", (int)ans);
  }
  return 0;
}
