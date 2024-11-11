#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void in(T &x) {
  x = 0;
  char c = getchar();
  bool f = 0;
  while (!isdigit(c)) f |= (c == '-'), c = getchar();
  while (isdigit(c)) x = x * 10 + (c ^ '0'), c = getchar();
  f ? x = -x : 0;
}
template <class T>
inline void out(T x, const char c = '\n') {
  static short st[30];
  short m = 0;
  if (x < 0) putchar('-'), x = -x;
  do st[++m] = x % 10, x /= 10;
  while (x);
  while (m) putchar(st[m--] | '0');
  putchar(c);
}
template <class T, class... Args>
inline void in(T &x, Args &...args) {
  in(x);
  in(args...);
}
template <class T, class... Args>
inline void out(const T &x, const Args &...args) {
  out(x, ' ');
  out(args...);
}
template <class T>
inline void prt(T a[], int n) {
  for (register int i = 0; i < n; ++i) out(a[i], i == n - 1 ? '\n' : ' ');
}
template <class T>
inline void clr(T a[], int n) {
  memset(a, 0, sizeof(T) * n);
}
template <class T>
inline void clr(T *a, T *b) {
  memset(a, 0, sizeof(T) * (b - a));
}
template <class T>
inline bool ckmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
inline bool ckmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
namespace i207M {
char S[200005], T[200005];
int n, m;
int nxt[200005], buk[200005];
signed main() {
  scanf("%s%s", S + 1, T + 1);
  n = strlen(S + 1), m = strlen(T + 1);
  nxt[0] = -1;
  for (register int i = 2, j = 0; i <= m; ++i) {
    while (j != -1 && T[j + 1] != T[i]) j = nxt[j];
    nxt[i] = ++j;
    if (nxt[i]) ++buk[i - nxt[i]];
  }
  for (register int i = 1; i <= m; ++i) buk[i] += buk[i - 1];
  T[m + 1] = '#', memcpy(T + m + 2, S + 1, n);
  int p = 1;
  long long ans = (long long)n * m;
  for (register int i = 2; i <= n + m + 1; ++i) {
    for (nxt[i] = max(0, min(p + nxt[p] - i, nxt[i - p + 1]));
         T[nxt[i] + 1] == T[i + nxt[i]]; ++nxt[i])
      ;
    if (i + nxt[i] > p + nxt[p]) p = i;
    if (i > m + 2) ans -= buk[nxt[i]];
  }
  out(ans);
  return 0;
}
}  // namespace i207M
signed main() {
  i207M::main();
  return 0;
}
