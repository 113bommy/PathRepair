#include <bits/stdc++.h>
using namespace std;
const int MX = 505, mod = 998244353;
int n, m;
vector<int> c, pos[MX];
long long mem[2 * MX][2 * MX];
bool isValid(int a, int b) {
  if (a != pos[c[a]][0] && a != pos[c[a]].back()) return 0;
  if (b != pos[c[b]][0] && b != pos[c[b]].back()) return 0;
  for (int i = 1; i <= n; i++)
    if ((a <= pos[i][0] && pos[i][0] <= b) !=
        (a <= pos[i].back() && pos[i].back() <= b))
      return 0;
  return 1;
}
long long dp(int a, int b) {
  if (a > b) return 1;
  long long &res = mem[a][b];
  if (res != -1) return res;
  if (!isValid(a, b)) return res = 0;
  int mn = c[a];
  for (int i = a; i <= b; i++) mn = min(mn, c[i]);
  int ind = pos[mn][0];
  long long x = dp(a, ind - 1);
  for (int i = a; i < ind; i++) x += dp(a, i) * dp(i + 1, ind - 1) % mod;
  x %= mod;
  ind = pos[mn].back();
  long long y = dp(ind + 1, b);
  for (int i = ind + 1; i <= b; i++) y += dp(ind + 1, i) * dp(i + 1, b) % mod;
  y %= mod;
  res = 1;
  for (int i = 0; i + 1 < pos[mn].size(); i++)
    (res *= dp(pos[mn][i] + 1, pos[mn][i + 1] - 1)) %= mod;
  (res *= x) %= mod;
  (res *= y) %= mod;
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  c.resize(m);
  for (int i = 0; i < m; i++) cin >> c[i];
  c.erase(unique(c.begin(), c.end()), c.end());
  if (c.size() > 2 * n) {
    cout << 0 << '\n';
    return 0;
  }
  m = c.size();
  for (int i = 0; i < m; i++) pos[c[i]].emplace_back(i);
  memset(mem, -1, sizeof(mem));
  cout << dp(0, m - 1) << '\n';
  return 0;
}
