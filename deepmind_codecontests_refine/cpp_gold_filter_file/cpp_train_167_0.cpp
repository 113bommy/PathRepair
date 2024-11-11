#include <bits/stdc++.h>
using namespace std;
void optimise() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
long long int mod = 1e9 + 7;
void normalize(long long int &a) { a = (a + mod) % mod; }
long long int modmul(long long int a, long long int b) {
  a = a % mod;
  b = b % mod;
  normalize(a);
  normalize(b);
  return (a * b) % mod;
}
long long int modadd(long long int a, long long int b) {
  a = a % mod;
  b = b % mod;
  normalize(a);
  normalize(b);
  return (a + b) % mod;
}
long long int modsub(long long int a, long long int b) {
  a = a % mod;
  b = b % mod;
  normalize(a);
  normalize(b);
  return (a - b + mod) % mod;
}
long long int me(long long int x, long long int n) {
  x %= mod;
  if (n == 0) return 1;
  long long int u = me(x, n / 2) % mod;
  u = (u * u) % mod;
  if (n % 2) u = (u * x) % mod;
  return u;
}
long long int me1(long long int x, long long int n) {
  if (n == 0) return 1;
  long long int u = me1(x, n / 2);
  u = u * u;
  if (n % 2) u = u * x;
  return u;
}
inline long long int modInv(long long int a) { return me(a, mod - 2); }
inline long long int modDiv(long long int a, long long int b) {
  return modmul(a, modInv(b));
}
long long int __gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return __gcd(b, a % b);
}
set<long long int> unvisted;
const long long int N = 2e5 + 1;
set<long long int> G[N];
long long int con = 0;
void dfs(long long int i) {
  con++;
  vector<long long int> next;
  unvisted.erase(i);
  for (auto &y : unvisted) {
    if (G[i].find(y) == G[i].end()) {
      next.push_back(y);
    }
  }
  for (auto &y : next) unvisted.erase(y);
  for (auto &y : next) dfs(y);
}
void solve() {
  long long int n;
  cin >> n;
  long long int m;
  cin >> m;
  for (long long int i = 1; i <= m; i++) {
    long long int x, y;
    cin >> x >> y;
    G[x].insert(y);
    G[y].insert(x);
  }
  for (long long int i = 1; i <= n; i++) unvisted.insert(i);
  vector<long long int> ans;
  for (long long int i = 1; i <= n; i++) {
    if (unvisted.find(i) != unvisted.end()) {
      con = 0;
      dfs(i);
      ans.push_back(con);
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << "\n";
  for (long long int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}
signed main() {
  optimise();
  long long int t;
  t = 1;
  while (t--) {
    solve();
  }
}
