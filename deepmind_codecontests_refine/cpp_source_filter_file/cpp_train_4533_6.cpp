#include <bits/stdc++.h>
using namespace std;
const int N = 21;
const int M = 1010101;
const int MOD = 1e9 + 7;
const int INV2 = (MOD + 1) >> 1;
inline char get(void) {
  static char buf[100000], *S = buf, *T = buf;
  if (S == T) {
    T = (S = buf) + fread(buf, 1, 100000, stdin);
    if (S == T) return EOF;
  }
  return *S++;
}
template <typename T>
inline void read(T& x) {
  static char c;
  x = 0;
  int sgn = 0;
  for (c = get(); c < '0' || c > '9'; c = get())
    if (c == '-') sgn = 1;
  for (; c >= '0' && c <= '9'; c = get()) x = x * 10 + c - '0';
  if (sgn) x = -x;
}
int a[M], b[M];
int c[M];
int n, m, x, lim, ans;
inline int BitCount(int x) {
  int cnt = 0;
  for (; x; x -= (x & -x)) cnt++;
  return cnt;
}
void FWT(int* a, int f, int n) {
  static int x, y;
  for (int i = 1; i < n; i <<= 1)
    for (int j = 0; j < n; j += (i << 1))
      for (int k = 0; k < i; k++) {
        x = a[j + k];
        y = a[j + k + i];
        a[j + k] = (x + y) % MOD;
        a[j + k + i] = (x - y + MOD) % MOD;
        if (f == -1) {
          a[j + k] = (long long)a[j + k] * INV2 % MOD;
          a[j + k + i] = (long long)a[j + k + i] * INV2 % MOD;
        }
      }
}
int main(void) {
  read(n);
  read(m);
  lim = 1 << n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      x = get() - '0';
      a[j] = a[j] << 1 | x;
    }
    get();
  }
  for (int i = 1; i <= m; i++) c[a[i]]++;
  for (int i = 0; i < lim; i++) {
    b[i] = min(BitCount(i), n - BitCount(i));
  }
  FWT(b, 1, lim);
  FWT(c, 1, lim);
  for (int i = 0; i < lim; i++) c[i] = (long long)c[i] * b[i] % MOD;
  FWT(c, -1, lim);
  ans = MOD;
  for (int i = 0; i < lim; i++) ans = min(ans, c[i]);
  cout << ans << endl;
  return 0;
}
