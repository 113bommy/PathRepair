#include <bits/stdc++.h>
inline int getint() {
  register char ch;
  while (!isdigit(ch = getchar()))
    ;
  register int x = ch ^ '0';
  while (isdigit(ch = getchar())) x = (((x << 2) + x) << 1) + (ch ^ '0');
  return x;
}
const int N = 100001;
int f[N], g[N];
int main() {
  const int L = getint(), n = getint(), p = getint(), t = getint();
  g[0] = -t;
  for (register int i = 1, j = 0; i <= n; i++) {
    const int l = getint(), r = getint();
    while (j < i && g[j] + t <= r) {
      if (f[j] + (r - std::max(l, g[j] + t)) / p > f[i] ||
          f[j] + (r - std::max(l, g[j] + t)) / p == f[i] &&
              r - (r - std::max(l, g[j] + t)) % p < g[i]) {
        f[i] = f[j] + (r - std::max(l, g[j] + t)) / p;
        g[i] = r - (r - std::max(l, g[j] + t)) % p;
      }
      j++;
    }
    j--;
    if (f[i - 1] >= f[i] || f[i - 1] == f[i] && g[i - 1] <= g[i]) {
      f[i] = f[i - 1];
      g[i] = g[i - 1];
    }
  }
  printf("%d\n", f[n]);
  return 0;
}
