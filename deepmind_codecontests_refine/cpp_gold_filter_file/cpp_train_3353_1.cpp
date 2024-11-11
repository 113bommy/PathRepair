#include <bits/stdc++.h>
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using namespace std;
void nein() {
  cout << "Impossible\n";
  exit(0);
}
const int N = 300;
vector<int> vers[N];
int t[N];
int by[N];
int rd() {
  int ans = 0;
  for (int i = 0; i < 3; ++i) {
    int x;
    cin >> x;
    ans = ans * 2 + x;
  }
  return ans;
}
vector<pair<int, int>> edges;
int ct[N];
int pc[8] = {0, 1, 1, 2, 1, 2, 2, 3};
bool w[8];
int par[8];
void dfs(int x) {
  w[x] = true;
  for (int v : vers[x]) {
    int y = t[v] & x;
    if (!y) {
      continue;
    }
    if (!w[y]) {
      for (int u : vers[y]) {
        edges.emplace_back(v, u);
      }
      par[y] = v;
      dfs(y);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(20);
  fill(par, par + 8, -1);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int m = rd();
    vers[m].push_back(i);
    ct[i] = pc[m] > 1;
  }
  for (int i = 0; i < n; ++i) {
    t[i] = rd();
  }
  for (int i = 1; i < vers[7].size(); ++i) {
    edges.emplace_back(0, vers[7][i]);
  }
  dfs(7);
  for (int i = 0; i < 3; ++i) {
    for (int j = i + 1; j < 3; ++j) {
      int si = (1 << i);
      int sj = (1 << j);
      int x = si + sj;
      if (vers[x].empty() || w[x]) {
        continue;
      }
      if (par[si] == -1 || par[sj] == -1) {
        nein();
      }
      edges.emplace_back(par[si], vers[x][0]);
      edges.emplace_back(par[sj], vers[x][0]);
      ct[vers[x][0]] = 0;
      for (int t = 1; t < vers[x].size(); ++t) {
        edges.emplace_back(vers[x][0], vers[x][t]);
      }
      w[x] = true;
    }
  }
  for (int i = 1; i < 8; ++i) {
    if (vers[i].size() && !w[i]) {
      nein();
    }
  }
  cout << "Possible\n";
  for (int i = 0; i < n; ++i) {
    cout << ct[i] << " ";
  }
  cout << "\n";
  cout << edges.size() << "\n";
  for (auto [x, y] : edges) {
    cout << x + 1 << " " << y + 1 << "\n";
  }
}
