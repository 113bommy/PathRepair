#include <bits/stdc++.h>
int IntMaxVal = (int)1e20;
int IntMinVal = (int)-1e20;
long long LongMaxVal = (long long)1e20;
long long LongMinVal = (long long)-1e20;
using namespace std;
template <typename T>
struct argument_type;
template <typename T, typename U>
struct argument_type<T(U)> {};
template <typename T1, typename T2>
istream& operator>>(istream& is, pair<T1, T2>& s) {
  is >> s.first >> s.second;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (int i = 0; i < v.size(); i++) os << v[i] << ' ';
  os << '\n';
  ;
  return os;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& s, pair<T1, T2>& t) {
  s << t.first << ' ' << t.second;
  return s;
}
int main() {
  srand(time(NULL));
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  ;
  int m;
  cin >> m;
  ;
  int k;
  cin >> k;
  ;
  int f[n][m];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cin >> f[i][j];
  }
  int ans = IntMaxVal;
  if (n <= k) {
    for (int mask = 0; mask < 1 << n; ++mask) {
      int res = 0;
      vector<int> row(n);
      for (int j = 0; j < n; ++j) row[j] = (mask & (1 << j)) ? 1 : 0;
      for (int r2 = 0; r2 < m; ++r2) {
        int match = 0;
        for (int j = 0; j < n; ++j)
          if (f[j][r2] == row[j]) match++;
        res += min(match, m - match);
      }
      { ans = min(ans, res); };
    }
  } else {
    for (int r = 0; r < n; ++r) {
      int res = 0;
      for (int r2 = 0; r2 < n; ++r2) {
        int match = 0;
        for (int j = 0; j < m; ++j)
          if (f[r2][j] == f[r][j]) match++;
        res += min(match, m - match);
      }
      { ans = min(ans, res); };
    }
  }
  if (ans > k)
    cout << -1;
  else
    cout << ans;
}
