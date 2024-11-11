#include <bits/stdc++.h>
const double pi = acos(-1.0);
using namespace std;
inline long long MAX2(long long a, long long b) {
  return (a) > (b) ? (a) : (b);
}
inline long long MAX3(long long a, long long b, long long c) {
  return (a) > (b) ? ((a) > (c) ? (a) : (c)) : ((b) > (c) ? (b) : (c));
}
inline long long MIN2(long long a, long long b) {
  return (a) < (b) ? (a) : (b);
}
inline long long MIN3(long long a, long long b, long long c) {
  return (a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c));
}
const int mod = 1e9 + 7;
int64_t extGcd(int64_t a, int64_t b, int64_t& x, int64_t& y) {
  if (!a) {
    x = 0;
    y = 1;
    return b;
  }
  int64_t x1, y1;
  int64_t d = extGcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
inline long long addmod(long long a, long long b) {
  a = a % mod + b % mod;
  if (a > mod) a %= mod;
  return a;
}
inline long long submod(long long a, long long b) {
  a = a % mod - b % mod;
  if (a < 0) a += mod;
  return a;
}
inline long long mulmod(long long a, long long b) {
  return (a % mod * b % mod) % mod;
}
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
inline long long exp(long long a, long long b) {
  if (a == 0) return 0ll;
  long long r = 1LL;
  while (b > 0) {
    if (b & 1) {
      r = r * (a % mod);
      r = (r + mod) % mod;
    }
    b /= 2;
    a = (a % mod) * (a % mod);
    a = (a + mod) % mod;
  }
  return (r + mod) % mod;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  if (a == 0) return b;
  return gcd(b, a % b);
}
unsigned long int setbits(long long n) {
  unsigned long int count = 0;
  while (n) {
    n &= (n - 1);
    count++;
  }
  return count;
}
int main() {
  if (fopen("input.txt", "r"))
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
  ;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  long long k;
  cin >> n >> k;
  k--;
  vector<vector<long long>> g1;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  if (k < 0) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
  }
  vector<long long> row1(n);
  row1[0] = 1;
  for (int i = 1; i < n; i++) {
    long long dem = exp(i, mod - 2);
    long long po = mulmod(k + i, dem);
    row1[i] = mulmod(row1[i - 1], po);
  }
  g1.push_back(row1);
  int prev = 1;
  for (int i = 1; i < n; i++) {
    vector<long long> curr;
    for (int j = 0; j < i; j++) curr.push_back(0);
    for (int j = prev; curr.size() < n; j++) curr.push_back(g1[i - 1][j]);
    prev++;
    g1.push_back(curr);
  }
  vector<long long> ans(n, 0);
  for (int i = 0; i < g1.size(); i++) {
    for (int j = 0; j < g1[i].size(); j++) {
      ans[j] = addmod(ans[j], mulmod(a[i], g1[i][j]));
    }
  }
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  return 0;
}
