#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
inline long long Min(const long long &a, const long long &b) {
  return a < b ? a : b;
}
inline long long Max(const long long &a, const long long &b) {
  return a > b ? a : b;
}
inline char get(void) {
  static char buf[100000], *p1 = buf, *p2 = buf;
  if (p1 == p2) {
    p2 = (p1 = buf) + fread(buf, 1, 100000, stdin);
    if (p1 == p2) return EOF;
  }
  return *p1++;
}
inline void read(long long &x) {
  x = 0;
  static char c;
  for (; !(c >= '0' && c <= '9'); c = get())
    ;
  for (; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = get())
    ;
}
long long s[4][N], n, m, pre[4][N], ans;
int main(void) {
  read(n), read(m);
  long long w, c;
  for (int i = 1; i <= n; i++) {
    read(w), read(c);
    s[w][++*s[w]] = c;
  }
  for (int i = 1; i <= 3; i++) {
    sort(s[i] + 1, s[i] + 1 + *s[i], std::greater<long long>());
    for (int k = 1; k <= *s[i]; k++) pre[i][k] = pre[i][k - 1] + s[i][k];
  }
  for (int i = 0; i <= *s[3] && m >= 0; i++) {
    int L = 0, R = Min(m / 2, *s[2]), Mid = 0;
    while (L < R) {
      Mid = (L + R) >> 1;
      int m1 = Min(*s[1], m - Mid * 2);
      if (m1 + Mid * 2 < m - 1 || s[2][Mid] > s[1][m1] * 2)
        L = Mid + 1;
      else
        R = Mid;
    }
    for (int k = Max(0, Mid - 50); k <= Min(*s[2], Mid + 50); k++) {
      if (k * 2 > m) break;
      int m1 = Min(*s[1], m - k * 2);
      ans = Max(ans, pre[2][k] + pre[1][m1] + pre[3][i]);
    }
    m -= 3;
  }
  printf("%I64d\n", ans);
  return 0;
}
