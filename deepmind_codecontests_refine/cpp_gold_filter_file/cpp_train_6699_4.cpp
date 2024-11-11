#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long inf = 10000000;
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
inline bool isLeapYear(long long year) {
  return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
inline void normal(long long &a) {
  a %= MOD;
  (a < 0) && (a += MOD);
}
inline long long modMul(long long a, long long b) {
  a %= MOD, b %= MOD;
  normal(a), normal(b);
  return (a * b) % MOD;
}
inline long long modAdd(long long a, long long b) {
  a %= MOD, b %= MOD;
  normal(a), normal(b);
  return (a + b) % MOD;
}
inline long long modSub(long long a, long long b) {
  a %= MOD, b %= MOD;
  normal(a), normal(b);
  a -= b;
  normal(a);
  return a;
}
inline long long modPow(long long b, long long p) {
  long long r = 1;
  while (p) {
    if (p & 1) r = modMul(r, b);
    b = modMul(b, b);
    p >>= 1;
  }
  return r;
}
inline long long modInverse(long long a) { return modPow(a, MOD - 2); }
inline long long modDiv(long long a, long long b) {
  return modMul(a, modInverse(b));
}
inline bool checkBit(long long n, int i) { return n & (1LL << i); }
inline long long setBit(long long n, int i) {
  return n | (1LL << i);
  ;
}
inline long long resetBit(long long n, int i) { return n & (~(1LL << i)); }
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
void input(long long n, const long long a[], int co = 0) {
  long long i = 1;
  for (; i <= n; i++) {
    if (co == 0)
      scanf("%lld", &a[i]);
    else
      printf("%lld ", a[i]);
  }
}
void dfs() {}
bool cmp() {}
const int N = 1e5 + 5;
int a[N], b[N], f[2 * N], bc[2 * N], n;
vector<int> rs;
int solve() {
  sort(rs.begin(), rs.end());
  rs.erase(unique(rs.begin(), rs.end()), rs.end());
  for (int i = 0; i < n; i++) {
    int fn = lower_bound(rs.begin(), rs.end(), a[i]) - rs.begin();
    int bk = lower_bound(rs.begin(), rs.end(), b[i]) - rs.begin();
    f[fn]++;
    if (fn != bk) bc[bk]++;
  }
  int ans = inf;
  n = (n + 1) / 2;
  for (int i = 0; i < int((rs).size()); i++)
    if (f[i] + bc[i] >= n) {
      ans = min(ans, max(0, n - f[i]));
    }
  return ans == inf ? -1 : ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &a[i], &b[i]);
    rs.push_back(a[i]);
    rs.push_back(b[i]);
  }
  cout << solve();
  return 0;
}
