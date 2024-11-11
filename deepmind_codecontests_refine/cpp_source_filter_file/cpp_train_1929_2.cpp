#include <bits/stdc++.h>
using namespace std;
struct point {
  double x, y;
  point() {}
  point(double x, double y) : x(x), y(y) {}
};
void norm(point &p) {
  double len = sqrt(p.x * p.x + p.y * p.y);
  p.x /= len;
  p.y /= len;
}
point p, v;
double a, b, c, d;
void print(point p) { cout << p.x << " " << p.y << "\n"; }
int main() {
  point p, v;
  cin >> p.x >> p.y >> v.x >> v.y >> a >> b >> c >> d;
  point v90 = v;
  swap(v90.x, v90.y);
  v90.x = -v90.x;
  norm(v);
  norm(v90);
  cout << fixed << setprecision(9);
  point f1(p.x + b * v.x, p.y + b * v.y);
  print(f1);
  point f2(p.x + a / 2 * v90.x, p.y + a / 2 * v90.y);
  print(f2);
  point f3(p.x + c / 2 * v90.x, p.y + a / 4 * v90.y);
  print(f3);
  point f4(f3.x - d * v.x, f3.y - d * v.y);
  print(f4);
  point f5(f4.x - c * v90.x, f4.y - c * v90.y);
  print(f5);
  point f6(p.x - c / 2 * v90.x, p.y - a / 4 * v90.y);
  print(f6);
  point f7(p.x - a / 2 * v90.x, p.y - a / 2 * v90.y);
  print(f7);
}
