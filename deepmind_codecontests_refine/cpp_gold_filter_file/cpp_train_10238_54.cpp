#include <bits/stdc++.h>
using namespace std;
const unsigned _mod = 998244353;
const unsigned mod = 1e9 + 7;
const long long infi = 0x3f3f3f3f3f3f3f3fll;
const int inf = 0x3f3f3f3f;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
long long qpow(long long x, long long y, long long m) {
  long long ret = 1;
  while (y) {
    if (y & 1ll) ret = ret * x % m;
    y >>= 1ll;
    x = x * x % m;
  }
  return ret;
}
long long ksm(long long x, long long y) {
  long long ret = 1;
  while (y) {
    if (y & 1ll) ret = ret * x % mod;
    y >>= 1ll;
    x = x * x % mod;
  }
  return ret;
}
long long _gcd(long long x, long long y) { return y ? _gcd(y, x % y) : x; }
bool s[2010][2010];
long long a, b, c, d, n, m, x, y;
void dfs(long long i, long long j) {
  s[i][j] = 0, m++;
  if (i > a || (i == a && j > b)) a = i, b = j;
  if (i < c || (i == c && j < d)) c = i, d = j;
  if (i + 1 < n && s[i + 1][j]) dfs(i + 1, j);
  if (j + 1 < n && s[i][j + 1]) dfs(i, j + 1);
  if (j > 1 && s[i][j - 1]) dfs(i, j - 1);
  if (i > 1 && s[i - 1][j]) dfs(i - 1, j);
}
int main() {
  cin >> n;
  for (register int i = 1; i <= n; ++i)
    for (register int j = 1; j <= n; ++j) s[i][j] = read();
  for (register int i = 1; i <= n; ++i)
    for (register int j = 1; j <= n; ++j)
      if (s[i][j]) {
        m = 0, a = d = 0, b = c = 20001;
        dfs(i, j);
        double e = (a - c) * (a - c) + (b - d) * (b - d), m1 = e / 2.0;
        if (m < 200) continue;
        if (m >= m1 * 1.095)
          x++;
        else
          y++;
      }
  cout << x << ' ' << y << '\n';
  return 0;
}
