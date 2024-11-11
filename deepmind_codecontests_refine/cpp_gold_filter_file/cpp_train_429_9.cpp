#include <bits/stdc++.h>
using namespace std;
const int Max_N = 3e3;
const long long Mod = 998244353;
int n, c, a[Max_N + 5], cnt[Max_N + 5], P[Max_N + 5], Ans[Max_N + 5],
    Inv[Max_N + 5], w[Max_N + 5][Max_N + 5], h[2][Max_N + 5][1 << 11],
    f[Max_N + 5][Max_N + 5];
inline void Add(int &x, int y) {
  x += y;
  x < Mod ?: x -= Mod;
}
inline int Read() {
  int num = 0;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar())
    ;
  for (; ch >= '0' && ch <= '9'; num = num * 10 + ch - '0', ch = getchar())
    ;
  return num;
}
inline void Print(int x) {
  if (x >= 10) Print(x / 10);
  putchar(x % 10 + '0');
}
inline long long Mul(int x, int y) {
  long long ans = 1;
  for (; y; y >>= 1, x = 1ll * x * x % Mod)
    if (y & 1) ans = ans * x % Mod;
  return ans;
}
int main() {
  n = Read(), c = Read();
  for (int i = 1; i <= n; i++) a[i] = Read();
  if (c > 11) {
    P[0] = 1;
    for (int i = 1; i <= n; i++) P[i] = P[i - 1] * 2 % Mod;
    for (int i = 1; i <= n; i++) Inv[i] = Mul((P[i] + Mod - 1) % Mod, Mod - 2);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= c; j++) cnt[j] = 0;
      long long tot = 1;
      for (int j = i, num = c; j <= n; j++) {
        if (cnt[a[j]] == 0)
          --num;
        else
          tot = tot * Inv[cnt[a[j]]] % Mod * (P[cnt[a[j]] + 1] - 1 + Mod) % Mod;
        ++cnt[a[j]];
        if (num == 0) w[i][j] = tot * Inv[cnt[a[j]]] % Mod;
      }
    }
    f[0][0] = 1;
    for (int i = 0; i < n; i++)
      for (int j = 0; j <= i / c; j++)
        if (f[i][j])
          for (int k = i + 1; k <= n; k++)
            if (w[i + 1][k])
              Add(f[k][j + 1], 1ll * f[i][j] * w[i + 1][k] % Mod);
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= n; j++) Add(Ans[i], 1ll * f[j][i] * P[n - j] % Mod);
    Add(Ans[0], Mod - 1);
    for (int i = 0; i < n; i++) Add(Ans[i], Mod - Ans[i + 1]);
    for (int i = 0; i <= n; i++) Print(Ans[i]), putchar(' ');
    puts("");
  } else {
    h[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= i / c; j++)
        for (int k = 0; k < 1 << c; k++) h[i & 1][j][k] = h[(i - 1) & 1][j][k];
      for (int j = 0; j <= i / c; j++)
        for (int k = 0; k + 1 < 1 << c; k++)
          if (((1 << a[i] - 1) | k) == (1 << c) - 1)
            Add(h[i & 1][j + 1][0], h[(i - 1) & 1][j][k]);
          else
            Add(h[i & 1][j][k | (1 << a[i] - 1)], h[(i - 1) & 1][j][k]);
    }
    for (int i = 0; i <= n; i++) {
      int ans = 0;
      for (int j = 0; j < 1 << c; j++) Add(ans, h[n & 1][i][j]);
      Print((ans - (i == 0) + Mod) % Mod);
      putchar(' ');
    }
    puts("");
  }
  return 0;
}
