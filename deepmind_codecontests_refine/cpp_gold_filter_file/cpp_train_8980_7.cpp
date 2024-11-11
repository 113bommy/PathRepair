#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000 + 10;
long long c[maxn][maxn];
int x[maxn], y[maxn], d[maxn];
int s[maxn][maxn];
const long long mod = 1e9 + 7;
inline int calc(int lx, int ly, int hx, int hy) {
  if (lx > hx || ly > hy) return 0;
  lx = max(lx, 1), ly = max(ly, 1), hx = min(hx, 1000), hy = min(hy, 1000);
  return s[hx][hy] - s[lx - 1][hy] - s[hx][ly - 1] + s[lx - 1][ly - 1];
}
int main() {
  int n, m, r;
  scanf("%d %d %d", &n, &m, &r);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d %d", &x[i], &y[i], &d[i]);
    s[x[i]][y[i]]++;
  }
  for (int i = 1; i <= 1000; i++)
    for (int j = 1; j <= 1000; j++)
      s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
  for (int i = 0; i <= n; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++)
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      long long nw = 1ll * d[i] * d[j] % mod;
      long long noi = c[n - calc(x[i] - r, y[i] - r, x[i] + r, y[i] + r)][m];
      long long noj = c[n - calc(x[j] - r, y[j] - r, x[j] + r, y[j] + r)][m];
      long long noij =
          c[n - calc(x[i] - r, y[i] - r, x[i] + r, y[i] + r) -
            calc(x[j] - r, y[j] - r, x[j] + r, y[j] + r) +
            calc(max(x[i] - r, x[j] - r), max(y[i] - r, y[j] - r),
                 min(x[i] + r, x[j] + r), min(y[i] + r, y[j] + r))][m];
      long long no = (((c[n][m] - noi) % mod - noj) % mod + noij) % mod;
      no = (no + mod) % mod;
      ans += no * nw % mod;
      ans %= mod;
    }
  printf("%lld\n", ans);
  return 0;
}
