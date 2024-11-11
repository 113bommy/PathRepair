#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
inline int lb(int x) { return x & -x; }
long long qpow(long long base, int n) {
  if (base == 0) return 0;
  long long ans = 1;
  while (n) {
    if (n & 1) ans *= base;
    n >>= 1;
    base *= base;
  }
  return ans;
}
int n, m;
long long a[maxn][9];
long long lo = 0, hi = 1e10;
int x, y;
int ve[(1 << 9) - 1], pos[(1 << 9) - 1];
bool solve(long long v) {
  memset(ve, 0, sizeof(ve));
  memset(pos, 0, sizeof(pos));
  for (int i = (1); i <= (n); ++i) {
    int tmp = 0;
    for (int j = (1); j <= (m); ++j)
      if (v <= a[i][j]) tmp |= (1 << (j - 1));
    ve[tmp] = 1;
    pos[tmp] = i;
  }
  int sum = (1 << (m)) - 1;
  for (int i = (0); i <= (sum); ++i) {
    if (!pos[i]) continue;
    for (int j = (i); j <= (sum); ++j)
      if (pos[j] && (i | j) == sum) {
        x = pos[i];
        y = pos[j];
        return true;
      }
  }
  return false;
}
int main() {
  cin >> n >> m;
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (m); ++j) cin >> a[i][j];
  while (lo < hi) {
    long long mi = (lo + hi) >> 1;
    if (solve(mi))
      lo = mi + 1;
    else
      hi = mi;
  }
  if (x > y) swap(x, y);
  cout << x << ' ' << y << '\n';
}
