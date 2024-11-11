#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const int INF = (int)1e9;
const long long LINF = (long long)1e18;
const long double PI = acos((long double)-1);
const long double EPS = 1e-9;
long long gcd(long long a, long long b) {
  if (a < b) swap(a, b);
  long long r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long fpow(long long n, long long k, long long p = MOD) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
template <class T>
void setmin(T& a, T val) {
  if (a > val) a = val;
}
template <class T>
void setmax(T& a, T val) {
  if (a < val) a = val;
}
void addmod(int& a, int val, int p = MOD) {
  if ((a = (a + val)) >= p) a -= p;
}
void submod(int& a, int val, int p = MOD) {
  if ((a = (a - val)) < 0) a += p;
}
int mult(int a, int b, int p = MOD) { return (long long)a * b % p; }
int inv(int a, int p = MOD) { return fpow(a, p - 2, p); }
string s, t;
long long n, m;
vector<vector<long long>> dp;
long long recurse(int curCharS, int curFrontCharT) {
  if (curCharS == -1) return 1;
  if (dp[curCharS][curFrontCharT] != -1) return dp[curCharS][curFrontCharT];
  if (curFrontCharT == m)
    return dp[curCharS][curFrontCharT] =
               2 * recurse(curCharS - 1, curFrontCharT);
  long long ways = 0;
  if (s[curCharS] == t[curFrontCharT])
    ways = (ways + recurse(curCharS - 1, curFrontCharT + 1)) % MOD;
  if (curFrontCharT + curCharS >= m ||
      s[curCharS] == t[curFrontCharT + curCharS])
    ways = (ways + recurse(curCharS - 1, curFrontCharT)) % MOD;
  return dp[curCharS][curFrontCharT] = ways;
}
void solve() {
  cin >> s >> t;
  n = s.size();
  m = t.size();
  dp = vector<vector<long long>>(n, vector<long long>(m + 1, -1));
  long long ways = 0;
  for (int i = (m - 1); i < (n); i++) ways = (ways + recurse(i, 0)) % MOD;
  cout << ways << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
