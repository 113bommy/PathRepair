#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int tab[5010][5010];
int com[100010][3], ex[2][5010];
int main(int argc, char const *argv[]) {
  memset(tab, 0, sizeof(tab));
  memset(ex, 0, sizeof(ex));
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < k; i++)
    scanf("%d%d%d", &com[i][0], &com[i][1], &com[i][2]);
  for (int i = k - 1; i >= 0; i--)
    if (ex[com[i][0]][com[i][1]] == 0) {
      ex[com[i][0]][com[i][1]] = 1;
    } else
      com[i][0] = -1;
  for (int i = 0; i < k; i++)
    if (com[i][0] != -1) {
      if (com[i][0] == 1)
        for (int j = 1; j <= m; j++) tab[com[i][1]][j] = com[i][2];
      else
        for (int j = 1; j <= n; j++) tab[j][com[i][1]] = com[i][2];
    }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) printf("%d ", tab[i][j]);
    printf("\n");
  }
  return 0;
}
