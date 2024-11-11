#include <bits/stdc++.h>
using namespace std;
bool used[105];
int i, n, m, x, y, k;
vector<vector<int> > g(105);
void dfs(int s) {
  k++;
  used[s] = true;
  for (i = 0; i < g[s].size(); i++)
    if (!used[g[s][i]]) dfs(g[s][i]);
}
int main() {
  cin >> n >> m;
  for (i = 0; i < m; i++) {
    cin >> x >> y;
    g[x - 1].push_back(y - 1);
    g[y - 1].push_back(x - 1);
  }
  dfs(0);
  if (k == n && m == n)
    cout << "FHTAGN!";
  else
    cout << "NO";
  return 0;
}
