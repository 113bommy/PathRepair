#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
struct Point {
  double x, y, z;
};
double dist(Point a, Point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) +
              (a.z - b.z) * (a.z - b.z));
}
Point p[MAXN];
double dis[MAXN];
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; i++) scanf("%lf%lf%lf", &p[i].x, &p[i].y, &p[i].z);
    for (int i = 1; i < n; i++) dis[i] = dist(p[0], p[i]);
    double ta = 100000.0;
    for (int i = 1; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        double tmp = dist(p[j], p[i]);
        double td;
        if (dis[i] > dis[j])
          td = (tmp - dis[i] + dis[j]) / 2 + dis[j];
        else
          td = (tmp - dis[j] + dis[i]) / 2 + dis[i];
        if (ta > td) ta = td;
      }
    }
    printf("%.6lf\n", ta);
  }
  return 0;
}
