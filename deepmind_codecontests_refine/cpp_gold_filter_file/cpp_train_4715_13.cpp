#include <bits/stdc++.h>
const int N = 1e3 + 10;
inline int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return f ? -x : x;
}
int a[N], b[N], A[N], B[N], x[N], y[N];
std::bitset<N * N> f[N];
int main() {
  f[0][0] = 1;
  for (int T = read(); T; --T) {
    int n = read(), sa = 0, ua = 0;
    for (int i = 1; i <= n; ++i) a[i] = read(), sa += a[i];
    int m = read(), sb = 0, ub = 0;
    for (int i = 1; i <= m; ++i) b[i] = read(), sb += b[i];
    if (n != m || sa & 1 || sb & 1) {
      puts("No");
      continue;
    }
    std::sort(a + 1, a + n + 1), std::sort(b + 1, b + m + 1), sa >>= 1,
        sb >>= 1;
    for (int i = 1; i <= n; ++i) f[i] = f[i - 1] | (f[i - 1] << a[i]);
    if (!f[n][sa]) {
      puts("No");
      continue;
    }
    for (int i = n; i >= 1; --i)
      if (sa >= a[i] && f[i - 1][sa - a[i]])
        A[i] = 1, sa -= a[i], ++ua;
      else
        A[i] = 0;
    for (int i = 1; i <= m; ++i) f[i] = f[i - 1] | (f[i - 1] << b[i]);
    if (!f[m][sb]) {
      puts("No");
      continue;
    }
    for (int i = m; i >= 1; --i)
      if (sb >= b[i] && f[i - 1][sb - b[i]])
        B[i] = 1, sb -= b[i], ++ub;
      else
        B[i] = 0;
    if (ua > ub)
      for (int i = 1; i <= m; ++i) B[i] ^= 1;
    int p1 = 0, p2 = 1;
    for (int i = n; i >= 1; --i)
      if (A[i]) x[p1 * 2 + 1] = a[i], ++p1;
    for (int i = n; i >= 1; --i)
      if (!A[i]) x[p1 * 2 + 1] = -a[i], ++p1;
    for (int i = 1; i <= m; ++i)
      if (B[i]) y[p2 * 2] = b[i], ++p2;
    for (int i = 1; i <= m; ++i)
      if (!B[i]) y[p2 * 2] = -b[i], ++p2;
    int _x = 0, _y = 0;
    puts("Yes");
    for (int i = 1; i <= n + m; ++i) {
      _x += x[i], _y += y[i];
      printf("%d %d\n", _x, _y);
    }
  }
  return 0;
}
