#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
const double PI = acos(-1.0);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long n;
const long long N = 1e5 + 10;
vector<long long> adj[N];
long long ar[N];
long long s;
long long leaf_parity = 0;
void dfs1(long long node, long long par) {
  if (adj[node].empty()) {
    leaf_parity = par;
  }
  for (auto x : adj[node]) {
    dfs1(x, par ^ 1);
  }
}
map<long long, long long> cnt[2];
void dfs2(long long node, long long par) {
  cnt[par][ar[node]]++;
  if (par == leaf_parity) {
    s ^= ar[node];
  }
  for (auto x : adj[node]) {
    dfs2(x, par ^ 1);
  }
}
long long c2(long long x) { return (x * (x - 1)) / 2; }
long long ans;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> ar[i];
  for (long long i = 2; i <= n; i++) {
    long long p;
    cin >> p;
    adj[p].push_back(i);
  }
  dfs1(1, 0);
  dfs2(1, 0);
  if (s == 0) {
    long long s0 = 0, s1 = 0;
    for (auto x : cnt[0]) {
      s0 += x.second;
      ans += x.second * cnt[1][x.first];
    }
    for (auto x : cnt[1]) {
      s1 += x.second;
    }
    ans += c2(s0) + c2(s1);
  } else {
    for (auto x : cnt[0]) {
      ans += x.second * cnt[1][s ^ x.first];
    }
    cout << ans << "\n";
  }
}
