#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
bool visit[100005] = {0};
vector<long long> g[100005];
long long n, m, k;
long long dfs(long long node) {
  long long val = 1;
  visit[node] = 1;
  for (int i = 0; i < g[node].size(); i++)
    if (visit[g[node][i]] == 0) {
      val += dfs(g[node][i]);
    }
  return val;
}
int main() {
  long long x, y, ans = 1;
  cin >> n >> m >> k;
  mod = k;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  x = 0;
  for (int i = 1; i <= n; i++)
    if (visit[i] == 0) {
      x++;
      ans = ans * dfs(i) % k;
    }
  if (x == 1) {
    cout << 1 % k << endl;
    return 0;
  }
  ans = ans * powmod(n, x - 2) % k;
  cout << ans << endl;
  return 0;
}
