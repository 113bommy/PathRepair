#include <bits/stdc++.h>
using namespace std;
const long long LINF = (long long)1e18 + 47;
const int INF = 2 * 1e9 + 47;
const int MOD = 1e9 + 7;
const int modulo = 1e8;
const int nax = 2 * (int)1e5 + 10;
vector<int> g[nax];
vector<pair<int, int>> edges;
vector<int> order;
int used[nax];
int pos[nax];
void dfs(int v) {
  used[v] = 1;
  for (auto to : g[v]) {
    if (!used[to]) dfs(to);
  }
  order.emplace_back(v);
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int tt;
  cin >> tt;
  for (int test = (1); test < (tt + 1); test++) {
    int n, m;
    cin >> n >> m;
    for (int i = (0); i < (m); i++) {
      int a, b, t;
      cin >> t >> a >> b;
      --a, --b;
      if (t == 1) {
        g[a].emplace_back(b);
      } else {
        edges.emplace_back(a, b);
      }
    }
    for (int i = (0); i < (n); i++)
      if (!used[i]) dfs(i);
    reverse(order.begin(), order.end());
    for (int i = (0); i < (n); i++) {
      pos[order[i]] = i;
    }
    bool bad = 0;
    for (int i = (0); i < (n); i++) {
      for (auto to : g[i]) {
        if (pos[to] < pos[i]) bad = 1;
      }
    }
    if (bad) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      for (int i = (0); i < (n); i++) {
        for (auto to : g[i]) {
          cout << i + 1 << ' ' << to << '\n';
        }
      }
      for (auto x : edges) {
        if (pos[x.first] < pos[x.second])
          cout << x.first + 1 << ' ' << x.second + 1 << '\n';
        else
          cout << x.second + 1 << ' ' << x.first + 1 << '\n';
      }
    }
    for (int i = (0); i < (n); i++) {
      used[i] = 0;
      g[i].clear();
    }
    order.clear();
    edges.clear();
  }
}
