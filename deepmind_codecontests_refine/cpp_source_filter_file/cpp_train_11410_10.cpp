#include <bits/stdc++.h>
#pragma GCC optimize("-O2")
using namespace std;
const int N = 2e5 + 5, MOD = 1e9 + 7;
const long double EPS = 1e-9;
long long binpow(long long a, long long b) {
  long long m = MOD;
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
long long modInverse(long long a, long long m = MOD) {
  long long m0 = m;
  long long y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long q = a / m;
    long long t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
int n;
vector<vector<int>> g;
vector<long long> nums;
vector<long long> st;
void dfs(int at, int p) {
  nums[at]--;
  vector<long long> subs;
  for (auto to : g[at]) {
    if (to == p) continue;
    dfs(to, at);
    subs.push_back(st[to]);
  }
  sort(subs.begin(), subs.end(), greater<int>());
  long long now = 1;
  long long mx = nums[at];
  for (long long i = 0; i < min(mx, (long long)subs.size()); i++) {
    now += subs[i] + 1;
    nums[at]--;
  }
  if (nums[at] > 0) {
    long long sum = 0;
    for (auto to : g[at]) {
      if (to == p) continue;
      sum += nums[to];
    }
    now += min(nums[at], sum);
    nums[at] -= min(nums[at], sum);
  }
  st[at] = now;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  g.resize(n + 5);
  nums.resize(n + 5);
  st.resize(n + 5);
  for (int i = 0; i < n; ++i) cin >> nums[i + 1];
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int root;
  cin >> root;
  nums[root]++;
  dfs(root, 0);
  cout << st[root] - 1;
  return 0;
}
