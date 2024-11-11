#include <bits/stdc++.h>
using namespace std;
const int N = 2050;
const int K = 100050;
const long long mod = 1e9 + 7;
inline void rd(long long &x) {
  x = 0;
  char ch = getchar();
  bool flag = 0;
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') flag = 1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10ll + ch - '0', ch = getchar();
  if (flag) x = -x;
}
inline void rd(int &x) {
  x = 0;
  char ch = getchar();
  bool flag = 0;
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') flag = 1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  if (flag) x = -x;
}
inline char rch() {
  char c;
  while ((c = getchar()) != 'A' && c != 'B' && c != 'C')
    ;
  return c;
}
long long n, m, a, b, k, D[N], inv[K], fac[K], A[K], B[K], SD[N];
inline long long ksm(long long x, long long y) {
  long long ans = 1ll;
  while (y) {
    if (y & 1) ans = ans * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
inline long long C(long long n, long long m) {
  if (n < m) return 0ll;
  return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
inline void prework() {
  fac[0] = fac[1] = inv[1] = inv[0] = 1ll;
  for (long long i = 2ll; i <= k; ++i) fac[i] = fac[i - 1] * i % mod;
  for (long long i = 2ll; i <= k; ++i)
    inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
  for (int i = 2; i <= k; ++i) inv[i] = inv[i] * inv[i - 1] % mod;
  B[1] = (b - a);
  b = ksm(b, mod - 2);
  A[0] = B[0] = 1ll;
  A[1] = a * b % mod;
  B[1] = B[1] * b % mod;
  for (int i = 2; i <= k; ++i)
    A[i] = A[i - 1] * A[1] % mod, B[i] = B[i - 1] * B[1] % mod;
  for (int i = 0; i <= m; ++i)
    D[i] = C(k, i) * A[i] % mod * B[k - i] % mod, SD[i] = SD[i - 1] + D[i - 1],
    SD[i] %= mod;
}
long long L[2][N], S[2][N], LD[N];
int main() {
  rd(n);
  rd(m);
  rd(a);
  rd(b);
  rd(k);
  prework();
  S[0][m] = 1;
  L[0][m] = 1;
  for (int j = 1; j <= n; ++j) {
    int op = (j & 1);
    for (int i = 1; i <= m; ++i) {
      S[op][i] = D[m - i] *
                 ((L[op ^ 1][m] - L[op ^ 1][m - i] + mod) % mod * SD[i] % mod -
                  LD[i] + mod) %
                 mod;
      L[op][i] = L[op][i - 1] + S[op][i];
      L[op][i] %= mod;
      LD[i] = LD[i - 1] + D[i - 1] * L[op][i - 1] % mod;
      LD[i] %= mod;
    }
  }
  cout << L[n & 1][m] << endl;
  return 0;
}
