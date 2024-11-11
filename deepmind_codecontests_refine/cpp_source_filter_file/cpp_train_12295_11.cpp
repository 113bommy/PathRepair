#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
const int mod = (int)1e9 + 7;
void smxl(long long &a, long long b) {
  if (a < b) a = b;
}
void smnl(long long &a, long long b) {
  if (a > b) a = b;
}
void adsl(long long &a, long long b) {
  a += b;
  if (a >= mod) a -= mod;
}
void misl(long long &a, long long b) {
  a -= b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}
void smx(long long &a, long long b) {
  if (a < b) a = b;
}
void smn(long long &a, long long b) {
  if (a > b) a = b;
}
void ads(long long &a, long long b) {
  a += b;
  if (a >= mod) a -= mod;
}
void mis(long long &a, long long b) {
  a -= b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}
long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b)); }
long long egcd(long long a, long long b, long long &x, long long &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  long long x1, y1;
  long long d = egcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
long long mbinp(long long a, long long b) {
  a %= mod;
  if (b == 0) return 1;
  long long ans = mbinp(a, b / 2);
  long long tmp = (ans * ans) % mod;
  if (b % 2) return ((tmp * a) % mod);
  return ((tmp) % mod);
}
long long binp(long long a, long long b) {
  if (b == 0) return 1;
  long long ans = binp(a, b / 2);
  long long tmp = (ans * ans);
  if (b % 2) return ((tmp * a));
  return ((tmp));
}
long long C(int n, int m) {
  long long ret = 1;
  for (int i = 1; i <= m; i++) {
    ret *= (n - i + 1);
    ret /= i;
  }
  return ret;
}
void solve() {
  long long x, y;
  cin >> x >> y;
  cout << (int)ceil((long double)(y) / x) << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  t = 1;
  while (t--) solve();
}
