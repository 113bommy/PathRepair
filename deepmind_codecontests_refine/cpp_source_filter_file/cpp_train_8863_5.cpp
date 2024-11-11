#include <bits/stdc++.h>
using namespace std;
int _max(int x, int y) { return x > y ? x : y; }
int _min(int x, int y) { return x < y ? x : y; }
const int mod = 998244353;
const int N = 2001;
int read() {
  int s = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * f;
}
void put(int x) {
  if (x >= 10) put(x / 10);
  putchar(x % 10 + '0');
}
int f[N * 2][N], jc[N];
int add(int x, int y) {
  x += y;
  return x >= mod ? x - mod : x;
}
int pow_mod(int a, int k) {
  int ans = 1;
  while (k) {
    if (k & 1) ans = (long long)ans * a % mod;
    a = (long long)a * a % mod, k /= 2;
  }
  return ans;
}
int main() {
  int n = read(), k = read(), L = read();
  f[0][0] = 1;
  for (int i = 1; i <= 2 * n; i++)
    for (int j = 0; j <= _min(i, n); j++) {
      f[i][j] = add((long long)f[i - 1][j + 1] * (j + 1) % mod,
                    j == 0 ? 0 : f[i - 1][j - 1]);
    }
  int ans = 0;
  jc[0] = 1;
  for (int i = 1; i <= n; i++) jc[i] = (long long)jc[i - 1] * i % mod;
  for (int i = 1; i <= 2 * n; i++)
    for (int j = k; j <= _min(2 * n - i, i); j++) {
      ans = add(ans, (long long)f[i][j] * f[2 * n - i][j] % mod * jc[j] % mod);
    }
  put((long long)ans * L % mod * pow_mod(2 * n + 1, mod - 2) % mod *
      pow_mod(f[2 * n][0], mod - 2) % mod);
  return 0;
}
