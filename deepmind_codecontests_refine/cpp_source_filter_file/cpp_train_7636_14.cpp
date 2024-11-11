#include <bits/stdc++.h>
using namespace std;
struct node {
  double x, y;
  node operator+(const node &A) const { return (node){x + A.x, y + A.y}; }
  node operator-(const node &A) const { return (node){x - A.x, y - A.y}; }
  node operator*(const double &A) const { return (node){x * A, y * A}; }
  node operator/(const double &A) const { return (node){x / A, y / A}; }
  double len() { return sqrt(x * x + y * y); }
};
double cross(node a, node b, node c) {
  return a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
}
node get_O(node p1, node p2, node p3) {
  double a1 = 2 * (p1.x - p2.x), a2 = 2 * (p2.x - p3.x), b1 = 2 * (p1.y - p2.y),
         b2 = 2 * (p2.y - p3.y),
         c1 = p2.x * p2.x - p1.x * p1.x + p2.y * p2.y - p1.y * p1.y;
  double c2 = -3 * (p2.x * p2.x + p2.y * p2.y) - (p3.x * p3.x + p3.y * p3.y) +
              4 * (p2.x * p3.x + p2.y * p3.y);
  return (node){(b1 * c2 - b2 * c1) / (a1 * b2 - a2 * b1),
                (a2 * c1 - a1 * c2) / (a1 * b2 - a2 * b1)};
}
bool check(node a, node b, node c) {
  node A = get_O(a, b, c), B, C, D;
  B = b * 2 - A;
  C = a * 2 - A;
  D = c * 2 - B;
  double p1 = cross(C, A, B), p2 = cross(A, B, D), p3 = cross(B, D, C),
         p4 = cross(D, C, A);
  if ((p1 > 0 && p2 > 0 && p3 > 0 && p4 > 0) ||
      (p1 < 0 && p2 < 0 && p3 < 0 && p4 < 0)) {
    puts("YES");
    printf("%.10f %.10f %.10f %.10f %.10f %.10f %.10f %.10f\n", A.x, A.y, B.x,
           B.y, D.y, D.x, C.x, C.y);
    return 1;
  }
  return 0;
}
bool solve(node a, node b, node c) {
  if (cross(a, b, c) && (check(a, b, c) || check(c, a, b) || check(b, c, a)))
    return 1;
  return 0;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    node a, b, c;
    scanf("%lf%lf%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y);
    if (!solve(a, b, c)) puts("No");
  }
}
