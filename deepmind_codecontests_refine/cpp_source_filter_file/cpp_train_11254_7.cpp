#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int parent[500004];
int findp(int i) { return i == parent[i] ? i : parent[i] = findp(parent[i]); }
void join(int i, int j) {
  i = findp(i), j = findp(j);
  parent[i] = j;
}
long long pow2(int i) {
  long long ret = 1, mult = 2;
  while (i) {
    if (i & 1) ret = (ret * mult) % MOD;
    mult = (mult * mult) % MOD;
    i /= 2;
  }
  return ret;
}
long long submod(long long a, long long b) {
  a %= MOD, b %= MOD;
  return (a >= b ? a - b : a + MOD - b);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  map<long long, vector<pair<int, int>>> mp;
  int n, m, k;
  cin >> n >> m >> k;
  vector<long long> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    parent[i] = i;
  }
  while (m--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    long long x = c[u] ^ c[v];
    mp[x].push_back({u, v});
  }
  int sz = mp.size();
  long long ans = (pow2(n) * submod(pow2(k), sz)) % MOD;
  for (auto &mppr : mp) {
    auto &v = mppr.second;
    int cc = 0, nodes = 0;
    for (auto pr : v) join(pr.first, pr.second);
    for (auto pr : v) {
      int a, b;
      tie(a, b) = pr;
      if (parent[a] == a)
        cc++, nodes++, parent[a] = -1;
      else if (parent[a] != -1)
        nodes++, parent[a] = -1;
      if (parent[b] == b)
        cc++, nodes++, parent[b] = -1;
      else if (parent[a] != -1)
        nodes++, parent[a] = -1;
    }
    for (auto pr : v) {
      int a, b;
      tie(a, b) = pr;
      parent[a] = a;
      parent[b] = b;
    }
    ans = (ans + pow2(n - nodes + cc)) % MOD;
  }
  cout << ans;
}
