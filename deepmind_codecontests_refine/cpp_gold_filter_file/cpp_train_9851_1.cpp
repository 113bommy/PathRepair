#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  struct coor {
    int x, y, id;
  } cr[n + 5];
  for (int i = 1; i <= n; ++i) {
    int x, y;
    cin >> x >> y;
    cr[i] = (coor){x, y, i};
  }
  vector<int> e[n + 5];
  sort(cr + 1, cr + 1 + n, [&](coor a, coor b) { return a.x < b.x; });
  for (int i = 1; i < n; ++i) {
    if (cr[i].x == cr[i + 1].x) {
      e[cr[i].id].emplace_back(cr[i + 1].id);
      e[cr[i + 1].id].emplace_back(cr[i].id);
    }
  }
  sort(cr + 1, cr + 1 + n, [&](coor a, coor b) { return a.y < b.y; });
  for (int i = 1; i < n; ++i) {
    if (cr[i].y == cr[i + 1].y) {
      e[cr[i].id].emplace_back(cr[i + 1].id);
      e[cr[i + 1].id].emplace_back(cr[i].id);
    }
  }
  sort(cr + 1, cr + 1 + n, [&](coor a, coor b) { return a.id < b.id; });
  long long ans = 1;
  unordered_map<int, int> vis;
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      unordered_map<int, int> x_val, y_val;
      function<bool(int, int)> dfs = [&](int u, int fa) {
        bool ok = 0;
        x_val[cr[u].x] = y_val[cr[u].y] = 1;
        vis[u] = 1;
        for (auto v : e[u]) {
          if (v == fa) continue;
          if (vis[v]) {
            ok = 1;
            continue;
          }
          if (dfs(v, u)) ok = 1;
        }
        return ok;
      };
      bool ok = dfs(i, 0);
      auto ksm = [&](int a, int b) {
        long long res = 1, bs = a;
        while (b) {
          if (b & 1) res = res * bs % P;
          bs = bs * bs % P;
          b >>= 1;
        }
        return res;
      };
      int res = (int)x_val.size() + (int)y_val.size();
      if (ok)
        ans = ans * ksm(2, res) % P;
      else
        ans = ans * (ksm(2, res) - 1) % P;
    }
  }
  cout << ans << '\n';
  return 0;
}
