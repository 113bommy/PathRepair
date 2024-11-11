#include <bits/stdc++.h>
using namespace std;
const int inf = 2000000000;
static inline int Rint() {
  struct X {
    int dig[256];
    X() {
      for (int i = '0'; i <= '9'; ++i) dig[i] = 1;
      dig['-'] = 1;
    }
  };
  static X fuck;
  int s = 1, v = 0, c;
  for (; !fuck.dig[c = getchar()];)
    ;
  if (c == '-')
    s = 0;
  else if (fuck.dig[c])
    v = c ^ 48;
  for (; fuck.dig[c = getchar()]; v = v * 10 + (c ^ 48))
    ;
  return s ? v : -v;
}
template <typename T>
static inline void cmax(T& a, const T& b) {
  if (b > a) a = b;
}
template <typename T>
static inline void cmin(T& a, const T& b) {
  if (b < a) a = b;
}
char buff[1000005];
int solve(int maxr, int flag, int n) {
  int a = 1, b = maxr;
  while (a <= b) {
    const int mid = a + b >> 1;
    int l = 0, r = 0, lc = 1, rc = 1, x = 0;
    for (int i = 0; i < n; ++i) {
      if (flag == 0) {
        if (buff[i] == 'L')
          --x;
        else
          ++x;
      } else {
        if (buff[i] == 'L')
          ++x;
        else
          --x;
      }
      if (x >= mid) x = mid - 1;
      if (x == l)
        ++lc;
      else if (x < l)
        l = x, lc = 1;
      if (x == r)
        ++rc;
      else if (x > r)
        r = x, rc = 1;
    }
    int ok = 0;
    if (l < 0 || x == l && lc == 1) {
      ok = 1;
    }
    if (ok)
      a = mid + 1;
    else
      b = mid - 1;
  }
  return a;
}
int main() {
  gets(buff);
  const int n = strlen(buff);
  int l = 0, r = 0, lc = 1, rc = 1, x = 0;
  for (int i = 0; i < n; ++i) {
    if (buff[i] == 'L')
      --x;
    else
      ++x;
    if (x == l)
      ++lc;
    else if (x < l)
      l = x, lc = 1;
    if (x == r)
      ++rc;
    else if (x > r)
      r = x, rc = 1;
  }
  if (l < 0 || x == l && lc == 1) {
    puts("1");
    return 0;
  }
  if (r > 0 || x == r && rc == 1) {
    puts("1");
    return 0;
  }
  int ans = 0;
  ans += solve(r, 0, n);
  ans += solve(l, 1, n);
  printf("%d\n", ans);
  return 0;
}
