#include <bits/stdc++.h>
using namespace std;
int xd[] = {1, 0, -1, 0, 1, 1, -1, -1};
int yd[] = {0, -1, 0, 1, 1, -1, 1, -1};
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
inline bool isEqual(double x, double y) {
  const double epsilon = 1e-5;
  return abs(x - y) <= epsilon * abs(x);
}
long double triarea(long long x1, long long y1, long long x2, long long y2,
                    long long x3, long long y3) {
  return (long double)abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) /
         2.0;
}
bool triinside(long x1, long y1, long x2, long y2, long x3, long y3, long x,
               long y) {
  long area1 = triarea(x1, y1, x2, y2, x3, y3);
  long area2 = triarea(x, y, x2, y2, x3, y3);
  long area3 = triarea(x1, y1, x, y, x3, y3);
  long area4 = triarea(x1, y1, x2, y2, x, y);
  if (isEqual(area1, area2 + area3 + area4)) return true;
  return false;
}
long long dist(long long x1, long long y1, long long x2, long long y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
const double pi = acos(-1.0);
long double todegree(long double radian) {
  if (radian < 0) radian += 2 * pi;
  return radian * 180 / pi;
}
long double toradian(long double degree) { return degree * pi / 180.0; }
long long poww(long long a, int b) {
  long long ret = 1;
  for (int i = 0; i < b; i++) ret *= a;
  return ret;
}
long long sumOfNumbers(long long num) {
  long long ret = 0;
  while (num) {
    ret += num % 10;
    num /= 10;
  }
  return ret;
}
unsigned long long fact(unsigned long long n) {
  unsigned long long sum = 1;
  while (n > 1) {
    sum *= n;
    n--;
  }
  return sum;
}
unsigned long long combination(unsigned long long a, unsigned long long b) {
  long long ret = 1;
  for (int i = 0; i < b; i++) ret = ret * (a - i) / (i + 1);
  return ret;
}
char s[1000055];
long dp[1000005][3][2], gg[1000005][3][2], n;
long solve(int p, int rem, bool x) {
  if (p == n) {
    if (rem == 0 && x) return 0;
    return 1e8;
  }
  if (dp[p][rem][x] != -1) return dp[p][rem][x];
  int fch = 1e8, sch;
  sch = solve(p + 1, rem, x) + 1;
  if (s[p] == '0' && x)
    fch = solve(p + 1, rem, x);
  else if (s[p] != '0')
    fch = solve(p + 1, ((rem % 3) + (s[p] - '0') % 3) % 3, 1);
  if (fch < sch) {
    dp[p][rem][x] = fch;
    gg[p][rem][x] = 1;
  } else {
    dp[p][rem][x] = sch;
    gg[p][rem][x] = 2;
  }
  return dp[p][rem][x];
}
void print(int p, int rem, int x) {
  if (p == n) return;
  if (gg[p][rem][x] == 1) {
    printf("%c", s[p]);
    if (s[p] == '0' && x)
      print(p + 1, rem, x);
    else
      print(p + 1, ((rem % 3) + (s[p] - '0') % 3) % 3, 1);
  } else {
    print(p + 1, rem, x);
  }
}
int main() {
  std::ios_base::sync_with_stdio(0);
  scanf("%s", s);
  n = strlen(s);
  for (int i = 0; i < (int)(n + 10); ++i) {
    for (int j = 0; j < (int)(3); ++j) {
      for (int k = 0; k < (int)(2); ++k) dp[i][j][k] = -1;
    }
  }
  long suu = solve(0, 0, 0);
  if (suu >= 1e8) {
    for (int i = 0; i < (int)(n); ++i) {
      if (s[i] == '0') return printf("0"), 0;
    }
    return printf("-1"), 0;
  }
  print(0, 0, 0);
  return 0;
}
