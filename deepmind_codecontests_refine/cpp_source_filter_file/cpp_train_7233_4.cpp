#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '(';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << ')';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> a(n, vector<int>(m));
  vector<int> best(n, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  auto solve_row = [&](int i) {
    int dp[m];
    dp[0] = a[i][0];
    int ans = 0;
    for (int j = 1; j < m; ++j) {
      if (a[i][j] == 0) {
        dp[j] = 0;
      } else {
        dp[j] = dp[j - 1] + 1;
      }
      ans = max(ans, dp[j]);
    }
    best[i] = ans;
  };
  for (int i = 0; i < n; ++i) {
    solve_row(i);
  };
  for (int i = 0; i < q; ++i) {
    int r, c;
    cin >> r >> c;
    r--, c--;
    a[r][c] ^= 1;
    solve_row(r);
    int ans = 0;
    for (int pp : best) {
      ans = max(ans, pp);
    }
    cout << ans << '\n';
  }
  return 0;
}
