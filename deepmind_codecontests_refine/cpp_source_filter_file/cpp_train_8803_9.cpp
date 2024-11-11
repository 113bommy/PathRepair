#include <bits/stdc++.h>
using namespace std;
const int maxn = 500010, inf = 1e9, mod = 1e9 + 7;
int n, ans, cnt;
int fac[maxn], inv[maxn], f[26][maxn], b[maxn], sum[26];
char s[maxn];
template <typename T>
inline void read(T &k) {
  int f = 1;
  k = 0;
  char c = getchar();
  while (c < '0' || c > '9') c == '-' && (f = -1), c = getchar();
  while (c <= '9' && c >= '0') k = k * 10 + c - '0', c = getchar();
  k *= f;
}
inline int power(int a, int b) {
  int ans = 1;
  for (; b; b >>= 1, a = 1ll * a * a % mod)
    if (b & 1) ans = 1ll * a * ans % mod;
  return ans;
}
inline int C(int n, int m) {
  return (n < m) ? 0 : 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;
}
int main() {
  read(n);
  scanf("%s", s + 1);
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  inv[n] = power(fac[n], mod - 2);
  for (int i = n; i; i--) inv[i - 1] = 1ll * inv[i] * i % mod;
  for (int i = 1; i <= n; i++)
    if (s[i] != s[i - 1]) b[++cnt] = s[i] - 'a';
  sum[0] = 2;
  for (int i = 0; i < 26; i++) f[i][0] = 1;
  for (int i = 1; i <= cnt; i++) {
    for (int j = i; j; j--) {
      int tmp = ((sum[j - 1] - f[b[i]][j - 1] + mod) >= mod
                     ? (sum[j - 1] - f[b[i]][j - 1] + mod) - mod
                     : (sum[j - 1] - f[b[i]][j - 1] + mod));
      sum[j] = ((((sum[j] - f[b[i]][j] + mod) >= mod
                      ? (sum[j] - f[b[i]][j] + mod) - mod
                      : (sum[j] - f[b[i]][j] + mod)) +
                 tmp) >= mod
                    ? (((sum[j] - f[b[i]][j] + mod) >= mod
                            ? (sum[j] - f[b[i]][j] + mod) - mod
                            : (sum[j] - f[b[i]][j] + mod)) +
                       tmp) -
                          mod
                    : (((sum[j] - f[b[i]][j] + mod) >= mod
                            ? (sum[j] - f[b[i]][j] + mod) - mod
                            : (sum[j] - f[b[i]][j] + mod)) +
                       tmp));
      f[b[i]][j] = tmp;
    }
  }
  for (int i = 1; i <= cnt; i++) {
    int sum = 0;
    for (int j = 0; j < 26; j++)
      sum = ((sum + f[j][i]) >= mod ? (sum + f[j][i]) - mod : (sum + f[j][i]));
    ans = (ans + 1ll * sum * C(n - 1, i - 1)) % mod;
  }
  printf("%d\n", ans);
}
