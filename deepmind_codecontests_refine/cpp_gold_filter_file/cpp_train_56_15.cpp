#include <bits/stdc++.h>
using namespace std;
char pattern[405][405], grid[405][405];
bitset<405> ans[405], possui[26][405];
int n, m;
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", grid[i]);
  int n2, m2;
  scanf("%d %d", &n2, &m2);
  for (int i = 0; i < n2; i++) scanf("%s", pattern[i]);
  for (int i = 0; i < n; i++)
    for (int c = 0; c < 26; c++) ans[i].set();
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) possui[grid[i][j] - 'a'][i][405 - 1 - j] = true;
  for (int i = 0; i < n2; i++) {
    for (int j = 0; j < m2; j++) {
      int c = pattern[i][j];
      if (c == '?') continue;
      for (int k = 0; k < n; k++)
        ans[k] &= (possui[c - 'a'][(k + i) % n] << j % m) |
                  (possui[c - 'a'][(k + i) % n] >> (m - j % m));
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) printf("%d", (int)ans[i][405 - 1 - j]);
    printf("\n");
  }
  return 0;
}
