#include <bits/stdc++.h>
using namespace std;
long long q, dp[555][15550], a[555555], b[555555], k, l, m, n, o, p;
map<long long, long long> mp;
vector<long long> adj[555555];
const long long mod = 1e9 + 7;
long long mem(long long i, long long op) {
  if (op == 0) return 1;
  if (i > n) return 0;
  long long &r = dp[i][op];
  if (r != -1) return r;
  r = (mem(i + 1, op) + mem(i, op - 1)) % mod;
  return r;
}
void solve() {
  memset(dp, -1, sizeof dp);
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> k;
    p = k;
    for (long long j = 2; j * j <= p; j++) {
      while (k % j == 0) {
        k /= j;
        mp[j]++;
      }
    }
    if (k - 1) mp[k]++;
  }
  o = 1;
  for (auto u : mp) {
    o = (o * mem(1, u.second)) % mod;
  }
  cout << o << endl;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  q = 1;
  while (q--) {
    solve();
  }
}
