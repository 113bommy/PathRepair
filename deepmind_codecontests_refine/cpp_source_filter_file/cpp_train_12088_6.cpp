#include <bits/stdc++.h>
using namespace std;
const int NN = 3e5 + 7;
const int N = 1e5 + 7;
const int M = 17;
const int mod = 998244353;
int n, m, q;
int p[N];
int cnt;
int tin[N];
int tout[N];
long long s[N];
long long d[N][M];
int up[N][M];
vector<pair<int, long long> > v[N], vv[N];
int get(int x) { return (p[x] == x ? x : p[x] = get(p[x])); }
void dfs(int x, int p) {
  up[x][0] = p;
  tin[x] = ++cnt;
  for (int i = 1; i < M; i++) {
    up[x][i] = up[up[x][i - 1]][i - 1];
  }
  s[x] += s[p];
  for (auto y : v[x]) {
    if (y.first != p) {
      s[y.first] += y.second;
      dfs(y.first, x);
    }
  }
  tout[x] = cnt;
}
bool upper(int x, int y) { return (tin[x] <= tin[y] && tout[x] >= tout[y]); }
int foos(int x, int y) {
  if (upper(x, y)) return x;
  if (upper(y, x)) return y;
  for (int i = M - 1; i >= 0; i--) {
    if (!upper(up[x][i], y)) {
      x = up[x][i];
    }
  }
  return up[x][0];
}
long long fag(int x, int y) { return s[x] + s[y] - 2 * s[foos(x, y)]; }
void solve1() {
  cin >> n >> m;
  vector<pair<int, pair<int, int> > > g;
  for (int i = 1; i <= m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    g.push_back({z, {y, x}});
    vv[x].push_back({y, z});
    vv[y].push_back({x, z});
  }
  for (int i = 1; i <= n; i++) {
    p[i] = i;
  }
  sort(g.begin(), g.end());
  vector<int> foo;
  for (int j = 0; j < m; j++) {
    auto x = g[j];
    int y = get(x.second.first);
    int z = get(x.second.second);
    if (y != z) {
      p[y] = z;
      v[x.second.first].push_back({x.second.second, x.first});
      v[x.second.second].push_back({x.second.first, x.first});
    } else
      foo.push_back(j);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < M; j++) {
      d[i][j] = 1e18;
    }
  }
  dfs(1, 1);
  for (int i = 0; i < (int)foo.size(); i++) {
    set<pair<long long, int> > s;
    s.insert({0ll, g[foo[i]].second.second});
    d[g[foo[i]].second.second][i] = 0;
    while (!s.empty()) {
      auto x = *s.begin();
      s.erase(s.begin());
      for (auto y : vv[x.second]) {
        if (d[y.first][i] > y.second + d[x.second][i]) {
          s.erase({d[y.first][i], y.first});
          d[y.first][i] = y.second + d[x.second][i];
          s.insert({d[y.first][i], y.first});
        }
      }
    }
  }
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int x, y;
    cin >> x >> y;
    long long res = fag(x, y);
    for (int j = 0; j < (int)foo.size(); j++) {
      res = min(res, d[x][j] + d[y][j]);
    }
    cout << res << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  srand(time(0));
  int cghf = 1;
  while (cghf--) {
    solve1();
  }
}
