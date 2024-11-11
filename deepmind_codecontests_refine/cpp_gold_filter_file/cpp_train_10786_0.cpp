#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
inline long long modPow(long long x, long long n) {
  if (n == 0) return (1);
  long long ret = modPow(x, n / 2);
  (ret *= ret) %= mod;
  if (n & 1) (ret *= x) %= mod;
  return (ret);
}
inline long long modInv(long long a) { return (modPow(a, mod - 2)); }
int N;
vector<int> g[100000], order, child[100000];
long long gg[100000], ki[100000];
void dfs(int idx, int par = -1) {
  for (auto &to : g[idx]) {
    if (to != par) {
      dfs(to, idx);
      child[idx].push_back(to);
    }
  }
  order.push_back(idx);
}
int dfs2(int idx, long long pargg) {
  int ret = 0;
  long long latte = 1;
  for (auto &to : child[idx]) (latte *= gg[to]) %= mod;
  (latte *= pargg) %= mod;
  (ret += latte) %= mod;
  (ret += latte) %= mod;
  for (auto &to : child[idx]) {
    (ret += dfs2(to, (latte + latte) % mod * modInv(gg[to]) % mod)) %= mod;
  }
  return (ret);
}
int main() {
  cin >> N;
  for (int i = 1; i < N; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  if (N == 1) {
    cout << 0 << endl;
    return (0);
  } else if (N == 2) {
    cout << 4 << endl;
    return (0);
  }
  int root = 0;
  for (int i = 0; i < N; i++) {
    if (g[i].size() >= 2) root = i;
  }
  dfs(root);
  for (int i : order) {
    long long latte = 1;
    for (auto &to : child[i]) (latte *= gg[to]) %= mod;
    (gg[i] += latte) %= mod;
    if (!child[i].empty()) (gg[i] += latte) %= mod;
  }
  cout << dfs2(root, 1) << endl;
}
