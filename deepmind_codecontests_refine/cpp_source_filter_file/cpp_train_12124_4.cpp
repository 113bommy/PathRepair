#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vii = vector<int>;
template <typename T = vii>
using vec = vector<T>;
const int MAX = 2e6 + 5;
vll primes;
bool is_composite[MAX + 1];
int s_prime[MAX + 1];
void sieve() {
  for (int i = 2; i <= MAX; i++) {
    if (!is_composite[i]) {
      primes.push_back(i);
      s_prime[i] = i;
    }
    for (auto p : primes) {
      ll j = i * p;
      if (j > MAX) break;
      is_composite[j] = true;
      s_prime[j] = p;
      if (i % p == 0) break;
    }
  }
}
vii f(int n) {
  vii res;
  while (n > 1) {
    const int p = s_prime[n];
    res.emplace_back(p);
    while (n % p == 0) n /= p;
  }
  return res;
}
int n;
vec<> adj;
vii value;
vii res;
vii height;
map<int, stack<int> > aux;
void dfs(const int curr = 0, const int prev = -1, const int h = 0) {
  if (curr == 0) {
    res.assign(n, -1);
  }
  height[curr] = h;
  const vii v = f(value[curr]);
  int max_height = -1;
  for (const int p : v) {
    if (aux[p].size() and max_height < height[aux[p].top()]) {
      res[curr] = aux[p].top();
      max_height = height[aux[p].top()];
    }
    aux[p].push(curr + 1);
  }
  for (const int node : adj[curr]) {
    if (node == prev) {
      continue;
    }
    dfs(node, curr, h + 1);
  }
  for (const int p : v) {
    aux[p].pop();
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  sieve();
  int q;
  cin >> n >> q;
  adj.resize(n);
  value.resize(n);
  height.resize(n);
  for (auto &e : value) {
    cin >> e;
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  dfs();
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int u;
      cin >> u;
      u--;
      cout << res[u] << '\n';
    } else {
      int u, x;
      cin >> u >> x;
      u--;
      value[u] = x;
      dfs();
    }
  }
}
