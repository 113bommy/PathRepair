#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const long long infLL = 9000000000000000000;
inline bool checkBit(long long n, int i) { return n & (1LL << i); }
inline long long setBit(long long n, int i) {
  return n | (1LL << i);
  ;
}
inline long long resetBit(long long n, int i) { return n & (~(1LL << i)); }
int dx[] = {+1, 0, -1, 0, +1, +1, -1, -1};
int dy[] = {0, +1, 0, -1, +1, -1, +1, -1};
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
inline bool isLeapYear(long long year) {
  return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
inline void normal(long long &a) {
  a %= 1000000007;
  (a < 0) && (a += 1000000007);
}
inline long long modMul(long long a, long long b) {
  a %= 1000000007, b %= 1000000007;
  normal(a), normal(b);
  return (a * b) % 1000000007;
}
inline long long modAdd(long long a, long long b) {
  a %= 1000000007, b %= 1000000007;
  normal(a), normal(b);
  return (a + b) % 1000000007;
}
inline long long modSub(long long a, long long b) {
  a %= 1000000007, b %= 1000000007;
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
inline long long modInverse(long long a) { return modPow(a, 1000000007 - 2); }
inline long long modDiv(long long a, long long b) {
  return modMul(a, modInverse(b));
}
const int MX = 101000;
int fact[MX], dp[MX];
pair<int, int> a[MX];
int op(int x, int y) { return modDiv(fact[x + y], modMul(fact[x], fact[y])); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  fact[0] = 1;
  for (int i = 1; i < MX; ++i) {
    fact[i] = modMul(fact[i - 1], i);
  }
  int h, w, n;
  cin >> h >> w >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
    --a[i].first;
    --a[i].second;
  }
  a[n++] = pair<int, int>(h - 1, w - 1);
  sort(a, a + n);
  for (int i = 0; i < n; ++i) {
    dp[i] = op(a[i].first, a[i].second);
    ;
    for (int j = 0; j < i; ++j) {
      if (a[j].first <= a[i].first && a[j].second <= a[i].second)
        dp[i] = modSub(dp[i], modMul(dp[j], op(a[i].first - a[j].first,
                                               a[i].second - a[j].second)));
    };
  }
  cout << dp[n - 1];
  return 0;
}
