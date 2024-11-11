#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC target("avx")
const long long INF = numeric_limits<long long>::max() / 2;
const long double PI = 3.1415926535898;
const long long MOD = 1e9 + 7;
const long long LIM = 1e5 + 5;
long long fpow(long long x, long long y) {
  long long temp;
  if (y == 0) return 1;
  temp = fpow(x, y / 2);
  if (y % 2 == 0)
    return (temp * temp) % MOD;
  else
    return (x * ((temp * temp) % MOD)) % MOD;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long ans, x[LIM];
vector<long long> adj[LIM];
void dfs(long long u, long long p, map<long long, long long>& mp) {
  map<long long, long long> curmp;
  for (auto ele : mp) curmp[gcd(ele.first, x[u])] += ele.second;
  curmp[x[u]]++;
  for (auto ele : curmp) {
    long long key = ele.first, val = ele.second;
    key %= MOD;
    val %= MOD;
    ans = (ans + (ele.first * ele.second) % MOD) % MOD;
  }
  for (long long x : adj[u]) {
    if (x != p) dfs(x, u, curmp);
  }
}
void solve() {
  long long n;
  cin >> n;
  ans = 0;
  for (long long i = 1; i <= n; ++i) cin >> x[i];
  for (long long i = 0; i < n - 1; ++i) {
    long long u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  map<long long, long long> mp;
  mp.clear();
  dfs(1, 0, mp);
  cout << ans << "\n";
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  { solve(); }
  return 0;
}
