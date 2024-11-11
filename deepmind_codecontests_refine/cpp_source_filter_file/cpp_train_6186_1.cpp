#include <bits/stdc++.h>
using namespace std;
int n, m;
int size;
char s[2010][2010];
int dp[2010][2010];
int get_sum(int lx, int ly, int ux, int uy) {
  if (lx > ux || ly > uy) return 0;
  return dp[ux][uy] - dp[ux][ly - 1] - dp[lx - 1][uy] + dp[lx - 1][ly - 1];
}
int get_border(int lx, int ly, int ux, int uy) {
  return get_sum(lx, ly, ux, uy) - get_sum(lx + 1, ly + 1, ux - 1, uy - 1);
}
void output(int lx, int ly) {
  int i;
  for (i = lx; i <= lx + size; i++) {
    s[i][ly] = (s[i][ly] == 'w') ? 'w' : '+';
    s[i][ly + size] = (s[i][ly + size] == 'w') ? 'w' : '+';
  }
  for (i = ly; i <= ly + size; i++) {
    s[lx][i] = (s[lx][i] == 'w') ? 'w' : '+';
    s[lx + size][i] = (s[lx + size][i] == 'w') ? 'w' : '+';
  }
  for (i = 0; i < n; i++) printf("%s\n", s[i]);
}
void solve() {
  int i, j;
  int lx, ly, ux, uy;
  lx = 2010;
  ly = 2010;
  ux = -1;
  uy = -1;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      if (s[i][j] == 'w') {
        lx = min(lx, i);
        ly = min(ly, j);
        ux = max(ux, i);
        uy = min(uy, j);
      }
  size = max(ux - lx, uy - ly);
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      dp[i + 1][j + 1] =
          (s[i][j] == 'w') + dp[i][j + 1] + dp[i + 1][j] - dp[i][j];
  for (i = 1; i + size <= n; i++)
    for (j = 1; j + size <= m; j++) {
      if (dp[n][m] == get_border(i, j, i + size, j + size)) {
        output(i - 1, j - 1);
        return;
      }
    }
  printf("-1\n");
}
void input() {
  int i, j;
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++) scanf("%s", &s[i]);
  solve();
}
int main() {
  input();
  fclose(stdin);
  fclose(stdout);
  return 0;
}
