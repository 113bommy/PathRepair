#include <bits/stdc++.h>
using namespace std;
int n, m;
char G[1003][1003];
pair<int, int> Q[1003 * 1003], w;
int pre[1003][1003] = {};
int post[1003][1003] = {};
int dist[1003][1003];
int p = 1, r = 1;
bool fin = false;
void is(int i, int j) {
  if (pre[i][j]) return;
  pre[i][j] = p++;
  if (i + 1 < n)
    if (G[i + 1][j] == (G[i][j] + 1) % 4) is(i + 1, j);
  if (j + 1 < m)
    if (G[i][j + 1] == (G[i][j] + 1) % 4) is(i, j + 1);
  if (i - 1 >= 0)
    if (G[i - 1][j] == (G[i][j] + 1) % 4) is(i - 1, j);
  if (j - 1 >= 0)
    if (G[i][j - 1] == (G[i][j] + 1) % 4) is(i, j - 1);
  post[i][j] = r++;
}
bool ans() {
  bool as = true;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (!pre[i][j]) continue;
      if (G[i][j] == 3) fin = true;
      if (i + 1 < n)
        if (G[i + 1][j] == (G[i][j] + 1) % 4)
          if (pre[i + 1][j] < pre[i][j] and post[i + 1][j] > post[i][j])
            as = false;
      if (j + 1 < n)
        if (G[i][j + 1] == (G[i][j] + 1) % 4)
          if (pre[i][j + 1] < pre[i][j] and post[i][j + 1] > post[i][j])
            as = false;
      if (i - 1 >= 0)
        if (G[i - 1][j] == (G[i][j] + 1) % 4)
          if (pre[i - 1][j] < pre[i][j] and post[i - 1][j] > post[i][j])
            as = false;
      if (j - 1 >= 0)
        if (G[i][j - 1] == (G[i][j] + 1) % 4)
          if (pre[i][j - 1] < pre[i][j] and post[i][j - 1] > post[i][j])
            as = false;
    }
  return as;
}
int dfs(int i, int j) {
  if (dist[i][j] != -1) return dist[i][j];
  int second = 0;
  if (i + 1 < n)
    if (G[i + 1][j] == (G[i][j] + 1) % 4) second = max(second, dfs(i + 1, j));
  if (j + 1 < m)
    if (G[i][j + 1] == (G[i][j] + 1) % 4) second = max(second, dfs(i, j + 1));
  if (i - 1 >= 0)
    if (G[i - 1][j] == (G[i][j] + 1) % 4) second = max(second, dfs(i - 1, j));
  if (j - 1 >= 0)
    if (G[i][j - 1] == (G[i][j] + 1) % 4) second = max(second, dfs(i, j - 1));
  return dist[i][j] = second + 1;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", G[i]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (G[i][j] == 'D') G[i][j] = 0;
      if (G[i][j] == 'I') G[i][j] = 1;
      if (G[i][j] == 'M') G[i][j] = 2;
      if (G[i][j] == 'A') G[i][j] = 3;
    }
  memset(dist, -1, sizeof dist);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (G[i][j] == 0) is(i, j);
  bool c = ans();
  if (!fin) {
    cout << "Poor Dima!" << endl;
    return 0;
  }
  if (!c) {
    cout << "Poor Inna!" << endl;
    return 0;
  }
  int as = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (G[i][j] == 0) as = max(dfs(i, j), as);
  cout << as / 4 << endl;
}
