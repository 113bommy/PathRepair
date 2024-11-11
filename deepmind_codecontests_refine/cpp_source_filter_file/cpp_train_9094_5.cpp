#include <bits/stdc++.h>
using namespace std;
void Print() { cout << endl; }
template <typename T1, typename... T>
void Print(const T1 &t1, const T &...t) {
  cout << t1 << " ";
  Print(t...);
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}
long long gcd(long long a, long long b) {
  while (b) {
    long long r = a % b;
    a = b, b = r;
  }
  return a;
}
tuple<long long, long long, long long> extend_gcd(long long a, long long b) {
  if (b == 0)
    return make_tuple(a, 1, 0);
  else {
    long long g, nx, ny;
    std::tie(g, nx, ny) = extend_gcd(b, a % b);
    return make_tuple(g, ny, nx - (a / b) * ny);
  }
}
long long fastpow(long long a, long long e, long long mod) {
  if (e == 0) return 1;
  if (e == 1) return a % mod;
  long long t = fastpow(a, e / 2, mod);
  t = t * t % mod;
  if (e & 1)
    return t * a % mod;
  else
    return t % mod;
}
const double PI = 3.14159265358979323846;
const int MOD = (int)1e9 + 7;
long long dp[64][64];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long n, t;
  cin >> n >> t;
  int bitcnt = 0;
  for (int i = 0; i < 60; ++i)
    if (t & (1ll << i)) ++bitcnt;
  if (bitcnt > 1) {
    Print(0);
    return 0;
  }
  for (int i = 0; i < 60; ++i)
    if (t & (1ll << i)) {
      t = i;
      break;
    }
  dp[0][0] = 1;
  for (int i = 1; i < 60; ++i) {
    dp[i][0] = 1;
    for (int j = 1; j < 60; ++j) dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
  }
  ++n;
  long long h = 0, ans = 0;
  int j;
  for (j = 0; j < 60 && h + (1ll << j) <= n; ++j) {
    ans += dp[j][t];
    h += (1ll << j);
  }
  --j;
  int s = 0;
  if (h + (1ll << j <= n)) {
    ans += dp[j][t];
    h += (1ll << j);
    ++s;
  }
  for (--j; j >= 0; --j)
    if (h + (1ll << j) <= n) {
      ans += (t >= s) ? dp[j][t - s] : 0;
      h += (1ll << j);
      ++s;
    }
  if (t == 0) --ans;
  Print(ans);
  return 0;
}
