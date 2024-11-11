#include <bits/stdc++.h>
using namespace std;
const int maxn = 3000 + 5;
int res[maxn];
char ch[maxn][maxn];
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++) scanf("%s", ch[i]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (ch[i][j] == 'U') {
        if (i % 2) res[j]++;
      } else if (ch[i][j] == 'L') {
        if (j - i >= 0) res[j - i]++;
      } else if (ch[i][j] == 'R') {
        if (j + i < m) res[j + i]++;
      }
    }
  for (int i = 0; i < m; i++) {
    printf("%d", res[i]);
    if (i != m - 1)
      printf(" ");
    else
      printf("\n");
  }
  return 0;
}
