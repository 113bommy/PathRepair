#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
const int mod = 1e+9 + 7;
inline long long powa(long long a, long long x) {
  long long ans = 1;
  for (; x; x >>= 1) {
    if (x & 1) ans = ans * a % mod;
    a = a * a % mod;
  }
  return ans;
}
inline long long inv(long long a) { return powa(a, mod - 2); }
long long n, m;
long long p[maxn], pi[maxn];
long long a[maxn], b[maxn], bn;
long long f[maxn][maxn];
void pre() {
  long long i;
  p[0] = pi[0] = 1;
  for (i = 1; i < maxn; i++)
    p[i] = p[i - 1] * i % mod, pi[i] = pi[i - 1] * inv(i) % mod;
}
void read() {
  long long i, j;
  char c;
  scanf("%d%d", &n, &m);
  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++) {
      cin >> c;
      a[j] |= ((c == '1') * 1ll << i);
    }
  sort(a, a + n);
  bn = 0;
  for (i = 0; i < n; i = j) {
    for (j = i + 1; j < n && a[j] == a[i]; j++)
      ;
    b[bn++] = j - i;
  }
}
long long C(long long n, long long r) {
  if (r > n || r < 0) return 0;
  return p[n] * pi[r] % mod * pi[n - r] % mod;
}
void dp(long long n) {
  if (f[n][n] != -1) return;
  long long i, j;
  for (i = 1; i <= n; i++) f[n][i] = powa(i, n);
  for (i = 2; i <= n; i++) {
    for (j = i - 1; j >= 1; j--)
      f[n][i] = (f[n][i] - f[n][j] * C(i, j) % mod + mod) % mod;
  }
}
void solve() {
  long long i, j, ans, fans = 1;
  memset(f, -1, sizeof(f));
  for (i = 0; i < bn; i++) {
    ans = 0;
    dp(b[i]);
    for (j = 1; j <= b[i]; j++) ans += f[b[i]][j] * pi[j] % mod;
    (fans *= ans % mod) %= mod;
  }
  cout << fans;
}
int main() {
  pre();
  read();
  solve();
  return 0;
}
