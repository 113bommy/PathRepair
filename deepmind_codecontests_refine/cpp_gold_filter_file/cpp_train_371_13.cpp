#include <bits/stdc++.h>
using namespace std;
int a[1550];
int ans[1550][30];
char s[1550];
int n;
int pre[1550][30];
int main() {
  scanf("%d", &n);
  scanf("%s", s);
  for (int i = 1; i <= n; ++i) {
    a[i] = s[i - 1] - 'a';
    for (int j = 0; j < 26; ++j) pre[i][j] = pre[i - 1][j];
    ++pre[i][a[i]];
  }
  for (int i = 1; i <= n; ++i)
    for (int j = i; j <= n; ++j) {
      for (int col = 0; col < 26; ++col) {
        int ned = (j - i + 1) - (pre[j][col] - pre[i - 1][col]);
        ans[ned][col] = max(ans[ned][col], j - i + 1);
      }
    }
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < 26; ++j) ans[i][j] = max(ans[i][j], ans[i - 1][j]);
  int q;
  scanf("%d", &q);
  char op[5];
  int u, v;
  while (q--) {
    scanf("%d%s", &u, op);
    v = *op - 'a';
    printf("%d\n", ans[u][v]);
  }
  return 0;
}
