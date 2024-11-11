#include <bits/stdc++.h>
using namespace std;
const int __SIZE = 1 << 18;
char ibuf[__SIZE], *iS, *iT;
template <typename T>
inline void read(T &x) {
  char ch, t = 0;
  x = 0;
  while (!isdigit(ch = (iS == iT
                            ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin),
                               (iS == iT ? EOF : *iS++))
                            : *iS++)))
    t |= ch == '-';
  while (isdigit(ch))
    x = x * 10 + (ch ^ 48),
    ch = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin),
                      (iS == iT ? EOF : *iS++))
                   : *iS++);
  x = t ? -x : x;
}
inline int read_int() {
  int x;
  return read(x), x;
}
inline long long read_ll() {
  long long x;
  return read(x), x;
}
template <typename T>
inline void chkmin(T &a, T b) {
  a = a < b ? a : b;
}
template <typename T>
inline void chkmax(T &a, T b) {
  a = a > b ? a : b;
}
const int MAXN = 400010;
int c[4];
int d[4];
int ab[MAXN];
int bc[MAXN];
int cd[MAXN];
int main() {
  for (int i = 0; i < 4; i++) c[i] = read_int();
  int n = c[0] + c[1] + c[2] + c[3];
  if (n == 1) {
    puts("YES");
    for (int i = 0; i < 4; i++)
      if (c[i]) putchar(i | 48);
    puts("");
    return 0;
  }
  if (c[0] - c[1] > 1 || c[3] - c[2] > 1) return puts("NO"), 0;
  if (c[0] > c[1] && (c[2] || c[3])) return puts("NO"), 0;
  if (c[3] > c[2] && (c[1] || c[0])) return puts("NO"), 0;
  if (c[0] > c[1]) {
    puts("YES");
    for (int i = 1; i <= n; i++) printf("%d%c", i & 1 ? 0 : 1, " \n"[i == n]);
    return 0;
  }
  if (c[3] > c[2]) {
    puts("YES");
    for (int i = 1; i <= n; i++) printf("%d%c", i & 1 ? 3 : 2, " \n"[i == n]);
    return 0;
  }
  int nab = 0, nbc = 0, ncd = 0;
  c[1] -= c[0], c[2] -= c[3];
  while (c[0]--) ab[++nab] = 0, ab[++nab] = 1;
  while (c[3]--) cd[++ncd] = 2, cd[++ncd] = 3;
  if (abs(c[1] - c[2]) <= 1) {
    puts("YES");
    int mi = min(c[1], c[2]);
    if (c[1] == c[2] + 1) printf("1 ");
    for (int i = 1; i <= nab; i++) printf("%d ", ab[i]);
    while (mi--) printf("2 1 ");
    for (int i = 1; i <= ncd; i++) printf("%d ", cd[i]);
    if (c[1] + 1 == c[2]) printf("2 ");
    puts("");
  } else
    puts("NO");
  return 0;
}
