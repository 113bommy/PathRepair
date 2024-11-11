#include <bits/stdc++.h>
using namespace std;
vector<int> g[110000];
int dep[110000];
void dfs(int x, int f) {
  for (int i = 0; i < g[x].size(); ++i) {
    if (g[x][i] == f) continue;
    dep[g[x][i]] = dep[x] + 1;
    dfs(g[x][i], x);
  }
}
int main() {
  int n, u, v;
  long long k, p;
  cin >> n >> k >> p;
  for (int i = 1; i < n; ++i) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  if (k == 0) {
    puts("0");
    return 0;
  }
  dfs(1, 0);
  sort(dep, dep + n);
  long long pp = p, res = 1;
  for (int i = n - 1, j = n - 1; i > 0; --i) {
    if (dep[i] != dep[i + 1]) pp += i - j;
    while (j > 0 && k > i - j && pp >= dep[i] - dep[j])
      pp -= (dep[i] - dep[j]), j--;
    long long kk = i - j;
    res = max(res, kk);
  }
  cout << res << endl;
  return 0;
}
