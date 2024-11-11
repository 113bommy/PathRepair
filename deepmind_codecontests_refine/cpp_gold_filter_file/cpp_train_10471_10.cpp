#include <bits/stdc++.h>
using namespace std;
int n, m;
int door[101000];
vector<pair<int, int> > e[101001];
vector<int> p[101000];
int color[101000];
bool flag = true;
void dfs(int u, int c) {
  if (flag == false) return;
  if (color[u] != -1) {
    if (color[u] != c) flag = false;
    return;
  }
  color[u] = c;
  for (int i = 0; i < e[u].size(); i++) {
    int v = e[u][i].first;
    int w = e[u][i].second;
    dfs(v, c ^ w);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &door[i]);
    door[i] = (door[i] ^ 1);
  }
  int k, x;
  for (int i = 1; i <= m; i++) {
    scanf("%d", &k);
    for (int j = 1; j <= k; j++) {
      scanf("%d", &x);
      p[x].push_back(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    int u = p[i][0];
    int v = p[i][1];
    e[u].push_back(make_pair(v, door[i]));
    e[v].push_back(make_pair(u, door[i]));
  }
  for (int i = 1; i <= m; i++) color[i] = -1;
  for (int i = 1; i <= m; i++) {
    if (color[i] == -1) dfs(i, 0);
  }
  if (flag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
