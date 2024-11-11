#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using vi = vector<int>;
using vll = vector<long long int>;
using vd = vector<double>;
using vvi = vector<vi>;
int ctoi(char c) { return c - '0'; }
int slen(string s) { return s.length(); }
int vsize(vi a) { return (int)a.size(); }
int in() {
  int x;
  cin >> x;
  return x;
}
const long long int mod = 998244353;
const int MOD = 1e9 + 7;
const int sz = 2e5 + 5;
vector<int> fact(sz);
int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }
void pre() {
  fact[0] = 1LL;
  for (int i = 1; i < sz; i++) {
    fact[i] = fact[i - 1] * i;
    fact[i] %= MOD;
  }
}
int power(int x, int y) {
  int ans = 1LL;
  x %= MOD;
  while (y) {
    if (y & 1) {
      ans *= x;
      ans %= MOD;
    }
    x *= x;
    x %= MOD;
    y >>= 1;
  }
  return ans;
}
int ferm_inv(int n) { return power(n, MOD - 2); }
int nCr(int x, int y) {
  if (x < 0 || y > x) {
    return 0;
  }
  int val = fact[x];
  int div = fact[y] * fact[x - y];
  div %= MOD;
  return (val * ferm_inv(div)) % MOD;
}
unsigned long long power(unsigned long long x, int y, int p) {
  unsigned long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
unsigned long long modInverse(unsigned long long n, int p) {
  return power(n, p - 2, p);
}
int cntdigits(long long int x) {
  int cnt{0};
  while (x) {
    cnt++;
    x /= 10;
  }
  return cnt;
}
void solve() {
  long long int n;
  cin >> n;
  long long int ans = 0;
  for (int i = 1; i <= n; ++i) {
    long long int x;
    cin >> x;
    long long int res = 0;
    long long int mul = 1;
    while (x > 0) {
      long long int rem = x % 10;
      res += (long long int)rem * 11 * mul;
      x /= 10;
      mul *= 100;
      mul %= mod;
    }
    ans = (ans + res) % mod;
  }
  cout << (ans * n) % mod << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t = 1;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
