#include <bits/stdc++.h>
using namespace std;
struct point {
  double x, y;
  void init(double _x, double _y) { x = _x, y = _y; }
  void print(double _x) { printf("%.10lf %.10lf\n", x + _x, y); }
};
double d18 = 3.14159265358979 * 18 / 180;
double d36 = d18 * 2;
struct star {
  point p[5];
  star() {
    p[0].init(-10 * cos(d36), -10 * sin(d36));
    p[1].init(0, 0);
    p[2].init(10 * cos(d36), -10 * sin(d36));
    p[3].init(5, -5 / tan(d18));
    p[4].init(-5, -5 / tan(d18));
  }
};
int main() {
  int n;
  cin >> n;
  star s;
  cout << n * 4 + 1 << endl;
  s.p[0].print(0);
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j < 5; ++j) {
      s.p[j].print(20 * i * cos(d36));
    }
  }
  cout << "1 2 3 4 5" << endl;
  for (int i = 1; i < n; ++i) {
    cout << i * 4 - 1;
    for (int j = 2; j <= 5; ++j) {
      cout << " " << i * 4 + j;
    }
    cout << endl;
  }
  cout << 1 << " ";
  for (int i = 1; i < n; ++i) {
    cout << i * 4 - 1 << " ";
  }
  for (int i = n; i; --i) {
    cout << i * 4 - 1 << " " << i * 4 + 1 << " " << i * 4 - 2 << " " << i * 4
         << " ";
  }
  cout << 1 << endl;
  return 0;
}
