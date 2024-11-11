#include <bits/stdc++.h>
using namespace std;
class point {
 public:
  double x;
  double y;
  double ang;
  point() { x = y = ang = 0; }
  point(int _x, int _y) {
    x = (double)_x;
    y = (double)_y;
    ang = atan2(x, y);
    ang *= 180.0;
    ang /= 3.14159265359;
  }
};
bool cmp(point A, point B) {
  if (A.ang < B.ang) return 1;
  return 0;
}
int N;
point P[100200];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int a, b;
  cin >> N;
  for (long long i = 0; i < N; i++) {
    cin >> a >> b;
    P[i] = point(a, b);
  }
  sort(P, P + N, cmp);
  double Max = 0.0;
  for (long long i = 0; i < N; i++) {
    double uno = P[(i + 1) % N].ang;
    double dos = P[i].ang;
    double Ang = uno - dos;
    if (Ang < 0.0) {
      Ang += 360.0;
    }
    if (Max < Ang) Max = Ang;
  }
  if (Max == 0.0) {
    cout << 0 << "\n";
  }
  printf("%.8f\n", 360.0 - Max);
  return 0;
}
