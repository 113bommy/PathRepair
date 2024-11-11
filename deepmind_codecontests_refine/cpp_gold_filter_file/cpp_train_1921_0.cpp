#include <bits/stdc++.h>
using namespace std;
long long int n, m, v[55], c, s = 1;
vector<int> g[55];
void dfs(long long int n) {
  v[n] = 1;
  c++;
  for (int i = 0; i < g[n].size(); i++)
    if (!v[g[n][i]]) dfs(g[n][i]);
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int t, t2;
    cin >> t >> t2;
    g[t - 1].push_back(t2 - 1);
    g[t2 - 1].push_back(t - 1);
  }
  for (int i = 0; i < n; i++)
    if (!v[i]) {
      c = 0;
      dfs(i);
      long long int k = 1LL << (c - 1);
      s *= k;
    }
  cout << s;
  return 0;
}
