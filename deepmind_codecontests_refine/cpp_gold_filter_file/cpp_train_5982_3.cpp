#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const int maxn = 100010;
const int lim = (int)1e9;
int n, x;
vector<int> v[maxn];
vector<int> colour;
pair<lli, lli> dfs(int node) {
  pair<lli, lli> dp = {1ll, 0ll};
  for (auto i : v[node]) {
    pair<lli, lli> aux = dfs(i);
    dp = {1ll * dp.first * ((aux.first + aux.second) % MOD) % MOD,
          1ll * (dp.second * ((aux.first + aux.second) % MOD) % MOD +
                 (1ll * dp.first * aux.second) % MOD)};
  }
  pair<lli, lli> temp = {0ll, dp.first};
  return (colour[node] ? temp : dp);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i + 1 < n; ++i) {
    cin >> x;
    v[x].push_back(i + 1);
  }
  colour.resize(n);
  for (auto &i : colour) cin >> i;
  cout << (dfs(0).second) % MOD;
}
