#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 5;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long llINF = 0x3f3f3f3f3f3f3f3f;
long long make_compiler_happy() { return INF & maxn & mod & llINF; }
long long fpow(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long inv(long long x) { return fpow(x, mod - 2); }
int x[maxn], y[maxn];
int a[maxn];
int n, m, r;
int sum[maxn / 2][maxn / 2];
int C[maxn][maxn];
int num[maxn];
int getsum(int x1, int y1, int x2, int y2) {
  x1 = max(0, x1 - 1);
  y1 = max(0, y1 - 1);
  x2 = min(x2, 1000);
  y2 = min(y2, 1000);
  return sum[x2][y2] - sum[x2][y1] - sum[x1][y2] + sum[x1][y1];
}
int getsum(int i, int j) {
  int x1 = x[i], x2 = x[j];
  if (x1 > x2) swap(x1, x2);
  int y1 = y[i], y2 = y[j];
  if (y1 > y2) swap(y1, y2);
  if (x1 + r < x2 - r) return 0;
  if (y1 + r < y2 - r) return 0;
  return getsum(x2 - r, y2 - r, x1 + r, y1 + r);
}
int getsum(int i) { return getsum(x[i] - r, y[i] - r, x[i] + r, y[i] + r); }
int c(int n, int m) {
  if (n < m || m < 0) return 0;
  return C[n][m];
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> r;
  for (int i = 0; i < (n); i++) {
    cin >> x[i] >> y[i] >> a[i];
    sum[x[i]][y[i]]++;
  }
  for (int i = (0); i <= (n + 1); i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = (1); j <= (i - 1); j++)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
  }
  for (int i = (1); i <= (1000); i++)
    for (int j = (1); j <= (1000); j++)
      sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
  long long ans = 0;
  for (int i = 0; i < (n); i++) {
    int ti = getsum(i);
    ans += (long long)(c(n, m) - c(n - ti, m)) * a[i] % mod * a[i];
    ans %= mod;
    for (int j = 0; j < (i); j++) {
      int t = getsum(i, j), tj = getsum(j);
      ans += 2LL * (c(n, m) - c(n - t, m)) * a[i] % mod * a[j];
      ans +=
          2LL *
          (c(n - t, m) - c(n - ti, m) - c(n - tj, m) + c(n + t - ti - tj, m)) *
          a[i] % mod * a[j];
      ans %= mod;
    }
  }
  if (ans < 0) ans += mod;
  cout << ans << '\n';
}
