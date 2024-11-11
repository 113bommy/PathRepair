#include <bits/stdc++.h>
const double eps = 1e-8;
const double pi = acos(-1.0);
const int INF = 0x7f7f7f7f;
const double inf = 1e50;
template <class T>
inline T minx(T a, T b) {
  return (a == -1 || b < a) ? b : a;
}
template <class T>
inline T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <class T>
inline T lcm(T a, T b) {
  return a * (b / gcd(a, b));
}
template <class T>
inline T getbit(T n) {
  return n ? (1 + getbit(n & (n - 1))) : 0;
}
template <class T>
inline T lowbit(T n) {
  return n & (-n);
}
using namespace std;
pair<double, double> parse(double x, double y) { return make_pair(x, y); }
int main() {
  int i, j, k;
  pair<double, double> A, B, C;
  double x, y;
  double dx, dy, tx, ty;
  while (cin >> x >> y) {
    A = parse(x, y);
    cin >> x >> y;
    B = parse(x, y);
    cin >> x >> y;
    C = parse(x, y);
    dx = B.first - A.first;
    dy = B.second - A.second;
    tx = C.first - B.first;
    ty = C.second - B.second;
    double res = dx * ty - dy * tx;
    if (res == 0)
      puts("TOWARDS");
    else if (res > 0)
      puts("LEFT");
    else
      puts("RIGHT");
  }
  return 0;
}
