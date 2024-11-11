#include <bits/stdc++.h>
using namespace std;
struct po {
  double x, y;
  double len2() { return x * x + y * y; }
  double len() { return sqrt(x * x + y * y); }
  po() {}
  po(double x, double y) {
    this->x = x;
    this->y = y;
  }
};
po operator-(po v1, po v2) { return po(v1.x - v2.x, v1.y - v2.y); }
double operator%(po v1, po v2) { return (v1.x * v2.y - v1.y * v2.x); }
double operator*(po v1, po v2) { return v1.x * v2.x + v1.y * v2.y; }
int n;
double pi = 3.14159265358979323846;
po p, q[100500];
double mn = 100000000000000, mx = 0;
double min_d(po v1, po v2) {
  if ((v1 - v2) * (v1 - p) >= 0 && (v2 - v1) * (v2 - p) >= 0) {
    return ((v1 - p) * (v2 - p) / (v1 - v2).len2()) * ((v1 - p) * (v2 - p));
  } else {
    return min((v1 - p).len2(), (v2 - p).len2());
  }
}
int main() {
  cin >> n >> p.x >> p.y;
  for (int i = 0; i < n; i++) {
    cin >> q[i].x >> q[i].y;
  }
  q[n] = q[0];
  for (int i = 0; i < n; i++) {
    mx = max(mx, (q[i] - p).len2());
    mn = min(min_d(q[i], q[i + 1]), mn);
  }
  mn = mx - mn;
  cout.precision(30);
  cout << double(mn) * pi;
}
