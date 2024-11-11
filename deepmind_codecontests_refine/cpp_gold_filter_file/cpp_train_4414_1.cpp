#include <bits/stdc++.h>
using namespace std;
struct Point {
  double x;
  double y;
};
struct Circle {
  double x;
  double y;
  double r;
};
struct Vec2 {
  double x;
  double y;
};
struct Line {
  Point p;
  Vec2 d;
};
Circle getApolloniusCircle(Circle A, Circle B);
Line getLineBisector(Circle A, Circle B);
pair<int, pair<Point, Point>> getLineIntersection(Line A, Line B);
pair<int, pair<Point, Point>> getLineCircleIntersection(Line A, Circle B);
pair<int, pair<Point, Point>> getCircleIntersection(Circle A, Circle B);
bool isEpsilonEqual(double x, double y);
int main() {
  cout.precision(5);
  cout << fixed;
  Circle A, B, C{};
  cin >> A.x >> A.y >> A.r >> B.x >> B.y >> B.r >> C.x >> C.y >> C.r;
  bool isFociABLine = A.r == B.r;
  bool isFociBCLine = B.r == C.r;
  Line lineAB;
  Line lineBC;
  Circle fociAB;
  Circle fociBC;
  if (isFociABLine) {
    lineAB = getLineBisector(A, B);
  } else {
    fociAB = getApolloniusCircle(A, B);
  }
  if (isFociBCLine) {
    lineBC = getLineBisector(B, C);
  } else {
    fociBC = getApolloniusCircle(B, C);
  }
  pair<int, pair<Point, Point>> potential;
  if (isFociABLine && isFociBCLine) {
    potential = getLineIntersection(lineAB, lineBC);
  } else if (isFociABLine) {
    potential = getLineCircleIntersection(lineAB, fociBC);
  } else if (isFociBCLine) {
    potential = getLineCircleIntersection(lineBC, fociAB);
  } else {
    potential = getCircleIntersection(fociAB, fociBC);
  }
  if (potential.first == 1) {
    cout << potential.second.first.x << ' ' << potential.second.first.y;
  } else if (potential.first == 2) {
    if (hypot(potential.second.first.x - A.x, potential.second.first.y - A.y) <
        hypot(potential.second.second.x - A.x,
              potential.second.second.y - A.y)) {
      cout << potential.second.first.x << ' ' << potential.second.first.y;
    } else {
      cout << potential.second.second.x << ' ' << potential.second.second.y;
    }
  }
  return 0;
}
Circle getApolloniusCircle(Circle A, Circle B) {
  Vec2 AB{B.x - A.x, B.y - A.y};
  Point p1{A.x + (A.r / (A.r + B.r)) * AB.x, A.y + (A.r / (A.r + B.r)) * AB.y};
  Point p2{A.x + (A.r / (A.r - B.r)) * AB.x, A.y + (A.r / (A.r - B.r)) * AB.y};
  return {p1.x + (p2.x - p1.x) / 2, p1.y + (p2.y - p1.y) / 2,
          hypot(p2.x - p1.x, p2.y - p1.y) / 2};
}
Line getLineBisector(Circle A, Circle B) {
  return {{A.x + (B.x - A.x) / 2, A.y + (B.y - A.y) / 2},
          {A.y - B.y, B.x - A.x}};
}
pair<int, pair<Point, Point>> getLineIntersection(Line A, Line B) {
  double det = A.d.x * -B.d.y + B.d.x * A.d.y;
  if (isEpsilonEqual(det, 0)) {
    return {0, {}};
  }
  double lam = (-B.d.y * (B.p.x - A.p.x) + B.d.x * (B.p.y - A.p.y)) / det;
  return {1, {{A.p.x + lam * A.d.x, A.p.y + lam * A.d.y}, {}}};
}
pair<int, pair<Point, Point>> getLineCircleIntersection(Line L, Circle C) {
  double a = L.d.x * L.d.x + L.d.y * L.d.y;
  double b = 2 * (L.d.x * (L.p.x - C.x) + L.d.y * (L.p.y - C.y));
  double c = (L.p.x - C.x) * (L.p.x - C.x) + (L.p.y - C.y) * (L.p.y - C.y) -
             (C.r * C.r);
  double dis = b * b - 4 * a * c;
  if (isEpsilonEqual(dis, 0.0)) {
    return {1,
            {{L.p.x + ((-1 * b) / (2 * a)) * L.d.x,
              L.p.y + ((-1 * b) / (2 * a)) * L.d.y},
             {}}};
  } else if (dis > 0.0) {
    double lam1 = (-1 * b + sqrt(dis)) / (2 * a);
    double lam2 = (-1 * b - sqrt(dis)) / (2 * a);
    return {2,
            {{L.p.x + lam1 * L.d.x, L.p.y + lam1 * L.d.y},
             {L.p.x + lam2 * L.d.x, L.p.y + lam2 * L.d.y}}};
  } else {
    return {0, {}};
  }
}
pair<int, pair<Point, Point>> getCircleIntersection(Circle A, Circle B) {
  double dist = hypot(B.x - A.x, B.y - A.y);
  if (isEpsilonEqual(dist, A.r + B.r)) {
    Vec2 AB{B.x - A.x, B.y - A.y};
    double percent = A.x / (A.x + B.x);
    return {1, {{A.x + percent * AB.x, A.y + percent * AB.y}, {}}};
  } else if (abs(A.r - B.r) < dist && dist < A.r + B.r) {
    double lenAM = (A.r * A.r + dist * dist - B.r * B.r) / (2 * dist);
    Point M{A.x + (B.x - A.x) * lenAM / dist, A.y + (B.y - A.y) * lenAM / dist};
    Line MC{M, {A.y - B.y, B.x - A.x}};
    return getLineCircleIntersection(MC, A);
  } else {
    return {0, {}};
  }
}
bool isEpsilonEqual(double x, double y) {
  constexpr double e = 1e-4;
  return abs(x - y) <= e;
}
