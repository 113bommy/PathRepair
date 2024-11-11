#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2")
const long long MOD = 1e9 + 7;
const double PI = acos(-1);
long long add(long long x, long long y) {
  long long res = x + y;
  return (res >= MOD ? res - MOD : res);
}
long long mul(long long x, long long y) {
  long long res = x * y;
  return (res >= MOD ? res % MOD : res);
}
long long sub(long long x, long long y) {
  long long res = x - y;
  return (res < 0 ? res + MOD : res);
}
long long power(long long a, long long b, long long m = MOD) {
  long long ans = 1;
  a = a % m;
  while (b > 0) {
    if (b & 1) ans = (1ll * a * ans) % m;
    b >>= 1;
    a = (1ll * a * a) % m;
  }
  return ans;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long x, long long y) { return (x * y) / gcd(x, y); }
bool isprime(long long n) {
  if (n < 2) return 0;
  long long i = 2;
  while (i * i <= n) {
    if (n % i == 0) return 0;
    i++;
  }
  return 1;
}
bool isPowerOfTwo(long long x) { return x && (!(x & (x - 1))); }
double distform(long long x, long long y, long long z, long long w) {
  return sqrt(1. * pow(x - z, 2) + 1. * pow(y - w, 2));
}
long long dx[] = {-1, 0, 1, 0};
long long dy[] = {0, 1, 0, -1};
const long long MAXN = 2e5 + 10;
const long long inf = 1e18;
template <typename T, typename T1>
T amax(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
long long intlog(double base, double x) {
  return (long long)(log(x) / log(base));
}
void read(vector<long long> &a) {
  for (long long i = 0; i < ((long long)(a).size()); ++i) cin >> a[i];
}
bool cmp(pair<long long, pair<long long, long long>> p1,
         pair<long long, pair<long long, long long>> p2) {
  return p1.second.first < p1.second.second;
}
long long n;
vector<long long> rnk(1e5 + 1);
vector<long long> par(1e5 + 1);
void reset() {
  rnk.resize(n + 1);
  par.resize(n + 1);
  for (long long i = 1; i <= n; i++) par[i] = i, rnk[i] = 1;
}
long long getpar(long long u) {
  if (u == par[u]) return u;
  return par[u] = getpar(par[u]);
}
void funion(long long a, long long b) {
  long long par1 = getpar(a), par2 = getpar(b);
  if (par1 == par2) return;
  if (rnk[par2] > rnk[par1]) swap(par1, par2);
  rnk[par1] += rnk[par2];
  par[par2] = par[par1];
}
void solve() {
  cin >> n;
  vector<long long> v(n + 1);
  for (long long i = 1; i <= n; i++) cin >> v[i];
  for (long long i = 1; i <= n; i++) {
    rnk[i] = 1;
    par[i] = i;
  }
  for (long long i = 1; i <= n; i++) funion(i, v[i]);
  for (long long i = 1; i <= n; i++) cout << rnk[getpar(par[i])] << " ";
  cout << endl;
}
int32_t main() {
  long long tt;
  cin >> tt;
  while (tt--) {
    solve();
  };
}
