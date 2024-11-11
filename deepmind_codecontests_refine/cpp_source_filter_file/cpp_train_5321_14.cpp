#include <bits/stdc++.h>
using namespace std;
long long sqr(long long x) { return x * x; }
int mysqrt(long long x) {
  int l = 0, r = 1e9 + 1;
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (m * (long long)m <= x)
      l = m;
    else
      r = m;
  }
  return l;
}
mt19937 rnd(1227);
mt19937_64 rndll(12365);
long long AR = 19, BR = 13, CR = 23, XR = 228, YR = 322, MODR = 1e9 + 993;
long long myrand() {
  long long ZR = (XR * AR + YR * BR + CR) % MODR;
  XR = YR;
  YR = ZR;
  return ZR;
}
int gcd(int a, int b) { return a ? gcd(b % a, a) : b; }
int gcdex(int a, int b, int &x, int &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  int x1, y1;
  int ret = gcdex(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return ret;
}
const int Mod = 998244353;
int Bpow(int x, int y) {
  int ret = 1;
  int w = x;
  while (y) {
    if (y & 1) ret = (ret * (long long)w) % Mod;
    w = (w * (long long)w) % Mod;
    y >>= 1;
  }
  return ret;
}
int Bdiv(int x) {
  int a, b;
  gcdex(x, Mod, a, b);
  if (a < 0) a += Mod;
  return a;
}
int Bdiv(int x, int y) { return (x * (long long)Bpow(y, Mod - 2)) % Mod; }
inline int ad(int x, int y) { return x + y >= Mod ? x + y - Mod : x + y; }
inline int dif(int x, int y) { return x - y < 0 ? x - y + Mod : x - y; }
int inv(int a) {
  int b = Mod, x = 0, y = 1;
  while (a) {
    int t = b / a;
    b -= a * t;
    x -= t * y;
    swap(a, b);
    swap(x, y);
  }
  if (x < 0) x += Mod;
  return x;
}
void setmin(int &x, int y) { x = min(x, y); }
void setmax(int &x, int y) { x = max(x, y); }
void setmin(long long &x, long long y) { x = min(x, y); }
void setmax(long long &x, long long y) { x = max(x, y); }
const long long llinf = 4e18 + 100;
const long double eps = 1e-14;
const int maxn = 110, maxw = 1e6 + 100, inf = 2e9 + 100, sq = 300, X = 43,
          mod = 1e9 + 933, LG = 17;
long double dp[maxn][10 * maxn];
int n;
pair<int, int> arr[maxn];
long double st[maxn];
void upd(long double &x, long double y) {
  if (x == -1 || x > y) x = y;
}
bool le(long double x, long double y) { return x <= y; }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  st[0] = 1;
  for (int i = 1; i < maxn; i++) st[i] = (st[i - 1] * 0.9);
  int tst;
  cin >> tst;
  while (tst--) {
    double C1, T;
    cin >> n >> C1 >> T;
    for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
    sort(arr, arr + n);
    reverse(arr, arr + n);
    for (int k = 0; k <= n; k++)
      for (int j = 0; j <= 10 * n; j++) dp[k][j] = -1;
    dp[0][0] = 0;
    int mx = 0;
    for (int i = 0; i < n; i++) {
      int cs = arr[i].second, val = arr[i].first;
      for (int sz = i; sz >= 0; sz--) {
        long double v = st[sz + 1];
        for (int cost = mx; cost >= 0; cost--)
          if (dp[sz][cost] != -1)
            upd(dp[sz + 1][cost + cs], dp[sz][cost] + val / v);
      }
      mx += arr[i].second;
    }
    int ans = 0;
    for (int sz = 0; sz <= n; sz++)
      for (int cost = 0; cost <= mx; cost++)
        if (dp[sz][cost] != -1) {
          long double val = dp[sz][cost];
          if (le(val, T - 10 * sz)) setmax(ans, cost);
          long double A = C1, B = 1 + 10 * sz * C1 - C1 * T,
                      C = T - 10 * sz - val;
          if (le(1 + 10 * sz + C1, C1 * T) && le(-(B * B) / (4 * A), C))
            setmax(ans, cost);
        }
    cout << ans << '\n';
  }
}
