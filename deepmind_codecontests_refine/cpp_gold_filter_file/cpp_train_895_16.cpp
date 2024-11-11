#include <bits/stdc++.h>
std::bitset<1 << 12> f[100005];
int a[15][100005];
inline int read() {
  register int x = 0, f = 1;
  register char s = getchar();
  while (s > '9' || s < '0') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  return x * f;
}
int main() {
  int n = read(), m = read(), Q = read(), num = m - 1;
  for (register int i = 0; i < m; ++i) {
    for (register int j = 1; j <= n; ++j) {
      a[i][j] = read();
    }
  }
  for (register int mask = 1; mask < (1 << m); ++mask) {
    for (register int i = 0; i < m; ++i) {
      if (mask >> i & 1) f[i].set(mask);
    }
  }
  while (Q--) {
    int op = read(), x = read() - 1, y = read();
    if (op == 1)
      f[++num] = f[x] | f[y - 1];
    else if (op == 2)
      f[++num] = f[x] & f[y - 1];
    else {
      std::vector<std::pair<int, int> > t;
      for (register int i = 0; i < m; ++i)
        t.push_back(std::make_pair(-a[i][y], i));
      std::sort(t.begin(), t.end());
      int mask = 0;
      for (register int i = 0; i < m; ++i) {
        mask |= 1 << t[i].second;
        if (f[x][mask]) {
          printf("%d\n", -t[i].first);
          break;
        }
      }
    }
  }
  return 0;
}
