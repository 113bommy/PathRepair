#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:268435456")
using namespace std;
const double PI = 3.1415926535897932384626433832795;
template <class T>
T min(T &a, T &b) {
  return (a < b) ? a : b;
}
template <class T>
T max(T &a, T &b) {
  return (a > b) ? a : b;
}
template <class T>
T sqr(T a) {
  return a * a;
}
template <class T>
T abs(T &a) {
  return (a < 0) ? (-a) : a;
}
inline void read(int &x) { scanf("%d", &x); }
inline void readln(int &x) { scanf("%d\n", &x); }
inline void write(int x) { printf("%d", x); }
inline void writeln(int x) { printf("%d\n", x); }
inline void read(long long &x) { scanf("%lld", &x); }
inline void readln(long long &x) { scanf("%lld\n", &x); }
inline void write(long long x) { printf("%lld", x); }
inline void writeln(long long x) { printf("%lld\n", x); }
inline void read(double &x) { scanf("%lf", &x); }
inline void readln(double &x) { scanf("%lf\n", &x); }
inline void write(double x) { printf("%.15lf", x); }
inline void writeln(double x) { printf("%.15lf\n", x); }
inline void read(char *s) { scanf("%s", s); }
inline void readln(char *s) { scanf("%s\n", s); }
inline void write(char *s) { printf("%s", s); }
inline void writeln(char *s) { printf("%s\n", s); }
inline int readInt() {
  int x;
  read(x);
  return x;
}
inline long long readLong() {
  long long x;
  read(x);
  return x;
}
inline double readDouble() {
  double x;
  read(x);
  return x;
}
inline void showTime() {}
const double eps = 1e-10;
double x, y, yw, r;
double ya, yb, yao, ybo;
double wp(double x1, double y1, double x2, double y2) {
  return x1 * y2 - x2 * y1;
}
double dist(double x1, double y1, double x2, double y2) {
  return sqrt(sqr(x1 - x2) + sqr(y1 - y2));
}
bool goodb(double xt) {
  double x1 = x;
  double y1 = y;
  double x2 = xt;
  double y2 = yw;
  double s = wp(x2 - x1, y2 - y1, 0 - x1, ybo - y1);
  double d = s / dist(x1, y1, x2, y2);
  if (d < r + eps) return false;
  return true;
}
bool gooda(double xt) {
  double x1 = x;
  double y1 = y;
  double x2 = xt;
  double y2 = yw;
  double s = wp(x2 - x1, y2 - y1, 0 - x1, yao - r - y1);
  double d = s / dist(x1, y1, x2, y2);
  if (d > -eps) return false;
  return true;
}
int main() {
  srand((unsigned)time(NULL));
  cin >> ya >> yb >> yw >> x >> y >> r;
  yw -= r;
  yao = 2 * yw - ya;
  ybo = 2 * yw - yb;
  double xt = 0;
  double step = x;
  while (step > eps) {
    if (!goodb(xt + step)) xt += step;
    step /= 2;
  }
  if (gooda(xt)) {
    cout.setf(ios::fixed);
    cout.precision(10);
    cout << xt;
  } else {
    cout << -1;
  }
}
