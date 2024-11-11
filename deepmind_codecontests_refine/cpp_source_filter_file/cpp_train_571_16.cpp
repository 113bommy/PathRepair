#include <bits/stdc++.h>
using namespace std;
struct Point {
  long long x, y;
  Point(long long a = 0, long long b = 0) { x = a, y = b; }
  Point operator+(const Point &P) const { return Point(x + P.x, y + P.y); }
  Point operator-(const Point &P) const { return Point(x - P.x, y - P.y); }
  bool operator==(const Point &P) const { return x == P.x && y == P.y; }
  long long operator*(const Point &P) const { return x * P.x + y * P.y; }
  long long operator^(const Point &P) const { return x * P.y - y * P.x; }
  double mag() const { return sqrt(x * x + y * y); }
};
double dist(Point a, Point b) {
  double rr = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
  return sqrt(rr);
}
inline bool Collinear(Point A, Point B, Point C) {
  return ((A - B) ^ (C - B)) == 0;
}
inline bool between(Point A, Point B, Point C) {
  if (A == B || C == B) return true;
  return (A - C) * (B - C) > 0 && (C - A) * (B - A) > 0 && Collinear(A, B, C);
}
bool insideConcave(vector<Point> V, Point P) {
  int N = V.size();
  double sum = 0;
  for (int i = 0; i < N; ++i) {
    int j = (i + 1) % N;
    double m1 = (V[i] - P).mag(), m2 = (V[j] - P).mag();
    double dp = ((V[i] - P) * (V[j] - P)) / (m1 * m2);
    double cp = (V[i] - P) ^ (V[j] - P);
    if (cp == 0 && between(V[i], P, V[j])) return true;
    if (dp > 1) dp = 1;
    if (dp < -1) dp = -1;
    double angle = cp > 0 ? acos(dp) : -acos(dp);
    sum += angle;
  }
  return fabs(sum) > 3.14159265358979323846264338327950288;
}
double LinePointD(Point A, Point B, Point C, bool seg = false) {
  if (seg && (A - B) * (C - B) < 0) return (B - C).mag();
  if (seg && (B - A) * (C - A) < 0) return (A - C).mag();
  return fabs((A - B) ^ (C - B)) / (A - B).mag();
}
int main() {
  int N;
  cin >> N;
  Point c;
  cin >> c.x >> c.y;
  vector<Point> V;
  double Rm = 1000000000.0, RM = 0;
  for (int i = 0; i < N; ++i) {
    Point b;
    cin >> b.x >> b.y;
    V.push_back(b);
    RM = max(RM, dist(c, b));
    Rm = min(Rm, dist(c, b));
  }
  if (insideConcave(V, c)) Rm = 0;
  for (int i = 0; i < N; ++i) {
    double d = LinePointD(V[i], V[(i + 1) % N], c);
    Rm = min(Rm, d);
  }
  printf("%0.15lf\n",
         (3.14159265358979323846264338327950288 * (RM * RM - Rm * Rm)));
}
