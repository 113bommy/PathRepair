#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:134217728")
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
long long fact(long long n) {
  long long res = 1;
  for (int i = 1; i <= n; i++) res *= i;
  return res;
}
long long forin(long long deg) { return (1LL << (2 * deg)); }
int getMax(int a, int b) {
  int d = a - b;
  int k = (d >> 31) & 0x1;
  int mx = a - k * d;
  return mx;
}
int getMin(int a, int b) { return a + b - getMax(a, b); }
int main() {
  long long x;
  cin >> x;
  x -= 180;
  x %= 360;
  x += 360;
  x %= 360;
  int df = getMin(360 - x, x);
  x += 90;
  x %= 360;
  df = getMin(df, getMin(360 - x, x));
  x += 90;
  x %= 360;
  df = getMin(df, getMin(360 - x, x));
  x += 90;
  x %= 360;
  df = getMin(df, getMin(360 - x, x));
  x += 90;
  x %= 360;
  int ans = 149;
  int curDf;
  curDf = getMin(360 - x, x);
  ans = getMin(ans, 0 + 149 * getMax(df - curDf, curDf - df));
  x += 90;
  x %= 360;
  curDf = getMin(360 - x, x);
  ans = getMin(ans, 1 + 149 * getMax(df - curDf, curDf - df));
  x += 90;
  x %= 360;
  curDf = getMin(360 - x, x);
  ans = getMin(ans, 2 + 149 * getMax(df - curDf, curDf - df));
  x += 90;
  x %= 360;
  curDf = getMin(360 - x, x);
  ans = getMin(ans, 3 + 149 * getMax(df - curDf, curDf - df));
  cout << ans;
  return 0;
}
