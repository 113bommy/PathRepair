#include <bits/stdc++.h>
using namespace std;
const int maxn = 1 * 1000 + 10;
bool markd[maxn], markb[maxn][maxn], flg;
vector<int> vec[maxn], kmk;
int n, m, u, v, ans, maximum = 0, o[maxn], asl, tmp;
queue<pair<int, int> > q;
pair<int, int> hlp;
void dfs(int x, int omgh, int ped) {
  markd[x] = 1;
  kmk.push_back(x);
  o[x] = omgh;
  for (int i = 0; i < ((int(vec[x].size()))); i++) {
    if (!markd[vec[x][i]])
      dfs(vec[x][i], omgh + 1, x);
    else if (vec[x][i] != ped &&
             (max(o[x], o[vec[x][i]]) - min(o[x], o[vec[x][i]])) % 2 != 1)
      flg = 1;
  }
}
int bfs(int x) {
  markb[x][x] = 1;
  q.push(make_pair(x, 0));
  while (!q.empty()) {
    hlp = q.front();
    tmp = max(tmp, hlp.second);
    q.pop();
    for (int i = 0; i < ((int(vec[hlp.first].size()))); i++) {
      if (!markb[x][vec[hlp.first][i]]) {
        markb[x][vec[hlp.first][i]] = 1;
        q.push(make_pair(vec[hlp.first][i], hlp.second + 1));
      }
    }
  }
  return tmp;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    vec[u].push_back(v);
    vec[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    if (!markd[i]) {
      kmk.clear();
      dfs(i, 0, -1);
      if (flg) {
        cout << -1;
        return 0;
      }
      maximum = tmp = 0;
      for (int i = 0; i < ((int(kmk.size()))); i++)
        maximum = max(maximum, bfs(kmk[i]));
      ans += maximum;
    }
  }
  cout << ans;
  return 0;
}
