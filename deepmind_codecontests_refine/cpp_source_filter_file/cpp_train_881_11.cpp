#include <bits/stdc++.h>
#pragma comment(linker, ”/ STACK : 36777216“)
int ddx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int ddy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
using namespace std;
vector<int> g[3][100011];
int ID[100011];
int color[100011];
void dfs(int v, int id) {
  ID[v] = id;
  for (int _n((g[0][v].size()) - 1), i(0); i <= _n; ++i)
    if (!ID[g[0][v][i]]) dfs(g[0][v][i], id);
}
bool dfs2(int v, int cur) {
  if (color[v] == cur) return 1;
  if (color[v] != -1) return 0;
  color[v] = cur;
  bool ok = 1;
  for (int _n((g[2][v].size()) - 1), i(0); i <= _n; ++i)
    if (!dfs2(g[2][v][i], cur ^ 1)) ok = 0;
  return ok;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int _n((m)-1), i(0); i <= _n; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    g[c][a].push_back(b);
    g[c][b].push_back(a);
  }
  int id = 1;
  for (int _n((n)-1), i(0); i <= _n; ++i)
    if (!ID[i]) dfs(i, id++);
  for (int _n((n)-1), i(0); i <= _n; ++i)
    for (int _n((g[1][i].size()) - 1), j(0); j <= _n; ++j)
      g[2][ID[g[1][i][j]]].push_back(ID[i]),
          g[2][ID[i]].push_back(ID[g[1][i][j]]);
  for (int _n((id)-1), i(0); i <= _n; ++i) color[i + 1] = -1;
  int cmp = 0;
  for (int _n(id - 1), i(1); i <= _n; ++i)
    if (color[i] == -1) {
      ++cmp;
      if (!dfs2(i, 0)) {
        cout << 0 << endl;
        return 0;
      }
    }
  long long ans = 1;
  for (int _n((cmp - 1) - 1), i(0); i <= _n; ++i) ans <<= 1, ans %= 1000000007;
  cout << ans << endl;
  return 0;
}
