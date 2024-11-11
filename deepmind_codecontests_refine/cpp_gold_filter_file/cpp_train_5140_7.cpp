#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const long long infLL = 90000000000000000;
inline bool checkBit(long long n, int i) { return n & (1LL << i); }
inline long long setBit(long long n, int i) {
  return n | (1LL << i);
  ;
}
inline long long resetBit(long long n, int i) { return n & (~(1LL << i)); }
int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
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
long long n, x, y, c;
long long topRight(long long val) {
  long long maxLen = min(n - y, val), ret = 0;
  long long lengthOfExceed = min(val - maxLen, x + 1);
  ret += lengthOfExceed * maxLen;
  long long remLength = min(maxLen, x - lengthOfExceed + 1);
  long long beg = maxLen, fin = beg - remLength + 1;
  ;
  ret += fin * remLength + (remLength * (remLength - 1)) / 2;
  return ret;
}
long long topLeft(long long val) {
  long long maxLen = min(val, y + 1), ret = 0;
  long long lengthOfExceed = min(val - maxLen, x + 1);
  ret += lengthOfExceed * maxLen;
  long long remLength = min(maxLen, x - lengthOfExceed + 1);
  long long fin = maxLen - remLength + 1;
  ret += fin * remLength + (remLength * (remLength - 1)) / 2;
  return ret;
}
long long botRight(long long val) {
  long long maxLen = min(n - y, val), ret = 0;
  long long lengthOfExceed = min(val - maxLen, n - x);
  ret += lengthOfExceed * maxLen;
  long long remLength = min(maxLen, n - x - lengthOfExceed);
  long long fin = maxLen - remLength + 1;
  ret += fin * remLength + (remLength * (remLength - 1)) / 2;
  return ret;
}
long long botLeft(long long val) {
  long long maxLen = min(val, y + 1), ret = 0;
  long long lengthOfExceed = min(val - maxLen, n - x);
  ret += lengthOfExceed * maxLen;
  long long remLength = min(maxLen, n - x - lengthOfExceed);
  long long fin = maxLen - remLength + 1;
  ret += fin * remLength + (remLength * (remLength - 1)) / 2;
  return ret;
}
bool valid(long long val) {
  long long tot = topRight(val) + topLeft(val) + botLeft(val) + botRight(val);
  long long maxUp = min(val, x + 1);
  long long maxDown = min(val, n - y);
  long long maxRight = min(val, n - x);
  long long maxLeft = min(val, y + 1);
  tot -= maxUp + maxDown + maxRight + maxLeft - 1;
  ;
  return tot >= c;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> x >> y >> c;
  --x;
  --y;
  long long low = 0, high = n * n;
  while (low < high) {
    long long mid = (low + high) / 2;
    if (valid(mid))
      high = mid;
    else
      low = mid + 1;
  }
  cout << max(low - 1, 0LL);
  return 0;
}
