#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1073741824")
#pragma warning(disable : 4996)
using namespace std;
const int N = 410, D = 26;
char s[N][N], t[N][N];
bitset<N> ans[N], g[D][N];
int main() {
  int n, m, r, c;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf(" %s", s[i]);
  }
  scanf("%d%d", &r, &c);
  for (int i = 0; i < r; i++) scanf(" %s", t[i]);
  for (int i = 0; i < n; i++) ans[i].set();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < D; k++) {
        if (s[i][j] == k + 'a') g[k][i][j] = 1;
      }
    }
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      char a = t[i][j];
      if (a == '?') continue;
      a -= 'a';
      for (int k = 0; k < n; k++) {
        int h = (k + i) % n;
        ans[k] &= ((g[a][h] >> j) | (g[a][h] << (m - j)));
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) printf("%d", (int)ans[i][j]);
    printf("\n");
  }
  return 0;
}
