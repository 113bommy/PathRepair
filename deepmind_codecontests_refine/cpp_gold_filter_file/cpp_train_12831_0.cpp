#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 19;
vector<int> e[N];
int a, b, clr[N], n;
void dfs(int u, int p) {
  for (auto v : e[u])
    if (v != p) {
      clr[v] = !clr[u];
      dfs(v, u);
    }
}
int main() {
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(1, 0);
  for (int i = 1; i <= n; ++i)
    if (clr[i])
      ++a;
    else
      ++b;
  cout << min(a, b) - 1 << endl;
  return 0;
}
