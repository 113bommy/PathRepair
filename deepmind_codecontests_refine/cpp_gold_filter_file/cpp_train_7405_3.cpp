#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0;
  int f = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + (ch ^ 48);
  return x * f;
}
void print(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}
const int N = 100010, mod = 1000000007;
int n, m;
long long dp[N], f[N], rem[60][60];
long long cnt[60], fac[N], w;
char c[N];
long long qpow(long long a, int b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod, b >>= 1;
  }
  return ans;
}
int num(char c) {
  if (c <= 'Z') return c - 'A' + 1;
  return c - 'a' + 27;
}
void get_w() {
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
  w = fac[m] * fac[m] % mod;
  for (int i = 1; i <= 52; i++)
    if (cnt[i]) w = w * qpow(fac[cnt[i]], mod - 2) % mod;
}
void init() {
  get_w();
  dp[0] = 1;
  for (int i = 1; i <= 52; i++)
    if (cnt[i])
      for (int j = m; j >= cnt[i]; j--) dp[j] = (dp[j] + dp[j - cnt[i]]) % mod;
  for (int i = 1; i <= 52; i++)
    if (cnt[i])
      for (int j = 1; j <= 52; j++)
        if (cnt[j]) {
          for (int k = 0; k <= m; k++) f[k] = dp[k];
          for (int k = cnt[i]; k <= m; k++)
            f[k] = (f[k] - f[k - cnt[i]] + mod) % mod;
          if (i ^ j)
            for (int k = cnt[j]; k <= m; k++)
              f[k] = (f[k] - f[k - cnt[j]] + mod) % mod;
          rem[i][j] = f[m];
        }
}
int main() {
  scanf("%s", c + 1), n = strlen(c + 1), m = n / 2;
  for (int i = 1; i <= n; i++) cnt[num(c[i])]++;
  init();
  int q = read();
  while (q--) {
    int x = read(), y = read();
    int a = num(c[x]), b = num(c[y]);
    print(rem[a][b] * w % mod * 2 % mod), putchar('\n');
  }
  return 0;
}
