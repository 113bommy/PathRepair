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
int fx[] = {0, +1, 0, -1};
int fy[] = {-1, 0, +1, 0};
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
inline bool isInside(pair<int, int> p, long long n, long long m) {
  return (p.first >= 0 && p.first < n && p.second >= 0 && p.second < m);
}
inline bool isInside(pair<int, int> p, long long n) {
  return (p.first >= 0 && p.first < n && p.second >= 0 && p.second < n);
}
inline bool isSquare(long long x) {
  long long s = sqrt(x);
  return (s * s == x);
}
inline bool isFib(long long x) {
  return isSquare(5 * x * x + 4) || isSquare(5 * x * x - 4);
}
inline bool isPowerOfTwo(long long x) {
  return ((1LL << (long long)log2(x)) == x);
}
inline long long gcd(long long a, long long b) {
  if (b > a) swap(a, b);
  if (b == 0) return a;
  return gcd(b, a % b);
}
inline long long lcm(long long a, long long b) { return (a / (b * gcd(a, b))); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long l, r, k;
  cin >> l >> r >> k;
  vector<long long> ans;
  for (long long i = 1; i <= r; i *= k) {
    ans.push_back(i);
    if (i > r / k) break;
  }
  int cnt = 0;
  for (int i = 0; i < ans.size(); i++) {
    if (ans[i] > r) break;
    if (ans[i] >= l) {
      if (cnt > 0) cout << " ";
      cout << ans[i];
      cnt++;
    }
  }
  if (cnt > 0)
    cout << '\n';
  else
    cout << -1 << '\n';
}
