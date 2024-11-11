#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const long long int mod = 1e8;
long long int powmod(long long int x, long long int y) {
  long long int t;
  for (t = 1; y; y >>= 1, x = x * x % mod)
    if (y & 1) t = t * x % mod;
  return t;
}
long long int gcd(long long int x, long long int y) {
  return y ? gcd(y, x % y) : x;
}
long long int lcm(long long int x, long long int y) {
  return x * (y / gcd(x, y));
}
long long int modd(long long int a) { return (a % mod + mod) % mod; }
double findMod(double a, double b) {
  double mods;
  if (a < 0)
    mods = -a;
  else
    mods = a;
  if (b < 0) b = -b;
  while (mods >= b) mods = mods - b;
  if (a < 0) return -mods;
  return mods;
}
long long int add(long long int a, long long int b) {
  return modd(modd(a) + modd(b));
}
long long int mul(long long int a, long long int b) {
  return modd(modd(a) * modd(b));
}
int smask(int i, int pos) { return (i | (1 << pos)); }
int clmask(int i, int pos) { return (i & (~(1 << pos))); }
bool chmask(int i, int pos) { return (i & (1 << pos)) != 0; }
double cordist(pair<double, double> a, pair<double, double> b) {
  return sqrt(((a.first - b.first) * (a.first - b.first)) +
              ((a.second - b.second) * (a.second - b.second)));
}
long long binpow(long long a, long long b) {
  if (b == 0) return 1;
  long long res = binpow(a, b / 2);
  if (b % 2)
    return mul(mul(res, res), a);
  else
    return mul(res, res);
}
long long int n, m, q, r, i, j;
vector<long long int> arr;
void solve() {
  long long int k, b, t;
  cin >> k >> b >> n >> t;
  long long int prev = 1;
  long long int sec = 0;
  while (prev <= t) {
    prev = (k * prev) + b;
    sec++;
  }
  cout << max(0LL, n - sec + 1) << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int k = 1;
  while (k--) {
    solve();
  }
  return 0;
}
