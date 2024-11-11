#include <bits/stdc++.h>
using namespace std;
int n, m;
int sett[502];
bool edge[502][502] = {false}, vis[502] = {false}, flag = true;
vector<int> cg[502], u, v;
void bip(int x, bool sig) {
  if (vis[x]) return;
  vis[x] = true;
  sett[x] = sig ? 0 : 2;
  if (sig)
    u.push_back(x);
  else
    v.push_back(x);
  for (int i = 0; i < cg[x].size(); i++) {
    if (!vis[cg[x][i]])
      bip(cg[x][i], !sig);
    else if (sett[x] == sett[cg[x][i]]) {
      flag = false;
      break;
    }
  }
}
bool check() {
  for (int i = 0; i < u.size(); i++)
    for (int j = 0; j < v.size(); j++)
      if (edge[u[i]][v[j]]) return false;
  return true;
}
int main() {
  cin >> n >> m;
  memset(sett, 1, sizeof(sett));
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    edge[x][y] = edge[y][x] = true;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i == j)
        continue;
      else if (!edge[i][j])
        cg[i].push_back(j);
  for (int i = 1; i <= n; i++)
    if (!vis[i] && cg[i].size()) bip(i, true);
  if (flag && check()) {
    cout << "Yes" << endl;
    for (int i = 1; i <= n; i++) printf("%c", 'a' + sett[i]);
  } else
    cout << "No" << endl;
  return 0;
}
