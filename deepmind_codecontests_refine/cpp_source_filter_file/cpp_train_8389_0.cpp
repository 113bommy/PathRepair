#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
const long long mod = 1000000007;
const long long N = 10001;
const long long alp = 26;
const long long inf = 2e9;
const long long infll = 3e18;
vector<long long> u;
vector<long long> p;
vector<vector<long long> > g;
void dfs(int v) {
  u[v] = 1;
  for (int i = 0; i < g[v].size(); i++) {
    if (u[g[v][i]] == 0) {
      p[g[v][i]] = v;
      dfs(g[v][i]);
    }
  }
}
int solve() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  g.resize(n * m);
  u.assign(n * m, 0);
  p.assign(n * m, -1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '*') continue;
      int now = i * m + j;
      if (i != 0) {
        int can = (i - 1) * m + j;
        if (a[i - 1][j] != '*') g[now].push_back(can);
      }
      if (j != 0) {
        int can = (i)*m + j - 1;
        if (a[i][j - 1] != '*') g[now].push_back(can);
      }
      if (i != n - 1) {
        int can = (i + 1) * m + j;
        if (a[i + 1][j] != '*') g[now].push_back(can);
      }
      if (j != m - 1) {
        int can = (i)*m + j + 1;
        if (a[i][j + 1] != '*') g[now].push_back(can);
      }
    }
  }
  dfs(0);
  string ans = "";
  pair<int, int> f;
  pair<int, int> ff;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (a[i][j] == 'F') f = {i, j};
  ff = f;
  ff.first++;
  ff.second++;
  while (f != make_pair(0, 0)) {
    int now = f.first * m + f.second;
    int prev = p[now];
    if (prev - now == m) ans.push_back('U');
    if (prev - now == -m) ans.push_back('D');
    if (prev - now == 1) ans.push_back('L');
    if (prev - now == -1) ans.push_back('R');
    f = {prev / m, prev % m};
  }
  reverse(ans.begin(), ans.end());
  int nlr = -1, nud = -1;
  f = {1, 1};
  for (int i = 0; i < ans.size(); i++) {
    if (ans[i] == 'U' || ans[i] == 'D') {
      if (nud == -1) {
        cout << ans[i] << endl;
        int x, y;
        cin >> x >> y;
        if (make_pair(x, y) == f) {
          nud = 1;
          if (ans[i] == 'U')
            ans[i] = 'D';
          else
            ans[i] = 'U';
          cout << ans[i] << endl;
          cin >> x >> y;
          f = {x, y};
        } else {
          nud = 0;
          f = {x, y};
        }
      } else if (nud == 1) {
        if (ans[i] == 'U')
          ans[i] = 'D';
        else
          ans[i] = 'U';
        cout << ans[i] << endl;
        int x, y;
        cin >> x >> y;
        f = {x, y};
      } else if (nud == 0) {
        cout << ans[i] << endl;
        int x, y;
        cin >> x >> y;
        f = {x, y};
      }
    } else {
      if (nlr == -1) {
        cout << ans[i] << endl;
        int x, y;
        cin >> x >> y;
        if (make_pair(x, y) == f) {
          nlr = 1;
          if (ans[i] == 'L')
            ans[i] = 'R';
          else
            ans[i] = 'L';
          cout << ans[i] << endl;
          cin >> x >> y;
          f = {x, y};
        } else {
          nlr = 0;
          f = {x, y};
        }
      } else if (nlr == 1) {
        if (ans[i] == 'L')
          ans[i] = 'R';
        else
          ans[i] = 'L';
        cout << ans[i] << endl;
        int x, y;
        cin >> x >> y;
        f = {x, y};
      } else if (nlr == 0) {
        cout << ans[i] << endl;
        int x, y;
        cin >> x >> y;
        f = {x, y};
      }
    }
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
