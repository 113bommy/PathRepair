#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > g[110];
int seen[110][110];
int c[110];
int ans;
void dfs(int s, int end, int color) {
  if (s == end && c[color] == 0) {
    c[color] = 1;
    ans++;
    return;
  }
  for (int i = 0; i < (int)g[s].size(); i++) {
    if ((color == 0 || color == g[s][i].second) &&
        seen[s][g[s][i].first] == 0 && seen[g[s][i].first][s] == 0) {
      seen[s][g[s][i].first] = 1;
      seen[g[s][i].first][s] = 1;
      dfs(g[s][i].first, end, g[s][i].second);
      seen[s][g[s][i].first] = 0;
      seen[g[s][i].first][s] = 0;
    }
  }
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int temp1, temp2, temp3;
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &temp1, &temp2, &temp3);
    g[temp1].push_back(pair<int, int>(temp2, temp3));
    g[temp2].push_back(pair<int, int>(temp1, temp3));
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d %d", &temp1, &temp2);
    dfs(temp1, temp2, 0);
    printf("%d\n", ans);
    ans = 0;
    for (int i = 0; i < 110; i++)
      for (int j = 0; j < 110; j++) seen[i][j] = 0;
    for (int i = 0; i < 110; i++) c[i] = 0;
  }
  return 0;
}
