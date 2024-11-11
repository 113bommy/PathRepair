#include <bits/stdc++.h>
using namespace std;
inline long long int ABS(long long int a) {
  if (a < 0) return (-a);
  return a;
}
inline long long int min(long long int a, long long int b, long long int c) {
  return min(a, min(b, c));
}
inline long long int max(long long int a, long long int b, long long int c) {
  return max(a, max(b, c));
}
inline long long int powmod(long long int x, long long int n,
                            long long int _mod) {
  long long int res = 1;
  while (n) {
    if (n & 1) res = (res * x) % _mod;
    x = (x * x) % _mod;
    n >>= 1;
  }
  return res;
}
inline long long int gcd(long long int a, long long int b) {
  long long int t;
  while (b) {
    a = a % b;
    t = a;
    a = b;
    b = t;
  }
  return a;
}
inline long long int lcm(long long int a, long long int b) {
  return a / (gcd(a, b) * b);
}
inline int bitCount(unsigned int i) { return __builtin_popcount(i); }
inline void cinarr(long long int x[], long long int n) {
  for (long long int i = 0; i < (n); ++i) cin >> (x[i]);
}
inline void cinvec(vector<long long int> &arr, long long int n) {
  for (long long int i = 0; i < (n); ++i) {
    long long int x;
    cin >> (x);
    arr.push_back(x);
  };
}
const int v5 = 100000;
const int v9 = 1000000000;
const int v6 = 1000000;
long long int n, m = 0, k = 0, c = 0, h, w, ans = 0, l = 0;
long long int a[v6 + 3], inv[v6 + 3], fct[v6 + 3];
vector<pair<long long int, long long int> > v;
string s;
const int MOD = 1e9 + 7;
const int SIZE = 1e6 + 2;
long long int nCr(long long int x, long long int y) {
  if (y < 0 || y > x) return 0;
  return (fct[x] * inv[y] % MOD) * inv[x - y] % MOD;
}
void build() {
  fct[0] = 1;
  for (long long int i = (1); i < (SIZE); ++i) fct[i] = (fct[i - 1] * i) % MOD;
  inv[SIZE - 1] = powmod(fct[SIZE - 1], MOD - 2, MOD);
  for (long long int i = (SIZE - 2); i >= (0); --i)
    inv[i] = inv[i + 1] * (i + 1) % MOD;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int mod = MOD;
  build();
  cin >> h >> w >> n;
  for (long long int i = (0); i < (n); ++i) {
    long long int a, b;
    cin >> a >> b;
    v.push_back(make_pair(a, b));
  }
  v.push_back(make_pair(h, w));
  n++;
  sort(v.begin(), v.end());
  for (long long int i = (0); i < (n); ++i) {
    long long int sm = 0;
    a[i] = nCr(v[i].first + v[i].second - 2, v[i].first - 1);
    for (long long int j = (0); j < (i); ++j)
      if (v[j].first <= v[i].first && v[j].second <= v[i].second) {
        a[i] -= (nCr(v[i].first + v[i].second - v[j].first - v[j].second,
                     v[i].second - v[j].second) *
                 a[j]) %
                mod;
        while (a[i] < 0) a[i] += mod;
      }
  }
  cout << a[n - 1] << "\n";
  return 0;
}
