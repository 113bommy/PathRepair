#include <bits/stdc++.h>
using namespace std;
typedef struct point {
  double x, y;
  point(double x = 0, double y = 0) : x(x), y(y) {}
} Vector;
point st, en;
int n;
int s1[311], s2[311];
Vector operator+(Vector A, Vector B) { return Vector(A.x + B.x, A.y + B.y); }
Vector operator-(point A, point B) { return Vector(A.x - B.x, A.y - B.y); }
double cross(Vector p1, Vector p2) { return p1.x * p2.y - p2.x * p1.y; }
int main() {
  cin >> st.x >> st.y >> en.x >> en.y;
  scanf("%d", &n);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    point q1, q2;
    double a, b, c;
    cin >> a >> b >> c;
    if (fabs(a) < 1e-8) {
      q1.x = 0;
      q2.y = -c / b;
      q2.x = 10;
      q2.y = q1.y;
    } else if (fabs(b) < 1e-8) {
      q1.x = -c / a;
      q1.y = 0;
      q2.x = q1.x;
      q2.y = 10;
    } else {
      q1.x = 0;
      q1.y = -c / b;
      q2.x = 10;
      q2.y = (-q2.x * a - c) / b;
    }
    double res1 = cross(st - q1, q2 - q1);
    double res2 = cross(en - q1, q2 - q1);
    if (res1 * res2 < 0) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
