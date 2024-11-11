#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool uax(T &x, T y) {
  return (y > x) ? x = y, true : false;
}
template <typename T>
inline bool uin(T &x, T y) {
  return (y < x) ? x = y, true : false;
}
template <typename T>
void kek(T ans) {
  cout << ans << endl;
  exit(0);
}
const int MOD = (int)1e9 + 7;
const long long INF = (long long)1e18 + 42;
const int N = 1e6 + 42;
vector<int> g[N];
int h[N];
int ans[N];
void calc(int u = 0, int p = -1) {
  if (auto it = find(begin(g[u]), end(g[u]), p); it != g[u].end())
    g[u].erase(it);
  for (int v : g[u]) {
    calc(v, u);
    uax(h[u], h[v]);
  }
  for (int &v : g[u]) {
    if (h[u] == h[v]) {
      swap(g[u].back(), v);
      break;
    }
  }
  ++h[u];
}
void dfs(int u, vector<int> &my) {
  if (g[u].empty()) {
    my = {1};
    return;
  }
  dfs(g[u].back(), my);
  ans[u] = ans[g[u].back()] + 1;
  g[u].pop_back();
  int len = 1;
  for (int v : g[u]) {
    vector<int> his;
    dfs(v, his);
    uax(len, int((his).size()));
    for (int i = 0; i < int((his).size()); ++i) {
      my[int((my).size()) - 1 - i] += his[int((his).size()) - 1 - i];
    }
  }
  my.push_back(1);
  for (int i = 0; i < len; ++i) {
    if (my[int((my).size()) - 1 - i] > my[int((my).size()) - 1 - ans[u]]) {
      ans[u] = i;
    } else if (my[int((my).size()) - 1 - i] ==
                   my[int((my).size()) - 1 - ans[u]] &&
               i < ans[u]) {
      ans[u] = i;
    }
  }
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  calc();
  vector<int> tmp;
  dfs(0, tmp);
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << '\n';
  }
}
