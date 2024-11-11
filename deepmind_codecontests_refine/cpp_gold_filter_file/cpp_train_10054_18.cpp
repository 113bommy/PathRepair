#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i32 = int32_t;
using ui32 = uint32_t;
using i64 = int64_t;
using ui64 = uint64_t;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
template <typename T>
T gcd(T a, T b) {
  return b == 0 ? a : gcd(b, a % b);
}
template <typename T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
static int constexpr dbg = 0;
int constexpr NM = 1.1e5;
int n;
ll a[NM][4], f[NM][4], g[NM][4];
int main(int argc, char *argv[]) {
  if (!dbg) {
    std::ios::sync_with_stdio(false);
  }
  cin >> n;
  for (int i = 1; i <= (int)(n); ++i) cin >> a[i][1];
  for (int i = 1; i <= (int)(n); ++i) cin >> a[i][2];
  for (int i = 1; i <= (int)(n); ++i) cin >> a[i][3];
  g[1][1] = a[1][1];
  g[1][2] = a[1][2];
  g[1][3] = a[1][3];
  f[1][1] = a[1][1];
  f[1][2] = a[1][1] + a[1][2];
  f[1][3] = a[1][1] + a[1][2] + a[1][3];
  for (int i = 2; i <= n; ++i) {
    f[i][1] = g[i][1] = f[i - 1][1] + a[i][1];
    f[i][2] = g[i][2] = f[i - 1][2] + a[i][2];
    f[i][3] = g[i][3] = f[i - 1][3] + a[i][3];
    f[i][1] = max(f[i][1], g[i][2] + a[i][1]);
    f[i][1] = max(f[i][1], g[i][3] + a[i][2] + a[i][1]);
    f[i][2] = max(f[i][2], g[i][1] + a[i][2]);
    f[i][2] = max(f[i][2], g[i][3] + a[i][2]);
    f[i][3] = max(f[i][3], g[i][2] + a[i][3]);
    f[i][3] = max(f[i][3], g[i][1] + a[i][2] + a[i][3]);
    f[i][1] = max(f[i][1], g[i - 1][3] + a[i][3] + a[i][2] + a[i - 1][2] +
                               a[i - 1][1] + a[i][1]);
    f[i][3] = max(f[i][3], g[i - 1][1] + a[i][1] + a[i][2] + a[i - 1][2] +
                               a[i - 1][3] + a[i][3]);
  }
  cout << f[n][3] << endl;
  return 0;
}
