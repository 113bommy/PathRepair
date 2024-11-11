#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1.0);
const int maxn = 100000 + 10;
const int mod = 1e9 + 7;
vector<int> nt[312345];
vector<int> id[312345];
int mark[312345];
int vis[312345];
vector<int> out;
int dfs(int x) {
  if (vis[x]) return 0;
  vis[x] = 1;
  int p = 0;
  for (int i = 0; i < nt[x].size(); i++) {
    if (dfs(nt[x][i])) {
      p ^= 1;
      out.push_back(id[x][i]);
    }
  }
  if (mark[x] == -1) return 0;
  if (p == mark[x]) return 0;
  return 1;
}
int main() {
  int t = 1;
  int n;
  int m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", mark + i);
    if (mark[i] == -1) t = i;
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    nt[v].push_back(u);
    nt[u].push_back(v);
    id[u].push_back(i + 1);
    id[v].push_back(i + 1);
  }
  if (dfs(t)) return 0 * puts("-1");
  printf("%d", out.size());
  for (int i = 0; i < out.size(); i++) printf("%d\n", out[i]);
  return 0;
}
