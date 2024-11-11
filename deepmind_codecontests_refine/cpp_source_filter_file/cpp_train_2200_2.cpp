#include <bits/stdc++.h>
using namespace std;
long long mult(long long a, long long b, long long p = 1000000007) {
  long long ans = ((a % p) * (b % p)) % p;
  return (ans + p) % p;
}
long long add(long long a, long long b, long long p = 1000000007) {
  long long ans = (a % p + b % p) % p;
  return (ans + p) % p;
}
long long fpow(long long n, long long k, long long p = 1000000007) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
long long inv(long long a, long long p = 1000000007) {
  return fpow(a, p - 2, p);
}
long long n, m, q;
string name;
vector<long long> adj(40, 0);
unordered_map<long long, int> dp = {{0, 0}};
int solve(long long mask) {
  auto it = dp.find(mask);
  if (it != dp.end()) return it->second;
  int firstsetbit = -1;
  for (int i = 0; i < m; ++i)
    if (mask & (1ll << i) == (1ll << i)) {
      firstsetbit = i;
      break;
    }
  dp[mask] = max(solve(mask & (~(1ll << firstsetbit))),
                 1 + solve(mask & adj[firstsetbit]));
  return dp[mask];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < m; i++) adj[i] = (1ll << m) - 1;
  int ind = 0;
  map<string, int> names;
  set<int> group;
  for (int i = 0; i < n + 1; i++) {
    if (i < n)
      cin >> q;
    else
      q = 1;
    if (q == 1) {
      if (!group.empty()) {
        for (auto &i : group)
          for (auto &j : group) adj[i] = adj[i] & (~(1ll << j));
      }
      group.clear();
      if (i == n) break;
    } else {
      cin >> name;
      auto it = names.find(name);
      if (it == names.end()) {
        names[name] = ind++;
        group.insert(ind - 1);
      } else
        group.insert(it->second);
    }
  }
  for (int i = 0; i < m; i++) adj[i] = adj[i] & (~(1ll << i));
  cout << solve((1ll << m) - 1) << endl;
  return 0;
}
