#include <bits/stdc++.h>
using namespace std;
int vis[30][30], into[30], w[30];
char s[105][105];
int main() {
  int n, i, judge, j, l1, l2, k;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%s", s[i]);
  memset(vis, 0, sizeof(vis));
  memset(into, 0, sizeof(into));
  memset(w, 0, sizeof(w));
  judge = 1;
  for (i = 2; i <= n; i++) {
    l1 = strlen(s[i - 1]);
    l2 = strlen(s[i]);
    j = 0;
    while (j < l1 && j < l2 && s[i - 1][j] == s[i][j]) j++;
    if (j >= l1) continue;
    if (j >= l2) {
      judge = 0;
      break;
    }
    vis[s[i - 1][j] - 'a' + 1][s[i][j] - 'a' + 1] = 1;
  }
  for (i = 1; i <= 26; i++)
    for (j = 1; j <= 26; j++)
      if (vis[i][j] && vis[j][i])
        judge = 0;
      else if (vis[i][j])
        into[j]++;
  for (i = 1; i <= 26; i++) {
    if (judge == 0) break;
    for (j = 1; i <= 26; j++)
      if (into[j] == 0) {
        w[i] = j;
        break;
      }
    if (w[i] == 0) {
      judge = 0;
      break;
    }
    into[j] = -1;
    for (k = 1; k <= 26; k++)
      if (vis[j][k]) into[k]--;
  }
  if (judge == 0) {
    printf("Impossible\n");
    return 0;
  }
  for (i = 1; i <= 26; i++) printf("%c", w[i] - 1 + 'a');
  printf("\n");
  return 0;
}
