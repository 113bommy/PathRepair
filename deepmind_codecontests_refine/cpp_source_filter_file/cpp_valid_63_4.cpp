#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5, mod = 1e9 + 7;
void time_leap() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
vector<int> par2(1001), par3(1001);
int findParent(int u, vector<int>& par) {
  if (par[u] == u) return u;
  return par[u] = findParent(par[u], par);
}
void join(int a, int b, vector<int>& par) {
  a = findParent(a, par);
  b = findParent(b, par);
  if (a != b) {
    par[a] = b;
  }
}
int main() {
  time_leap();
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  iota(((par2).begin()), ((par2).end()), 0);
  iota(((par3).begin()), ((par3).end()), 0);
  vector<pair<int, int>> ans;
  for (int i = 0; i < m1; ++i) {
    int u, v;
    cin >> u >> v;
    join(u, v, par2);
  }
  for (int i = 0; i < m2; ++i) {
    int u, v;
    cin >> u >> v;
    join(u, v, par3);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (findParent(i, par2) != findParent(j, par2) &&
          findParent(i, par3) != findParent(j, par2)) {
        join(i, j, par2);
        join(i, j, par3);
        ans.push_back({i, j});
      }
    }
  }
  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i].first << " " << ans[i].second << '\n';
  }
  return 0;
}
