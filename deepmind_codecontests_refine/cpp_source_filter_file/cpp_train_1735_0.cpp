#include <bits/stdc++.h>
using namespace std;
int const N = 103;
int n;
long long v[N], x;
map<long long, bool> vis2, vis;
vector<long long> an;
map<long long, vector<long long> > g;
void dfs(long long u) {
  vis[u] = true;
  an.push_back(u);
  for (int i = 0; i < g[u].size(); ++i) {
    if (!vis[g[u][i]]) dfs(g[u][i]);
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    x = v[i];
  }
  for (int i = 0; i < n; ++i) {
    x = v[i];
    for (int j = 0; j < n; ++j) {
      if (v[j] * 3 == x || v[j] * 2 == x) {
        g[x].push_back(v[j]);
        g[v[j]].push_back(x);
      }
    }
  }
  long long tmp = 0;
  for (int i = 0; i < n; ++i) {
    if (g[v[i]].size() == 1) {
      tmp = v[i];
      break;
    }
  }
  dfs(tmp);
  if (an[0] / 3 != an[1] && an[0] != an[1] * 2) reverse(an.begin(), an.end());
  for (int i = 0; i < an.size(); ++i) cout << an[i] << " ";
}
