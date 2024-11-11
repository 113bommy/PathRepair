#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " , ";
  __f(comma + 1, args...);
}
const int maxn = 2e5 + 10;
long long ans1, ans2;
vector<pair<int, int>> g[maxn];
vector<int> siz;
int n;
void dfs(int u, int par) {
  siz[u] = 1;
  for (auto v : g[u])
    if (v.first != par) {
      dfs(v.first, u);
      siz[u] += siz[v.first];
      if (siz[v.first] & 1) ans1 += v.second;
      ans2 += min(siz[v.first], n - siz[v.first]) * v.second;
    }
}
int main() {
  ios::sync_with_stdio(0);
  int i, j, k, tt;
  cin >> tt;
  while (tt--) {
    cin >> n;
    n <<= 1;
    siz.resize(n, 0);
    for (i = 0; i < n; ++i) g[i].clear();
    vector<pair<pair<int, int>, int>> ed;
    for (i = 0; i < n - 1; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      u--, v--;
      g[u].push_back({v, w});
      g[v].push_back({u, w});
      ed.push_back({{u, v}, w});
    }
    ans1 = ans2 = 0;
    dfs(0, -1);
    cout << ans1 << " " << ans2 << "\n";
  }
  return 0;
}
