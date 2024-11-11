#include <bits/stdc++.h>
using namespace std;
struct point3D {
  double x;
  double y;
  double z;
  point3D() {}
  point3D(double a, double b, double d) {
    x = a;
    y = b;
    z = d;
  }
  point3D operator+(const point3D &a) {
    return point3D(a.x + this->x, a.y + this->y, this->z + a.z);
  }
  bool operator==(const point3D &a) {
    if (a.x == this->x && a.y == this->y && this->z == a.z) return true;
    return false;
  }
};
double distance3D(point3D a, point3D b) {
  if (a == b) return 0.0;
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) +
              (a.z - b.z) * (a.z - b.z));
}
vector<point3D> movement;
point3D harry, bestPoint;
double vs, vp, bestSol;
bool sol = false;
int bestI = -1;
double bestT = 1e7;
vector<pair<double, double> > times;
void Bsearch(double AT, point3D base, point3D start, point3D end) {
  double tleft, tright;
  tleft = distance3D(base, start) / vs;
  tright = distance3D(base, end) / vs;
  while (tleft + 1e-11 < tright) {
    point3D midPt((start.x + end.x) / 2.0, (start.y + end.y) / 2.0,
                  (start.z + end.z) / 2.0);
    if ((AT + distance3D(base, midPt) / vs) >
        distance3D(harry, midPt) / vp - 1e-11) {
      end = midPt;
    } else {
      start = midPt;
      bestPoint = midPt;
    }
    tleft = distance3D(base, start) / vs;
    tright = distance3D(base, end) / vs;
  }
}
void calc() {
  double AT;
  double sum = 0.0;
  times[0].first = 0.0;
  times[0].second = distance3D(harry, movement[0]) / vp;
  if (movement[0] == harry || fabs(times[0].first - times[0].second) < 1e-11) {
    bestI = 0;
    bestPoint = movement[0];
    sol = true;
    return;
  }
  if (bestI < 0)
    for (int i = 1; i < movement.size(); i++) {
      times[i].first =
          times[i - 1].first + distance3D(movement[i - 1], movement[i]) / vs;
      times[i].second = distance3D(harry, movement[i]) / vp;
      if (times[i].second <= times[i].first) {
        if (times[i].first < bestT) {
          AT = times[i - 1].first;
          bestT = times[i].first;
          bestI = i;
        }
      }
    }
  if (bestI > -1) {
    sol = true;
    bestSol = bestT;
    bestPoint = movement[bestI];
    Bsearch(AT, movement[bestI - 1], movement[bestI - 1], movement[bestI]);
  }
}
int main() {
  int n;
  int x, y, z;
  point3D pt;
  scanf("%d", &n);
  for (int i = 0; i <= n; i++) {
    scanf("%d%d%d\n", &x, &y, &z);
    pt.x = x;
    pt.y = y, pt.z = z;
    movement.push_back(pt);
  }
  scanf("%lf%lf\n", &vp, &vs);
  scanf("%d%d%d", &x, &y, &z);
  harry.x = x;
  harry.y = y;
  harry.z = z;
  times.clear();
  times.resize(n + 1);
  calc();
  if (sol) {
    printf("YES\n");
    bestSol = distance3D(harry, bestPoint) / vp;
    printf("%.10lf\n%.10lf %.10lf %.10lf", bestSol, bestPoint.x, bestPoint.y,
           bestPoint.z);
  } else {
    printf("NO");
  }
  return 0;
}
