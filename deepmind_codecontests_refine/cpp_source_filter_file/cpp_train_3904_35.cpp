#include <bits/stdc++.h>
using namespace std;
inline long long gcd(long long x, long long y) { return x ? gcd(y % x, x) : y; }
const long long mod = 1e9 + 7;
inline signed rd() {
  signed ans = 0;
  char last = ' ', ch = getchar();
  while (!(ch >= '0' && ch <= '9')) last = ch, ch = getchar();
  while (ch >= '0' && ch <= '9')
    ans = (ans << 3) + (ans << 1) + ch - '0', ch = getchar();
  return ans;
}
inline long long QPow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
inline long long QPow(long long a, long long b, const long long &mod) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
long long exgcd(long long a, long long b, long long &x, long long &y) {
  long long d = a;
  if (b == 0)
    x = 1, y = 0;
  else {
    d = exgcd(b, a % b, y, x), y -= a / b * x;
  }
  return d;
}
const long double PI = 3.141592653589793115997963468544185161590576171875;
const long long maxn = 1005;
pair<signed, signed> p[maxn];
unsigned long long dp[36][36];
unsigned long long fac[36];
signed main5D() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  signed n, h;
  fac[0] = 1;
  for (long long i = 1; i < 36; i++) fac[i] = fac[i - 1] * i;
  for (long long i = 0; i < 36; i++) cout << fac[i] << ' ';
  cout << endl;
  cin >> n >> h;
  dp[0][0] = 1;
  for (long long i = 1; i <= n; i++) {
    for (long long j = i; j <= h; j++) {
      if (i == j)
        dp[i][j] = 1 + (i != 1);
      else {
        for (long long k = 0; k < i; k++) {
          dp[i][j] -= dp[k][j - 1] * dp[i - 1 - k][j - 1];
          dp[i][j] +=
              dp[k][j - 1] * fac[k] + dp[i - 1 - k][j - 1] * fac[i - 1 - k];
        }
      }
    }
    for (long long j = i; j <= h; j++) dp[i][j] += dp[i][j - 1];
  }
  cout << dp[h][n];
  system("pause");
  return 0;
}
bool vis[102][102];
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  signed n, t, m, u, v, r, x, w, k;
  cin >> n >> m >> k;
  for (long long i = 1; i <= k; i++)
    cin >> p[i].first >> p[i].second, vis[p[i].first][p[i].second] = 1;
  signed mn = n + m;
  for (long long i = 1; i <= k; i++)
    mn = min(
        {p[i].first - 1, p[i].second - 1, n - p[i].first, m - p[i].second, mn});
  if (mn <= 2)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
