#include <bits/stdc++.h>
using namespace std;
double proj(const complex<double>& p, const complex<double>& a,
            const complex<double>& b) {
  double d = (((conj(((p) - (a))) * (((b) - (a)))).real()));
  double l = (((conj(((b) - (a))) * (((b) - (a)))).real()));
  return d / l;
}
enum STATE { PARALLEL, COLLINEAR, INTERSECT };
STATE lineLineIntersection(const complex<double>& p1, const complex<double>& p2,
                           const complex<double>& p3, const complex<double>& p4,
                           complex<double>& intersectionPoint) {
  double D = p4.imag() - p3.imag();
  double A = p2.real() - p1.real();
  double B = p4.real() - p3.real();
  double C = p2.imag() - p1.imag();
  double numerator =
      ((((p3.real() - p1.real())) * D) + ((p1.imag() - p3.imag()) * B));
  double denominator = ((A * D) - (C * B));
  STATE ret;
  if (fabs(denominator) < 1e-9) {
    if (fabs(numerator) < 1e-9) {
      ret = COLLINEAR;
    } else {
      ret = PARALLEL;
    }
  } else {
    double t = numerator / denominator;
    intersectionPoint = ((p1) + ((t) * ((p2) - (p1))));
    ret = INTERSECT;
  }
  return ret;
}
bool isOnLine(const complex<double>& p1Line, const complex<double>& p2Line,
              const complex<double>& pToCheck) {
  return fabs(((conj(((p2Line) - (p1Line))) * (((pToCheck) - (p1Line))))
                   .imag())) < 1e-9 &&
         fabs(((conj(((p1Line) - (p2Line))) * (((pToCheck) - (p2Line))))
                   .imag())) < 1e-9;
}
bool isOnRay(const complex<double>& rayStart, const complex<double>& pOnRay,
             const complex<double>& pToCheck) {
  return isOnLine(rayStart, pOnRay, pToCheck) &&
         ((conj(((pOnRay) - (rayStart))) * (((pToCheck) - (rayStart))))
              .real()) > -1e-9;
}
bool isOnSegment(const complex<double>& p1, const complex<double>& p2,
                 const complex<double>& pToCheck) {
  return isOnRay(p1, p2, pToCheck) && isOnRay(p2, p1, pToCheck);
}
double costs[1002][1002];
vector<pair<complex<double>, complex<double> > > v;
complex<double> pointToSegmentProj(const complex<double>& p,
                                   const complex<double>& s1,
                                   const complex<double>& s2) {
  double pro = proj(p, s1, s2);
  if (pro < -1e-9) {
    pro = 0;
  } else if (pro - 1e-9 > 1) {
    pro = 1;
  }
  return (s1) + (((s2) - (s1)) * pro);
}
double getMinimumDistance(int i, int j) {
  complex<double> proj1 =
      pointToSegmentProj(v[i].first, v[j].first, v[j].second);
  complex<double> proj2 =
      pointToSegmentProj(v[i].second, v[j].first, v[j].second);
  complex<double> p1 = pointToSegmentProj(proj1, v[i].first, v[i].second);
  complex<double> p2 = pointToSegmentProj(proj2, v[i].first, v[i].second);
  return min((hypot((((p1) - (proj1))).real(), (((p1) - (proj1))).imag())),
             (hypot((((p2) - (proj2))).real(), (((p2) - (proj2))).imag())));
}
int n, a, b;
typedef struct node {
  double cost;
  int vertex;
  node(double c, int v) {
    cost = c;
    vertex = v;
  }
  bool operator<(const node& n) const { return cost + 1e-9 < n.cost; }
};
double vis[1001];
double dijkstra(const complex<double>& start, const complex<double>& end) {
  priority_queue<node> pq;
  double toEnd =
      (hypot((((end) - (start))).real(), (((end) - (start))).imag()));
  if (toEnd - 1e-9 < a) {
    pq.push(node(toEnd, -1));
  }
  for (int i = 0; i < n; i++) {
    double distance = (hypot(
        (((pointToSegmentProj(start, v[i].first, v[i].second)) - (start)))
            .real(),
        (((pointToSegmentProj(start, v[i].first, v[i].second)) - (start)))
            .imag()));
    if (distance - 1e-9 < a) {
      pq.push(node(a, i));
    }
  }
  while (!pq.empty()) {
    node cur = pq.top();
    pq.pop();
    if (cur.vertex == -1) {
      return cur.cost;
    }
    for (int i = 0; i < n; i++) {
      if (i == cur.vertex) continue;
      if (costs[cur.vertex][i] - 1e-9 > a) continue;
      if (cur.cost + a + b < vis[i]) {
        vis[i] = cur.cost + a + b;
        pq.push(node(cur.cost + a + b, i));
      }
    }
    double toEnd = (hypot(
        (((pointToSegmentProj(end, v[cur.vertex].first, v[cur.vertex].second)) -
          (end)))
            .real(),
        (((pointToSegmentProj(end, v[cur.vertex].first, v[cur.vertex].second)) -
          (end)))
            .imag()));
    if (toEnd - 1e-9 < a) {
      pq.push(node(cur.cost + b + toEnd, -1));
    }
  }
  return -1;
}
int main() {
  int x, y, x1, y1;
  scanf("%d %d", &a, &b);
  scanf("%d %d", &x, &y);
  complex<double> start(x, y);
  scanf("%d %d", &x, &y);
  complex<double> end(x, y);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d %d", &x, &y, &x1, &y1);
    v.push_back(make_pair(complex<double>(x, y), complex<double>(x1, y1)));
  }
  for (int i = 0; i < n; i++) {
    vis[i] = 1 << 29;
    costs[i][i] = 0;
    for (int j = i + 1; j < n; j++) {
      costs[i][j] = costs[j][i] = getMinimumDistance(i, j);
    }
  }
  double best = dijkstra(start, end);
  if (best < 0) {
    cout << "-1";
  } else {
    printf("%.15lf", best);
  }
  return 0;
}
