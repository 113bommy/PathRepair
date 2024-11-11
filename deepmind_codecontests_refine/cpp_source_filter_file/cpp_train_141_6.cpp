#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > g;
vector<vector<int> > g1;
int n;
int ver[1003];
int coun;
int coun2[1003];
bool flag[1003];
int coun3;
void dfs(int x) {
  int i;
  coun2[coun]++;
  ver[x] = coun;
  flag[x] = true;
  for (i = 0; i < g[x].size(); i++)
    if (!flag[g[x][i]]) dfs(g[x][i]);
}
void dfs2(int x) {
  coun3++;
  if ((int)g1[x].size() > 0) dfs2(g1[x][0]);
}
int main() {
  int i, j;
  int x, y;
  scanf("%d %d", &n, &x);
  g1.resize(n);
  g.resize(n);
  x--;
  for (i = 0; i < n; i++) {
    scanf("%d", &y);
    if (y > 0 && y != i) {
      y--;
      g[i].push_back(y);
      g[y].push_back(i);
      g1[i].push_back(y);
    }
  }
  for (i = 0; i < n; i++)
    if (!flag[i]) {
      dfs(i);
      coun++;
    }
  dfs2(x);
  int dp[1003];
  for (i = 1; i < 1000; i++) dp[i] = 0;
  dp[0] = 1;
  for (i = 0; i < coun; i++) {
    if (ver[x] != i)
      for (j = 999; j > coun2[i] - 1; j--) dp[j] += dp[j - coun2[i]];
  }
  for (i = 0; i < 1000; i++)
    if (dp[i] > 0) printf("%d\n", i + coun3);
  return 0;
}
