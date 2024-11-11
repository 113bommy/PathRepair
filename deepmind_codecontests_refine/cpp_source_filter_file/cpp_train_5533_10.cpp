#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const int MOD = 1e9 + 7;
int m;
int rev[N];
int dp[N];
vector<int> primes[N];
vector<int> d[N];
int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
void mult(int &a, int b) { a = (1ll * a * b) % MOD; }
void add(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}
int product(int a, int b) { return (1ll * a * b) % MOD; }
int power(int b, int p) {
  int res = 1;
  while (p) {
    if (p & 1) mult(res, b);
    mult(b, b);
    p /= 2;
  }
  return res;
}
void calc() {
  for (int i = 1; i <= m; i++) rev[i] = power(i, MOD - 2);
  for (int i = 2; i < N; i++) {
    if (primes[i].size() > 0) continue;
    for (int j = i; j < N; j++) primes[j].push_back(i);
  }
  for (int i = 1; i <= m; i++) {
    for (int j = i; j <= m; j += i) d[j].push_back(i);
  }
}
int fstup(int m, int x, int g) {
  int res = 0;
  for (int i = 1; i <= m; i++) {
    if (gcd(x, i) == g) res++;
  }
  return res;
}
int f(int m, int x, int g) {
  x /= g;
  m /= g;
  int n = primes[x].size();
  int res = 0;
  for (int mask = 0; mask < (1 << n); mask++) {
    int cnt = 0;
    int val = 1;
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) {
        cnt++;
        val *= primes[x][i];
      }
    }
    if (cnt & 1)
      res -= m / val;
    else
      res += m / val;
  }
  return res;
}
void solve() {
  dp[1] = 0;
  for (int i = 2; i <= m; i++) {
    dp[i] = 0;
    int cnt = 0;
    for (int j = 0; j < d[i].size(); j++) {
      if (d[i][j] != i)
        add(dp[i], product(f(m, i, d[i][j]), dp[d[i][j]]));
      else
        cnt = f(m, i, d[i][j]);
    }
    mult(dp[i], rev[m - cnt]);
    add(dp[i], product(m, rev[m - cnt]));
  }
}
int main() {
  cin >> m;
  calc();
  int ans = 0;
  solve();
  for (int i = 1; i <= m; i++) add(ans, product(1 + dp[i], rev[m]));
  cout << ans;
}
