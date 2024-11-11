#include <bits/stdc++.h>
using namespace std;
struct p {
  double x, y, z;
} mas[10000];
double l(p a, p b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) +
              (a.z - b.z) * (a.z - b.z));
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> mas[i].x >> mas[i].y >> mas[i].z;
  }
  double k = 1.0;
  p s;
  s.x = 0.0;
  s.y = 0.0;
  s.z = 0.0;
  for (int d = 0; d < 100000; d++) {
    int mx = 0;
    for (int i = 1; i < n; i++)
      if (l(s, mas[mx]) < l(s, mas[i])) mx = i;
    double dx = mas[mx].x - s.x;
    double dy = mas[mx].y - s.y;
    double dz = mas[mx].z - s.z;
    s.x += dx * k;
    s.y += dy * k;
    s.z += dz * k;
    k *= 0.99;
  }
  printf("%.10lf %.10lf %.10lf\n", s.x, s.y, s.z);
  return 0;
}
