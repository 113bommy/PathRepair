#include <bits/stdc++.h>
using namespace std;
vector<int> was, comp;
vector<vector<int>> v;
bool bo = true;
int dfs(int x, int l) {
  if (l == 1)
    was[x] = 2;
  else
    was[x] = 1;
  comp.push_back(x);
  for (int i = 0; i < v[x].size(); i++) {
    if (was[v[x][i]] == 0) {
      dfs(v[x][i], was[x]);
    }
    if (was[v[x][i]] == was[x]) bo = false;
  }
  return 0;
}
int main() {
  int t, n, m, a, b, black = 1, white = 1;
  long long ans = 1;
  cin >> t;
  for (int f = 0; f < t; f++) {
    cin >> n >> m;
    was.clear();
    v.clear();
    was.resize(n);
    v.resize(n);
    for (int i = 0; i < m; i++) {
      cin >> a >> b;
      a--;
      b--;
      v[a].push_back(b);
      v[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
      if (was[i] == 0) {
        comp.clear();
        dfs(i, 1);
        for (int j = 0; j < comp.size(); j++) {
          if (was[comp[j]] == 1) black *= 2;
          black = black % 998244353;
          if (was[comp[j]] == 2) white *= 2;
          white = white % 998244353;
        }
        ans = (1ll * ans * (black + white)) % 998244353;
        black = 1;
        white = 1;
      }
    }
    if (bo)
      cout << ans % 998244353 << '\n';
    else
      cout << 0 << '\n';
    bo = true;
    ans = 1;
  }
  return 0;
}
