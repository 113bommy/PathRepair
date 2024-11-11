#include <bits/stdc++.h>
using namespace std;
long long const INF = INT_MAX;
const long long MOD = 998244353;
const long double EPS = 3e-16;
const long long N = 5e5 + 123;
void SpeedForce() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long is_prime(long long n) {
  if (n <= 1 || n > 3 && (n % 2 == 0 || n % 3 == 0)) return 0;
  for (long long i = 5, t = 2; i * i <= n; i += t, t = 6 - t)
    if (n % i == 0) return 0;
  return 1;
}
long long binpow(long long x, long long n) {
  long long res = 1;
  while (n) {
    if (n % 2) {
      res = (res * x) % MOD;
    }
    x = (x * x) % MOD;
    n /= 2;
  }
  return res;
}
vector<int> tree[N], lvl;
void dfs(int i, int p, int lv) {
  if (tree[i].size() == 1) {
    lvl.push_back(lv);
    return;
  }
  for (int j = 0; j < tree[i].size(); j++)
    if (tree[i][j] != p) dfs(tree[i][j], i, lv + 1);
}
void solve() {
  int n;
  cin >> n;
  for (int i = 1, u, v; i < n; i++) {
    cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  int ans = 0;
  for (int i = 0, cnt; i < tree[1].size(); i++) {
    dfs(tree[1][i], 1, 1);
    cnt = 0;
    sort(lvl.begin(), lvl.end());
    for (int j = 0; j < lvl.size(); j++) cnt = max(cnt + 1, lvl[j]);
    ans = max(cnt, ans);
    lvl.clear();
  }
  cout << ans << '\n';
}
int main() {
  SpeedForce();
  int T = 1;
  while (T--) {
    solve();
  }
}
