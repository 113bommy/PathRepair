#include <bits/stdc++.h>
using namespace std;
template <typename T>
void alert(const T& t) {
  cout << t;
  exit(0);
}
const long long MAX64 = 1 + 1e+18;
const int MAX = 1 + 1e+9;
const double PI = 3.1415926536;
const long long CEL = 26;
long long MID(long long l, long long r) { return (l + r) / 2; }
long long LSON(long long u) { return u * 2; }
long long RSON(long long u) { return u * 2 + 1; }
struct Point {
  Point() : x(0), y(0){};
  Point(double X, double Y) : x(X), y(Y){};
  double x;
  double y;
};
int GCD(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return GCD(b, a % b);
}
int LCM(long long a, long long b) { return (a * b) / GCD(a, b); }
int main() {
  {}
  long long s, x1, x2;
  cin >> s >> x1 >> x2;
  long long t1, t2;
  cin >> t1 >> t2;
  long long p, d;
  cin >> p >> d;
  long long answer = abs(x1 - x2) * t2;
  long long tram = 0;
  if (x1 <= x2 && p <= x1) {
    if (d == -1) {
      tram = (p + x2) * t1;
    } else {
      tram = (x2 - p) * t1;
    }
  } else if (x1 <= x2 && p >= x1) {
    if (d == -1) {
      tram = (p + x2) * t1;
    } else {
      tram = ((s - p) + s + x2) * t1;
    }
  } else if (x1 >= x2 && p <= x1) {
    if (d == -1) {
      tram = (p + s + (s - x2)) * t1;
    } else {
      tram = ((s - p) + (s - x2)) * t1;
    }
  } else if (x1 >= x2 && p >= x1) {
    if (d == -1) {
      tram = (p - x2) * t1;
    } else {
      tram = ((s - p) + (s - x2)) * t1;
    }
  }
  answer = min(tram, answer);
  alert(answer);
  return 0;
}
