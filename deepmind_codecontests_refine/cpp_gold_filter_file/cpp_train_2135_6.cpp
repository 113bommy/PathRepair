#include <bits/stdc++.h>
using namespace std;
void solve();
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed;
  cout.precision(12);
  solve();
  return 0;
}
template <typename T>
void prv(vector<T> v) {
  for (int __ii = 0; __ii < ((int)v.size()); __ii++) {
    if (__ii) cout << ' ';
    cout << v[__ii];
  }
  cout << '\n';
}
template <typename T>
void prm(vector<vector<T>> v) {
  for (int __ii = 0; __ii < ((int)v.size()); __ii++) {
    for (int __jj = 0; __jj < v[__ii].size(); __jj++) {
      if (__jj) cout << ' ';
      cout << v[__ii][__jj];
    }
    cout << '\n';
  }
}
template <typename T>
void sc(T& x) {
  cin >> x;
}
template <typename Head, typename... Tail>
void sc(Head& head, Tail&... tail) {
  cin >> head;
  sc(tail...);
}
template <typename T>
void pr(const T& x) {
  cout << x << '\n';
}
template <typename Head, typename... Tail>
void pr(const Head& head, const Tail&... tail) {
  cout << head << ' ';
  pr(tail...);
}
template <typename... T>
void err(const T&... cod) {
  pr(cod...);
  exit(0);
}
const int N = 110;
int dp[3][N];
string a[3];
int n, k;
int dfs(int y, int x) {
  if (x >= n) return 1;
  if (dp[y][x] != -1) return dp[y][x];
  int win = 0;
  for (int dy = -1; dy < 2; dy++) {
    if (y + dy >= 0 && y + dy < 3) {
      bool obstacle = false;
      for (int dx = 1; dx < 4; dx++) {
        if (x + dx < n) obstacle |= a[y + dy][x + dx] != '.';
      }
      if (x + 1 < n) obstacle |= a[y][x + 1] != '.';
      if (!obstacle) win |= dfs(y + dy, x + 3);
    }
  }
  return dp[y][x] = win;
}
void solve_case() {
  cin >> n >> k;
  for (int i = 0; i < 3; i++) cin >> a[i];
  memset(dp, -1, sizeof dp);
  for (int i = 0; i < 3; i++)
    if (a[i][0] == 's') pr(dfs(i, 0) ? "YES" : "NO");
}
void solve() {
  int qq;
  sc(qq);
  while (qq--) solve_case();
}
