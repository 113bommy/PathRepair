#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T& n) {
  char ch;
  int sign = 1;
  while (!isdigit(ch = getchar()))
    if (ch == '-') sign = -1;
  n = ch - '0';
  while (isdigit(ch = getchar())) n = n * 10 + ch - '0';
  n *= sign;
}
const int INF = 1e9 + 7;
const int N = 151111;
const int MOD = INF;
int n, first;
int a[N], b[N], c[N], d[N], fib[N];
int t[25][N], h[25][N], p[N], b1[N], c1[N];
void upd(int& first, int second) {
  first += second;
  if (first >= MOD) first -= MOD;
}
int calc(int first) { return first ? calc(first - (first & -first)) + 1 : 0; }
int rev(int first) {
  int ret = 0;
  for (int i = (0); i <= (16); ++i) ret |= (((first >> i) & 1) ^ 1) * (1 << i);
  return ret;
}
void fmt(int* f, int sign) {
  for (int i = (0); i <= (16); ++i)
    for (int s = (0); s <= ((1 << 17) - 1); ++s)
      if ((s & (1 << i)) == 0) {
        if (sign == 1)
          upd(f[s | (1 << i)], f[s]);
        else
          f[s | (1 << i)] = (f[s | (1 << i)] - f[s] + MOD) % MOD;
      }
}
void fwt(int* f) {
  for (int i = (0); i <= (16); ++i)
    for (int s = (0); s <= ((1 << 17) - 1); ++s)
      if ((s & (1 << i)) == 0) {
        int l = f[s], r = f[s | (1 << i)];
        f[s] = (l + r) % MOD, f[s | (1 << i)] = (l - r + MOD) % MOD;
      }
}
long long mut(long long a, long long b) {
  long long second = 1, t = a;
  for (; b; b >>= 1, t = t * t % MOD)
    if (b & 1) second = second * t % MOD;
  return second;
}
int main() {
  read(n);
  fib[0] = 0, fib[1] = 1;
  for (int i = (2); i <= (N - 1); ++i) fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
  for (int i = (1); i <= (n); ++i) {
    read(first);
    t[calc(first)][first]++, b1[first]++, p[first]++;
  }
  for (int i = (0); i <= (17); ++i) fmt(t[i], 1);
  for (int i = (0); i <= ((1 << 17) - 1); ++i)
    for (int j = (0); j <= (17); ++j)
      for (int k = (0); k <= (17); ++k)
        if (j + k <= 17) upd(h[j + k][i], (long long)t[j][i] * t[k][i] % MOD);
  for (int i = (0); i <= (17); ++i) fmt(h[i], -1);
  for (int i = (0); i <= ((1 << 17) - 1); ++i)
    a[rev(i)] = (long long)h[calc(i)][i] * fib[i] % MOD;
  for (int i = (0); i <= ((1 << 17) - 1); ++i)
    b1[i] = (long long)b1[i] * fib[i] % MOD;
  for (int i = (0); i <= ((1 << 17) - 1); ++i) b[rev(i)] = b1[i];
  fwt(p);
  for (int i = (0); i <= ((1 << 17) - 1); ++i)
    c1[i] = (long long)p[i] * p[i] % MOD;
  fwt(c1);
  int po2 = mut(2, MOD - 2);
  for (int i = (0); i <= ((1 << 17) - 1); ++i)
    for (int j = (1); j <= (17); ++j) c1[i] = (long long)c1[i] * po2 % MOD;
  for (int i = (0); i <= ((1 << 17) - 1); ++i)
    c1[i] = (long long)c1[i] * fib[i] % MOD;
  for (int i = (0); i <= ((1 << 17) - 1); ++i) c[rev(i)] = c1[i];
  fmt(a, 1), fmt(b, 1), fmt(c, 1);
  for (int i = (0); i <= ((1 << 17) - 1); ++i)
    d[i] = (long long)a[i] * b[i] % MOD * c[i] % MOD;
  fmt(d, -1);
  int ans = 0;
  for (int i = (0); i <= (16); ++i) upd(ans, d[(1 << 17) - 1 - (1 << i)]);
  printf("%d\n", ans);
  return 0;
}
