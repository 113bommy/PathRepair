#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int w = 1, s = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    s = s * 10 + ch - '0';
    ch = getchar();
  }
  return w * s;
}
int T, mod, I[100100], g[505][505], f[505], fac[505];
inline int mns(int a, int b) {
  a -= b;
  return a < 0 ? a + mod : a;
}
inline int pls(int a, int b) {
  a += b;
  return a >= mod ? a - mod : a;
}
inline void Solve() {
  fac[0] = 1;
  for (register int i = 1; i <= 300; ++i) fac[i] = 1ll * fac[i - 1] * i % mod;
  I[1] = 1;
  for (register int i = 2; i <= 300; ++i) {
    I[i] = fac[i];
    for (register int j = 1; j <= i - 1; ++j) {
      I[i] = mns(I[i], 1ll * fac[i - j] * I[j] % mod);
    }
  }
  g[0][0] = 1;
  for (register int i = 0; i <= 300; ++i) {
    for (register int j = 0; j <= i; ++j) {
      for (register int k = 1; k <= 300; ++k) {
        if (i + k <= 300) {
          g[i + k][j + 1] = pls(g[i + k][j + 1], 1ll * g[i][j] * fac[k] % mod);
        }
      }
    }
  }
  f[1] = 1;
  for (register int i = 2; i <= 300; ++i) {
    f[i] = fac[i];
    for (register int j = 1; j <= i - 1; ++j) {
      f[i] = mns(f[i], 2ll * I[j] * fac[i - j] % mod);
    }
    for (register int j = 3; j <= i - 1; ++j) {
      f[i] = mns(f[i], 1ll * g[i][j] * f[j] % mod);
    }
  }
}
int main() {
  T = read(), mod = read();
  Solve();
  f[2] = 2;
  while (T--) {
    int x = read();
    cout << f[x] << "\n";
  }
  return 0;
}
