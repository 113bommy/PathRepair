#include <bits/stdc++.h>
using namespace std;
const int maxn = 300005;
int n, m;
int color[maxn], vis[maxn];
vector<int> v[maxn], s[maxn];
int ans, mark;
void dfs(int x, int fa) {
  mark++;
  for (int i = 0; i < s[x].size(); i++)
    if (color[s[x][i]]) vis[color[s[x][i]]] = mark;
  int id = 1;
  for (int i = 0; i < s[x].size(); i++)
    if (color[s[x][i]] == 0) {
      while (vis[id] == mark) id++;
      vis[id] = mark;
      color[s[x][i]] = id;
      ans = max(ans, id);
    }
  for (int i = 0; i < v[x].size(); i++)
    if (v[x][i] != fa) dfs(v[x][i], x);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int c, x;
    scanf("%d", &c);
    s[i].clear();
    while (c--) {
      scanf("%d", &x);
      s[i].push_back(x);
    }
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    v[a].push_back(b);
    v[b].push_back(a);
  }
  ans = 1;
  mark = 0;
  dfs(1, 0);
  printf("%d\n", ans);
  for (int i = 1; i <= m; i++) printf("%d ", max(1, color[i]));
  cout << endl;
  return 0;
}
