#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 5e3;
int n, k;
int S[N + 10][N + 10];
inline int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') f |= ch == '-', ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return f ? -x : x;
}
void init() {
  S[0][0] = 1;
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= i; j++) {
      S[i][j] = (S[i - 1][j - 1] + 1ll * S[i - 1][j] * j % mod) % mod;
    }
  }
}
inline int qpow(int a, int b) {
  int ans = 1;
  for (; b; b >>= 1, a = 1ll * a * a % mod)
    if (b & 1) ans = 1ll * ans * a % mod;
  return ans;
}
int inv(int x) { return qpow(x, mod - 2); }
int main() {
  n = read(), k = read();
  init();
  int ans = 0;
  int fac = 1, x = 1;
  for (int i = 1; i <= min(n, k); i++) {
    x = 1ll * x * (n - i + 1) % mod * inv(i) % mod;
    fac = 1ll * fac * i % mod;
    ans = (ans + 1ll * x * S[k][i] % mod * fac % mod * qpow(2, n - i)) % mod;
  }
  printf("%d\n", ans);
  return 0;
}
