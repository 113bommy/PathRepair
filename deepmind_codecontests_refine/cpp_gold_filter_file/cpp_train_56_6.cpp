#include <bits/stdc++.h>
int n, m, r, c;
char tab[(410)][(410)], pat[(410)][(410)];
std::bitset<(410)> res[(410)];
std::bitset<(410)> g[(26)][(410)];
std::bitset<(410)> shiftRight(const std::bitset<(410)> &b, int shift, int len) {
  return (b >> shift) | (b << (len - shift));
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", tab + i);
    for (int j = 0; j < m; ++j) {
      g[tab[i][j] - 'a'][i][j] = true;
    }
    res[i] = ~res[i];
  }
  scanf("%d%d", &r, &c);
  for (int i = 0; i < r; ++i) {
    scanf("%s", pat + i);
    for (int j = 0; j < c; ++j) {
      if (pat[i][j] == '?') continue;
      int ch = pat[i][j] - 'a';
      for (int x = 0; x < n; ++x) {
        res[(x - i + n) % n] &= shiftRight(g[ch][x], j % m, m);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      putchar(res[i][j] ? '1' : '0');
    }
    putchar('\n');
  }
  return 0;
}
