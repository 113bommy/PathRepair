#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5, Mod = 1e9 + 7;
char buf[1 << 12], *pp1 = buf, *pp2 = buf, nc;
int ny;
inline char gc() {
  return pp1 == pp2 &&
                 (pp2 = (pp1 = buf) + fread(buf, 1, 1 << 12, stdin), pp1 == pp2)
             ? EOF
             : *pp1++;
}
inline int read() {
  int x = 0;
  for (ny = 1; nc = gc(), (nc < 48 || nc > 57) && nc != EOF;)
    if (nc == 45) ny = -1;
  if (nc < 0) return nc;
  for (x = nc - 48; nc = gc(), 47 < nc && nc < 58 && nc != EOF;
       x = (x << 3) + (x << 1) + (nc ^ 48))
    ;
  return x * ny;
}
int n, a[MAXN], b[MAXN], c[MAXN], ans[MAXN], Fpow[MAXN];
inline void Fwt(int* F, int len) {
  for (int i = 1; i < len; i *= 10)
    for (int j = len - 1; j >= 0; j--)
      if (j / i % 10) F[j - i] = (F[j - i] + F[j]) % Mod;
}
inline void iFwt(int* F, int len) {
  for (int i = 1; i < len; i *= 10)
    for (int j = 0; j <= len - 1; j++)
      if (j / i % 10) F[j - i] = (F[j - i] - F[j] + Mod) % Mod;
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[read()]++;
  for (int i = 0; i <= 1e6 - 1; i++)
    b[i] = 1ll * a[i] * i % Mod, c[i] = 1ll * a[i] * i % Mod * i % Mod;
  Fpow[0] = 1;
  for (int i = 1; i <= 1e6 - 1; i++) Fpow[i] = (Fpow[i - 1] << 1) % Mod;
  Fwt(a, 1e6), Fwt(b, 1e6), Fwt(c, 1e6);
  for (int i = 0; i <= 1e6 - 1; i++) {
    if (a[i] >= 2)
      ans[i] = 1ll * Fpow[a[i] - 2] * (1ll * b[i] * b[i] % Mod + c[i]) % Mod;
    else if (a[i] == 1)
      ans[i] = c[i];
    else
      ans[i] = 0;
  }
  iFwt(ans, 1e6);
  long long Ans = 0;
  for (int i = 0; i <= 1e6 - 1; i++) Ans ^= 1ll * ans[i] * i;
  cout << Ans << '\n';
  return 0;
}
