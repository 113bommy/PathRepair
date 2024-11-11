#include <bits/stdc++.h>
using namespace std;
template <class T>
bool setmax(T &_a, T _b) {
  if (_b > _a) {
    _a = _b;
    return true;
  }
  return false;
}
template <class T>
bool setmin(T &_a, T _b) {
  if (_b < _a) {
    _a = _b;
    return true;
  }
  return false;
}
template <class T>
T gcd(T _a, T _b) {
  return _b == 0 ? _a : gcd(_b, _a % _b);
}
const int N = 555;
bool g[N][N];
int d[N];
int n;
int main() {
  memset(d, 0, sizeof(d));
  memset(g, false, sizeof(g));
  int m;
  cin >> n >> m;
  for (int i = int(1); i <= int(m); ++i) {
    int u, v;
    cin >> u >> v;
    g[u][v] = g[v][u] = true;
    d[u]++, d[v]++;
  }
  if (m == n * (n - 1) / 2) {
    cout << "Yes" << endl << string(n, 'a') << endl;
    return 0;
  }
  string r(n, ' ');
  function<bool(int, char)> dfs = [&](int i, char c) {
    if (r[i - 1] != ' ') return r[i - 1] == c;
    r[i - 1] = c;
    for (int j = int(1); j <= int(n); ++j)
      if (j != i && !g[i][j]) {
        if (!dfs(j, c == 'a' ? 'c' : 'a')) return false;
      }
    return true;
  };
  for (int i = int(1); i <= int(n); ++i)
    if (r[i - 1] == ' ') {
      if (d[i] == n - 1)
        r[i - 1] = 'b';
      else {
        if (!dfs(i, 'a')) {
          cout << "No" << endl;
          return 0;
        }
      }
    }
  for (int i = int(1); i <= int(n); ++i)
    for (int j = int(1); j <= int(n); ++j)
      if (r[i - 1] == 'a' && r[j - 1] == 'c' && g[i][j]) {
        cout << "No" << endl;
        return 0;
      }
  cout << "Yes" << endl << r << endl;
  return 0;
}
