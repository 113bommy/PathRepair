#include <bits/stdc++.h>
using namespace std;
const int kMaxN = 110000;
int n, m, r, c;
bitset<440> ans[440];
bitset<440> G[26][440];
int main() {
  scanf("%d%d", &n, &m);
  char ch;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf(" %c", &ch);
      G[ch - 'a'][i][j] = 1;
    }
  }
  for (int i = 0; i < n; i++) ans[i] = ~ans[i];
  scanf("%d%d", &r, &c);
  for (int x = 0; x < r; x++) {
    for (int y = 0; y < c; y++) {
      scanf(" %c", &ch);
      if (ch == '?') continue;
      for (int i = 0; i < n; i++) {
        int ii = x % n, jj = y % m;
        ans[(i - ii + n) % n] &=
            ((G[ch - 'a'][i] >> (jj)) | (G[ch - 'a'][i] << ((m - jj))));
      }
    }
  }
  for (int i = 0; i < n; i++, puts(""))
    for (int j = 0; j < m; j++) printf("%d", (int)ans[i][j]);
  return 0;
}
