#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10, mod = 1e9 + 7, mmask = 8;
int dp[maxn][mmask], n, ans, t[maxn];
vector<pair<pair<int, int>, pair<int, int>>> v;
char c[maxn][5];
pair<int, int> p;
bool check(int i, int mask) { return (t[i] | mask) == 7; }
int fdp() {
  memset(dp, 0, sizeof(dp));
  memset(t, 0, sizeof(t));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < 3; ++j)
      if (c[j][i] == '.') t[i] ^= (1 << j);
  for (int i = 0; i < mmask; ++i)
    if (check(0, i)) {
      int j = i & t[0];
      if (!(j % 3)) dp[0][i] = 1;
    }
  for (int i = 1; i < n; ++i)
    for (int f = 0; f < mmask; ++f)
      if (check(i, f)) {
        int j = f & t[i];
        dp[i][f] = dp[i - 1][7 ^ j];
        if (j == 3 || j == 6) dp[i][f] = (dp[i][f] + dp[i - 1][7]) % mod;
        if (j == 7)
          dp[i][f] = (dp[i][f] + (dp[i - 1][3] + dp[i - 1][6]) % mod) % mod;
      }
  return dp[n - 1][7];
}
void rep(pair<int, int> d, char f) {
  c[d.first][d.second] = f;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < n; ++j) {
      cin >> c[i][j];
      if (c[i][j] == 'O') p = {i, j};
    }
  if (p.second < n - 2 && c[p.first][p.second + 1] == '.' &&
      c[p.first][p.second + 2] == '.')
    v.push_back({{p.first, p.second + 1}, {p.first, p.second + 2}});
  if (p.second >= 2 && c[p.first][p.second - 1] == '.' &&
      c[p.first][p.second - 2] == '.')
    v.push_back({{p.first, p.second - 1}, {p.first, p.second - 2}});
  if (!p.first && c[p.first + 1][p.second] == '.' &&
      c[p.first + 2][p.second] == '.')
    v.push_back({{p.first + 1, p.second}, {p.first + 2, p.second}});
  if (p.first == 2 && c[p.first - 1][p.second] == '.' &&
      c[p.first - 2][p.second] == '.')
    v.push_back({{p.first - 1, p.second}, {p.first - 2, p.second}});
  int se = v.size(), num = 1 << se;
  for (int i = 1; i < num; ++i) {
    for (int j = 0; j < se; ++j)
      if (i & (1 << j)) {
        rep(v[j].first, 'X');
        rep(v[j].second, 'X');
      }
    int k = fdp();
    if (!(__builtin_popcount(i) & 1)) k = -k;
    ans = (ans + k) % mod;
    for (int j = 0; j < se; ++j)
      if (i & (1 << j)) {
        rep(v[j].first, '.');
        rep(v[j].second, '.');
      }
  }
  if (ans < 0) ans += mod;
  cout << ans << '\n';
  return 0;
}
