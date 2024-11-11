#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T &x) {
  int f = 0;
  x = 0;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  if (f) x = -x;
}
const int N = 5005, mod = 1e9 + 7;
int f[N][N], a[N], n, K, las = 1;
int power(int x, int p) {
  int res = 1;
  for (; p; p >>= 1, x = (long long)x * x % mod)
    if (p & 1) res = (long long)res * x % mod;
  return res;
}
int main() {
  read(n), read(K);
  for (int i = (1); i <= (n); i++)
    read(a[i]), las = (long long)las * a[i] % mod;
  f[0][0] = 1;
  for (int i = (1); i <= (n); i++) {
    f[i][0] = (long long)f[i - 1][0] * a[i];
    for (int j = (1); j <= (i); j++)
      f[i][j] = ((long long)f[i - 1][j] * a[i] + mod - f[i - 1][j - 1]) % mod;
  }
  int prod = 1, ans = 0;
  for (int i = (K); i >= (max(0, K - n)); i--) {
    ans = (ans + (long long)prod * f[n][K - i] % mod * power(n, i)) % mod;
    prod = (long long)prod * i % mod;
  }
  ans = (mod + las - (long long)ans * power(power(n, mod - 2), K) % mod) % mod;
  cout << ans << endl;
  return 0;
}
