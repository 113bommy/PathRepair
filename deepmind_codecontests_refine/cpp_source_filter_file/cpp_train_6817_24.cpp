#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-7;
const string alpha = "abcdefghijklmnopqrstuvwxyz";
int d8x[8] = {+1, +1, +1, 0, 0, -1, -1, -1};
int d8y[8] = {+1, 0, -1, +1, -1, +1, 0, -1};
int d4x[4] = {1, 0, 0, -1};
int d4y[4] = {0, -1, 1, 0};
long long power(long long x, long long y) {
  long long fk = 1;
  x = x;
  while (y > 0) {
    if (y & 1) fk = (fk * x);
    y = y >> 1;
    x = (x * x);
  }
  return fk;
}
long long sqr(long long x) { return x * x; }
template <typename T>
T gcd(T a, T b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
template <class T>
inline void chmax(T &x, T y) {
  x = max((x), (y));
}
template <class T>
inline void chmin(T &x, T y) {
  x = min((x), (y));
}
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
template <typename T>
T powm(T a, T b, long long m) {
  T cnt = 1;
  while (b > 0) {
    if (b % 2 == 1) cnt = (cnt * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return cnt % m;
}
long long ncr(long long n, long long r) {
  long long fk = 1;
  if (r > n) return 0;
  if (r > n - r) r = n - r;
  for (long long i = 0; i < r; i++) {
    fk *= (n - i);
    fk /= (i + 1);
  }
  return fk;
}
const int MOD = 998244353;
const int N = 102;
int r, p, s;
long double cache[N][N][N];
bool vis[N][N][N];
long double dp(int a, int b, int c) {
  if (a < 0 or b < 0 or c < 0) return 0;
  if (a == 0) return 0;
  if (a > 0 and b + c == 0) return 1.0;
  long double &ans = cache[a][b][c];
  if (vis[a][b][c]) return cache[a][b][c];
  ans = 0;
  vis[a][b][c] = 1;
  long double tot = a * b + b * c + a * c;
  ans = (a * b * dp(a, b - 1, c) + a * c * dp(a - 1, b, c) +
         b * c * dp(a, b, c - 1)) /
        tot;
  return ans;
}
void solve() {
  cin >> r >> p >> s;
  cout << fixed << setprecision(20);
  cout << dp(r, s, p) << ' ' << dp(s, p, r) << ' ' << dp(p, r, s);
}
int32_t main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(cin.failbit);
  int tc = 1;
  for (int i = 1; i <= tc; ++i) {
    solve();
  }
  return 0;
}
