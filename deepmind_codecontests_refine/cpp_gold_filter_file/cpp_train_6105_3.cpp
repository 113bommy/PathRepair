#include <bits/stdc++.h>
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n >> b) & 1; }
inline void set_bit(int& n, int b) { n |= two(b); }
inline void unset_bit(int& n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) {
  int res = 0;
  while (n && ++res) n -= n & (-n);
  return res;
}
long long int gcd(long long int a, long long int b) {
  return (a ? gcd(b % a, a) : b);
}
long long int modPow(long long int a, long long int b, long long int MOD) {
  long long int x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x * y) % MOD;
    }
    b /= 2;
    y = (y * y) % MOD;
  }
  return x;
}
long long int modInverse(long long int a, long long int p) {
  return modPow(a, p - 2, p);
}
using namespace std;
int dp[101][101][101];
vector<pair<int, int> > adj[101];
int solve(int v, int u, int ch) {
  if (dp[v][u][ch] != -1) return dp[v][u][ch];
  int ans = 0;
  for (auto x : adj[v]) {
    if (x.second >= ch) ans |= !solve(u, x.first, x.second);
  }
  return (dp[v][u][ch] = ans);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  memset(dp, -1, sizeof(dp));
  int n, m, u, v;
  char ch;
  cin >> n >> m;
  for (auto i = (1); i <= (m); i++) {
    cin >> u >> v >> ch;
    adj[u].push_back({v, ch - 'a'});
  }
  for (auto i = (1); i <= (n); i++) {
    for (auto j = (1); j <= (n); j++) {
      if (solve(i, j, 0))
        cout << "A";
      else
        cout << "B";
    }
    cout << endl;
  }
}
