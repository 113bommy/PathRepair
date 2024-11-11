#include <bits/stdc++.h>
using namespace std;
const int Maxb = 17, Maxs = 1 << 17, mod = 1e9 + 7, INV2 = (mod + 1) >> 1;
inline int read() {
  char c;
  int rec = 0;
  while ((c = getchar()) < '0' || c > '9')
    ;
  while (c >= '0' && c <= '9') rec = rec * 10 + c - '0', c = getchar();
  return rec;
}
int n, a[Maxs + 5], fib[Maxs + 5];
int sz[Maxs + 5], f[Maxb + 1][Maxs + 5], g[Maxb + 1][Maxs + 5];
inline void Fmt_Or(int *x, int n, int f) {
  for (int i = 0; i < n; ++i) {
    for (int T = 0; T < (1 << n); ++T)
      if (T & (1 << i))
        (x[T] += (f == 1) ? x[T ^ (1 << i)] : mod - x[T ^ (1 << i)]) %= mod;
  }
  return;
}
inline void Fmt_And(int *x, int n, int f) {
  for (int i = 0; i < n; ++i) {
    for (int T = (1 << n) - 1; ~T; --T) {
      if ((T & (1 << i)) == 0)
        (x[T] += (f == 1) ? x[T ^ (1 << i)] : mod - x[T ^ (1 << i)]) %= mod;
    }
  }
  return;
}
int s[Maxs + 5];
inline void Fwt(int *x, int N, int f) {
  for (int s = 2; s <= N; s <<= 1) {
    int u, t;
    for (int k = 0; k < N; k += s) {
      for (int j = 0; j < (s >> 1); ++j) {
        u = x[k + j];
        t = x[k + j + (s >> 1)];
        if (f == 1)
          x[k + j] = (u + t) % mod, x[k + j + (s >> 1)] = (u - t + mod) % mod;
        else
          x[k + j] = 1ll * (u + t) * INV2 % mod,
                x[k + j + (s >> 1)] = 1ll * (u - t + mod) * INV2 % mod;
      }
    }
  }
  return;
}
int ans1[Maxs + 5], ans2[Maxs + 5], ans[Maxs + 5];
int main() {
  n = read();
  fib[1] = 1;
  for (int T = 2; T < Maxs; ++T) fib[T] = (fib[T - 1] + fib[T - 2]) % mod;
  for (int T = 1; T < Maxs; ++T) sz[T] = sz[T - (T & -T)] + 1;
  for (int i = 1; i <= n; ++i) a[read()]++;
  for (int T = 0; T < Maxs; ++T)
    if (a[T]) f[sz[T]][T] = a[T];
  for (int i = 0; i < Maxb; ++i) Fmt_Or(f[i], Maxb, 1);
  for (int i = 0; i < Maxb; ++i) {
    for (int j = 0; j <= i; ++j) {
      for (int T = 0; T < Maxs; ++T) {
        (g[i][T] += 1ll * f[j][T] * f[i - j][T] % mod) %= mod;
      }
    }
    Fmt_Or(g[i], Maxb, -1);
    for (int T = 0; T < Maxs; ++T)
      if (sz[T] != i) g[i][T] = 0;
  }
  for (int T = 0; T < Maxs; ++T) ans1[T] = g[sz[T]][T];
  memcpy(s, a, sizeof(s));
  Fwt(s, Maxs, 1);
  for (int T = 0; T < Maxs; ++T) s[T] = 1ll * s[T] * s[T] % mod;
  Fwt(s, Maxs, -1);
  for (int T = 0; T < Maxs; ++T) ans2[T] = s[T];
  for (int T = 0; T < Maxs; ++T) {
    ans1[T] = 1ll * ans1[T] * fib[T] % mod;
    a[T] = 1ll * a[T] * fib[T] % mod;
    ans2[T] = 1ll * ans2[T] * fib[T] % mod;
  }
  Fmt_And(ans1, Maxb, 1);
  Fmt_And(a, Maxb, 1);
  Fmt_And(ans2, Maxb, 1);
  for (int T = 0; T < Maxs; ++T) {
    ans[T] = 1ll * ans1[T] * ans2[T] % mod * a[T] % mod;
  }
  Fmt_And(ans, Maxb, -1);
  int Ans = 0;
  for (int i = 0; i < Maxb; ++i) Ans = (Ans + ans[1 << i]) % mod;
  cout << Ans;
  return 0;
}
