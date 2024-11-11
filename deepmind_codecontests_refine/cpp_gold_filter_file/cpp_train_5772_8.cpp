#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
inline void remax(T1& A, T2 B) {
  if (A < B) A = B;
}
template <class T1, class T2>
inline void remin(T1& A, T2 B) {
  if (A > B) A = B;
}
long long Gcd(long long a, long long b) {
  if (!a || !b) return a + b;
  while (a %= b ^= a ^= b ^= a)
    ;
  return b;
}
long long Power(long long base, unsigned long long power) {
  long long ret = 1;
  while (power) {
    if (power & 1) ret *= base;
    power >>= 1;
    base *= base;
  }
  return ret;
}
long long PowerMod(long long base, unsigned long long power, long long mod) {
  if (!power) return 1 % mod;
  if (power & 1) return (base * PowerMod(base, power - 1, mod)) % mod;
  return PowerMod((base * base) % mod, power >> 1, mod);
}
FILE* Input = stdin;
int mat[20000][10];
inline void run() {
  int ans[20000] = {};
  int cnt[10] = {};
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) scanf("%d", &mat[i][j]);
  while (k--) {
    int x, y;
    scanf("%d%d", &x, &y);
    --ans[--x];
    ++cnt[--y];
  }
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j)
      if (mat[j][i]) ans[j] += cnt[i];
  for (int i = 0; i < n; ++i) {
    if (i) putchar(' ');
    printf("%d", ans[i]);
  }
  puts("");
}
int main() {
  run();
  return 0;
}
