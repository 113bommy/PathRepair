#include <bits/stdc++.h>
using namespace std;
long long int binpow(long long int a, long long int b) {
  if (a == 0) return 0;
  if (b == 0) return 1;
  long long int ans = 1;
  while (b > 0) {
    if (b & 1) ans = ans * a;
    a = a * a;
    b = b >> 1;
  }
  return ans;
}
long long int binpowM(long long int a, long long int b,
                      long long int m = 1000000007) {
  if (a == 0) return 0;
  if (b == 0) return 1;
  long long int ans = 1;
  while (b > 0) {
    if (b & 1) ans = ans * a;
    ans %= m;
    a = a * a;
    a %= m;
    b = b >> 1;
  }
  return ans;
}
template <typename T>
T Min(T a, T b) {
  return a < b ? a : b;
}
template <typename T>
T Max(T a, T b) {
  return a > b ? a : b;
}
int n, m;
vector<vector<bool> > vis;
vector<string> a;
bool dfs(int i, int j, char c, char &t) {
  if (i < 0 || j < 0 || i >= n || j >= m || t != a[i][j]) return 0;
  if (vis[i][j]) {
    return 1;
  }
  bool ans = 0;
  vis[i][j] = 1;
  if (c != 'L') ans |= dfs(i - 1, j, 'R', t);
  if (c != 'R') ans |= dfs(i + 1, j, 'L', t);
  if (c != 'U') ans |= dfs(i, j - 1, 'D', t);
  if (c != 'D') ans |= dfs(i, j + 1, 'U', t);
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  vis.resize(n);
  vector<bool> X(m, 0);
  for (int i = 0; i < (n); ++i) vis[i] = X;
  a.resize(n);
  for (int i = 0; i < (n); ++i) cin >> a[i];
  bool ch = 0;
  for (int i = 0; i < (n); ++i)
    for (int j = 0; j < (m); ++j) {
      if (vis[i][j] == 0) ch |= dfs(i, j, 'a', a[i][j]);
    }
  ch ? cout << "Yes" << '\n' : cout << "No" << '\n';
  return 0;
}
