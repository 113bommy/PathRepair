#include <bits/stdc++.h>
using namespace std;
int const sz = 1e5 + 2;
vector<vector<int> > adjlst;
bool exist[101];
bool vis[101];
void dfs(int v) {
  vis[v] = 1;
  for (int i = 0; i < adjlst[v].size(); i++) {
    int vertex = adjlst[v][i];
    if (!vis[vertex]) dfs(vertex);
  }
  return;
}
int m, n;
int main() {
  scanf("%d %d", &n, &m);
  int tmp, a;
  adjlst.resize(n + 1);
  int ans = 0;
  for (int i = 0; i < m; i++) {
    vector<int> lst;
    scanf("%d", &tmp);
    if (!tmp) ans++;
    for (int j = 0; j < tmp; j++) {
      scanf("%d", &a);
      lst.push_back(a - 1);
      exist[a - 1] = 1;
    }
    for (int j = 0; j < tmp; j++) {
      for (int k = j + 1; k < tmp; k++) {
        adjlst[lst[j]].push_back(lst[k]);
        adjlst[lst[k]].push_back(lst[j]);
      }
    }
  }
  int comp = 0;
  for (int i = 0; i < n; i++) {
    if (exist[i] && !vis[i]) {
      dfs(i);
      comp++;
    }
  }
  if (comp) ans += comp - 1;
  printf("%d", ans);
  return 0;
}
