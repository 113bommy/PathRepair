#include <bits/stdc++.h>
using namespace std;
const char IO_MODE = 0;
inline long long ReadInt() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void WriteInt(long long x) {
  char CH[20];
  if (x < 0) putchar('-');
  x = -x;
  int Num = 0;
  if (!x) {
    putchar('0');
    return;
  }
  while (x > 0) CH[++Num] = x % 10, x /= 10;
  while (Num) putchar(CH[Num--] + 48);
}
inline void out(int x) {
  if (IO_MODE & 1)
    WriteInt(x);
  else
    printf("%i", x);
}
template <typename... Args>
inline void out(int x, Args... args) {
  out(x);
  putc(' ', stdout);
  out(args...);
}
inline void in(int &x) {
  if (IO_MODE & 2)
    x = ReadInt();
  else
    scanf("%i", &x);
}
template <typename... Args>
inline void in(int &x, Args &...args) {
  in(x);
  in(args...);
}
inline void outll(long long x) {
  if (IO_MODE & 1)
    WriteInt(x);
  else
    printf("%I64d", x);
}
template <typename... Args>
inline void outll(long long x, Args... args) {
  outll(x);
  putc(' ', stdout);
  outll(args...);
}
inline void inll(long long &x) {
  if (IO_MODE & 2)
    x = ReadInt();
  else
    scanf("%I64d", &x);
}
template <typename... Args>
inline void inll(long long &x, Args &...args) {
  inll(x);
  inll(args...);
}
int aa, bb, cc, dd, ee, ff, gg, hh, ii, jj, kk, mm, nn, oo, pp, qq, rr, ss, tt,
    uu, vv, ww, xx, yy, zz;
int tc;
int n, m, k;
int C[5000][5000];
void init_nCr() {
  for (int n = 0; n < 5000; n++) C[n][0] = C[n][n] = 1;
  for (int n = 2; n < 5000; n++)
    for (int r = 1; r < n; r++)
      C[n][r] = (C[n - 1][r - 1] + C[n - 1][r]) % 1000000007;
}
int main() {
  in(n, m, k);
  init_nCr();
  long long a = C[n - 1][2 * k];
  long long b = C[m - 1][2 * k];
  out((a * b) % 1000000007);
  putc('\n', stdout);
}
