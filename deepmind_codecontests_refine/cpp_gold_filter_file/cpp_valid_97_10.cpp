#include <bits/stdc++.h>
using namespace std;
void abc() { cout << endl; }
template <typename T, typename... U>
void abc(T a, U... b) {
  cout << a << ' ', abc(b...);
}
template <typename T>
void printv(T l, T r) {
  while (l != r) cout << *l << " \n"[++l == r];
}
template <typename A, typename B>
istream& operator>>(istream& o, pair<A, B>& a) {
  return o >> a.first >> a.second;
}
template <typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> a) {
  return o << '(' << a.first << ", " << a.second << ')';
}
template <typename T>
ostream& operator<<(ostream& o, vector<T> a) {
  bool is = false;
  for (T i : a) {
    o << (is ? ' ' : '{'), is = true, o << i;
  }
  return o << '}';
}
template <typename T>
struct vv : vector<vector<T>> {
  vv(int n, int m, T v) : vector<vector<T>>(n, vector<T>(m, v)) {}
  vv() {}
};
template <typename T>
struct vvv : vector<vv<T>> {
  vvv(int n, int m, int k, T v) : vector<vv<T>>(n, vv<T>(m, k, v)) {}
  vvv() {}
};
const int mod = 998244353, N = 401, logN = 20, K = 80000;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  vv<int> ans(n, m, -1);
  vector<vector<int>> adj(n * m);
  for (int i = 1; i + 1 < n; ++i)
    for (int j = 1; j + 1 < m; ++j)
      if (s[i][j] == 'X') {
        vector<pair<int, int>> v;
        if (s[i + 1][j] == '.') v.emplace_back(i + 1, j);
        if (s[i - 1][j] == '.') v.emplace_back(i - 1, j);
        if (s[i][j + 1] == '.') v.emplace_back(i, j + 1);
        if (s[i][j - 1] == '.') v.emplace_back(i, j - 1);
        if (int(v.size()) & 1) {
          cout << "NO\n";
          return 0;
        }
        if (v.size() == 2) {
          int x = v[0].first * m + v[0].second,
              y = v[1].first * m + v[1].second;
          adj[x].push_back(y), adj[y].push_back(x);
          ans[i][j] = 5;
        } else if (v.size() == 4) {
          int x = v[0].first * m + v[0].second,
              y = v[3].first * m + v[3].second;
          adj[x].push_back(y), adj[y].push_back(x);
          x = v[2].first * m + v[2].second, y = v[1].first * m + v[1].second;
          adj[x].push_back(y), adj[y].push_back(x);
          ans[i][j] = 10;
        } else {
          ans[i][j] = 0;
        }
      }
  function<void(int)> dfs = [&](int v) {
    for (int u : adj[v])
      if (ans[u / m][u % m] == -1) {
        ans[u / m][u % m] = 5 ^ ans[v / m][v % m];
        dfs(u);
      }
  };
  for (int i = 0; i < n * m; ++i)
    if (!adj[i].empty() && ans[i / m][i % m] == -1) {
      ans[i / m][i % m] = 1;
      dfs(i);
    }
  cout << "YES\n";
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (ans[i][j] == -1)
        cout << (i & 1 ? 1 : 4);
      else
        cout << ans[i][j];
      cout << " \n"[j == m - 1];
    }
}
