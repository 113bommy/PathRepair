#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
vector<int> g[N];
int c[N];
int cnt = 0;
void dfs(int v, int p = -1) {
  ++cnt;
  c[v] = 1;
  for (int i = 0; i < g[v].size(); ++i) {
    int to = g[v][i];
    if (to == p) continue;
    if (c[v] == 2) {
      cout << "no\n";
      exit(0);
    }
    if (!c[v]) dfs(to);
  }
  c[v] = 2;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  if (m != n - 1) {
    cout << "no\n";
    return 0;
  }
  dfs(1);
  cout << (cnt == n ? "yes\n" : "no\n");
  return 0;
}
