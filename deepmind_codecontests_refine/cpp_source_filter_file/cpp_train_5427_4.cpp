#include <bits/stdc++.h>
using namespace std;
int n, k, sum;
vector<vector<int> > g;
vector<int> a;
vector<int> mark;
vector<int> p;
vector<int> deg;
void dfs(int x) {
  mark[x] = 1;
  for (int i = 0; i < g[x].size(); i++) {
    if (!mark[g[x][i]]) {
      p[g[x][i]] = x;
      if (a[g[x][i]] == -1 && deg[g[x][i]] > 1) {
        int min = 1000000007;
        for (int j = 0; j < g[g[x][i]].size(); j++) {
          if (a[g[g[x][i]][j]] < min && g[g[x][i]][j] != x)
            min = a[g[g[x][i]][j]];
        }
        a[g[x][i]] = min;
      } else if (a[g[x][i]] == -1)
        a[g[x][i]] = a[x];
      if (a[x] > a[g[x][i]]) k = 0;
      dfs(g[x][i]);
    }
  }
  if (p[x] != -1)
    sum += a[x] - a[p[x]];
  else
    sum += a[x];
}
int main() {
  k = 1;
  sum = 0;
  cin >> n;
  g = vector<vector<int> >(n);
  mark = vector<int>(n);
  a = vector<int>(n);
  p = vector<int>(n);
  deg = vector<int>(n);
  for (int i = 0; i < n; i++) {
    mark[i] = 0;
    g[i].clear();
    p[i] = -1;
    deg[i] = 0;
  }
  int v;
  for (int i = 1; i < n; i++) {
    cin >> v;
    v--;
    deg[v]++;
    deg[i]++;
    g[i].push_back(v);
    g[v].push_back(i);
  }
  for (int i = 0; i < n; i++) cin >> a[i];
  dfs(0);
  if (!k)
    cout << -1 << "\n";
  else
    cout << sum << "\n";
  return 0;
}
