#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10, mod = 998244353;
const long long inf = 1e18;
vector<int> v[maxn];
int dp1[maxn], dp2[maxn], dp3[maxn], dp4[maxn];
int Pow(int a, int b) {
  int ans = 1;
  for (; b; b >>= 1, a = 1ll * a * a % mod)
    if (b & 1) ans = 1ll * ans * a % mod;
  return ans;
}
void dfs(int u, int par = -1) {
  for (int y : v[u]) {
    if (y != par) dfs(y, u);
  }
  int num = 1;
  for (int y : v[u]) {
    if (y != par) num = 1ll * num * dp1[y];
  }
  bool come = 0;
  for (int y : v[u]) {
    if (y != par) {
      num = 1ll * num * Pow(dp1[y], mod - 2) % mod;
      dp1[u] = (1ll * dp1[u] + 1ll * dp3[y] * num) % mod;
      if (come)
        dp3[u] = (1ll * dp3[u] + 1ll * dp3[y] * num) % mod;
      else
        dp4[u] = (1ll * dp4[u] + 1ll * dp3[y] * num) % mod;
      num = 1ll * num * (dp4[y] + dp2[y]) % mod;
    } else {
      dp2[u] = num;
      come = 1;
    }
  }
  dp1[u] = (1ll * dp1[u] + num) % mod;
  dp3[u] = (1ll * dp3[u] + num) % mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie();
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  dfs(1);
  return cout << dp1[1] << '\n', 0;
}
