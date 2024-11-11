#include <bits/stdc++.h>
#pragma GCC target("arch=ivybridge")
using namespace ::std;
template <class T>
istream& operator>>(istream& I, vector<T>& v) {
  for (T& e : v) I >> e;
  return I;
}
template <class T>
ostream& operator<<(ostream& O, const vector<T>& v) {
  for (const T& e : v) O << e << ' ';
  return O;
}
template <class T>
ostream& operator<<(ostream& O, const deque<T>& v) {
  for (const T& e : v) O << e << ' ';
  return O;
}
char grid[105][105];
bool valid[105][105];
void _main() {
  long long n, m;
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      cin >> grid[i][j];
      valid[i][j] = grid[i][j] == '.';
    }
  }
  vector<array<long long, 3>> ans;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      if (grid[i][j] == '.') continue;
      long long p = 0;
      for (long long k = 1; k <= n; k++) {
        if (i - k < 1 || i + k > n || j - k < 1 || j + k > m) break;
        vector<pair<long long, long long>> vec;
        vec.emplace_back(i, j);
        vec.emplace_back(i - k, j);
        vec.emplace_back(i + k, j);
        vec.emplace_back(i, j - k);
        vec.emplace_back(i, j + k);
        set<char> s;
        s.emplace(grid[i - k][j]);
        s.emplace(grid[i + k][j]);
        s.emplace(grid[i][j - k]);
        s.emplace(grid[i][j + k]);
        if (s.size() == 1 && *s.begin() == '*') {
          p = k;
          for (const auto w : vec) valid[w.first][w.second] = 1;
        } else {
          break;
        }
      }
      if (p >= 1) ans.emplace_back(array<long long, 3>{i, j, p});
    }
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      if (!valid[i][j]) {
        cout << -1;
        return;
      }
    }
  }
  cout << ans.size() << '\n';
  for (long long i = 0; i < ans.size(); i++)
    cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int _t = 1;
  while (_t--) _main();
  return 0;
}
