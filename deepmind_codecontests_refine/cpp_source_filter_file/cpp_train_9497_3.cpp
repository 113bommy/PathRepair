#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
vector<int> g[N];
int n, p[N];
queue<int> q;
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    p[v]++;
    p[u]++;
  }
  for (int i = 1; i <= n; i++)
    if ((p[i]) == 1) q.push(i);
  while (q.size() > 1) {
    int x = q.front();
    q.pop();
    int y = q.front();
    q.pop();
    cout << "? " << x << " " << y << endl;
    fflush(stdout);
    int lca = 0;
    cin >> lca;
    if (lca == x || y == lca) {
      cout << "! " << lca << endl;
      return 0;
    }
    p[x]--;
    p[y]--;
    for (int i = 0; i < g[x].size(); i++) {
      p[g[x][i]]--;
      if (p[g[x][i]] == 1) q.push(g[x][i]);
    }
    for (int i = 0; i < g[y].size(); i++) {
      p[g[y][i]]--;
      if (p[g[y][i]] == 1) q.push(g[y][i]);
    }
  }
  cout << q.front() << endl;
}
