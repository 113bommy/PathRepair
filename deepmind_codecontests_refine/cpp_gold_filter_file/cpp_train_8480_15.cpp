#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1000000000000000000;
long long mod = 1000000000;
long double pi = 3.141592653589793238;
void pls() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long mul_mod(long long a, long long b, long long m) {
  long long x = 0, y = a;
  while (b > 0) {
    if (b & 1) {
      x = (x + y) % m;
    }
    y = (y + y) % m;
    b >>= 1;
  }
  return x;
}
inline long long modu(long long val, long long modul) {
  return (val % modul + modul) % modul;
}
inline int madd(int x, int y) { return (x % mod + y % mod) % mod; }
inline int msub(int x, int y) { return (mod + x % mod - y % mod) % mod; }
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long powmod(long long a, long long mod, long long p) {
  if (p == 0) return 1;
  long long res;
  long long x = powmod(a, mod, p / 2);
  res = x;
  if (p & 1) x = mul_mod(x, a, mod);
  return mul_mod(x, res, mod);
}
long long exp(long long a, long long p) {
  if (p == 0) return 1;
  long long res;
  long long x = exp(a, p / 2);
  res = x;
  if (p & 1) x = (x * a);
  return (x * res);
}
long long sqt(long long x) {
  long long l = 1LL;
  long long r = x;
  long long res;
  while (l <= r) {
    long long mid = l + (r - l) / 2;
    if (mid * mid <= x) {
      res = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  return res;
}
bool isprime(long long n) {
  for (int i = 2; i <= sqt(n); i++)
    if (n % i == 0) return 0;
  return 1;
}
vector<int> soe(long long upto) {
  vector<bool> prime(upto + 1, 0);
  prime[1] = 1;
  prime[0] = 1;
  for (int i = 2; i <= sqt(upto); i++) {
    if (!prime[i]) {
      for (int j = 2 * i; j <= upto; j += i) prime[j] = 1;
    }
  }
  vector<int> res;
  res.push_back(2);
  for (int i = 3; i < prime.size(); i += 2) {
    if (!prime[i]) res.push_back(i);
  }
  return res;
}
int di[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
int dj[8] = {-1, 0, 1, -1, 0, 1, -1, 1};
int ii[4] = {0, 0, -1, 1};
int jj[4] = {-1, 1, 0, 0};
long long n, d;
long long a[30001];
long long ex;
long long dp[500][30001];
long long top_down(int ix, int pre) {
  if (ix > 30000) return 0;
  if (dp[pre][ix] != -1) return dp[pre][ix];
  long long previous = d + (pre - 250);
  long long p = 0, q = 0, r = 0;
  if (previous > 0) p = top_down(ix + previous, pre);
  if (previous > 1) q = top_down(ix + previous - 1, pre - 1);
  r = top_down(ix + previous + 1, pre + 1);
  return dp[pre][ix] = a[ix] + max({p, q, r});
}
void solve() {
  cin >> n >> d;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    a[x] += 1;
  }
  memset(dp, -1, sizeof(dp));
  cout << top_down(d, 250) << endl;
}
int main() {
  pls();
  solve();
  return 0;
}
