#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e4 + 5, Mod = 998244353;
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
int n, m;
const int R[16] = {0,   4,  8,   -1, 16,  -10, 4,  -12,
                   -48, 26, -44, 15, -16, -4,  -4, -1};
int A[16] = {0,    0,    0,     24,    4,      240,    204,     1316,
             2988, 6720, 26200, 50248, 174280, 436904, 1140888, 3436404};
int f[MAXN];
int main() {
  n = read();
  for (int i = (0); i <= (15); i++) f[i] = A[i];
  for (int i = (16); i <= (n); i++)
    for (int j = (0); j <= (15); j++)
      f[i] = (f[i] + 1ll * R[j] * f[i - j - 1]) % Mod;
  cout << (f[n] + Mod) % Mod << "\n";
  return 0;
}
