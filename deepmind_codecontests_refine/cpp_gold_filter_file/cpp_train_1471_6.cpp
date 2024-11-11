#include <bits/stdc++.h>
using namespace std;
const long long INF = 1 << 30;
priority_queue<pair<long long, long long>, vector<pair<long long, long long> >,
               greater<pair<long long, long long> > >
    pq;
vector<pair<long long, pair<long long, long long> > > vpp;
vector<pair<long long, long long> > vp;
const int mx = 100005;
struct Point {
  long long x, y;
} P[mx], ans[mx];
Point Pivot;
long long orientation(Point p, Point q, Point r) {
  return ((q.y - p.y) * (r.x - q.x)) - ((r.y - q.y) * (q.x - p.x));
}
long long dist(Point p1, Point p2) {
  return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}
double calc(Point A, Point B, Point C) {
  double a = sqrt((double)dist(A, B));
  double b = sqrt((double)dist(B, C));
  double c = sqrt((double)dist(C, A));
  return acos((a * a + c * c - b * b) / (2 * a * c));
}
bool cmp(Point a, Point b) {
  if (orientation(Pivot, a, b) == 0) return dist(Pivot, a) < dist(Pivot, b);
  long long slop1x = a.x - Pivot.x;
  long long slop1y = a.y - Pivot.y;
  long long slop2x = b.x - Pivot.x;
  long long slop2y = b.y - Pivot.y;
  return (atan2((double)slop1y, (double)slop1x) -
          atan2((double)slop2y, (double)slop2x)) < 0;
}
Point nextToTop(stack<Point> &S) {
  Point p = S.top();
  S.pop();
  Point res = S.top();
  S.push(p);
  return res;
}
vector<Point> V;
double Convexhull(long long N) {
  long long ymin = P[0].y, mn = 0;
  for (int i = 1; i < N; i++) {
    if (P[i].y < ymin || (ymin == P[i].y && P[i].x < P[mn].x)) {
      ymin = P[i].y;
      mn = i;
    }
  }
  swap(P[0], P[mn]);
  Pivot = P[0];
  sort(&P[1], P + N, cmp);
  long long m = 1;
  for (int i = 1; i < N; i++) {
    while (i < N - 1 && orientation(Pivot, P[i], P[i + 1]) == 0) i++;
    P[m++] = P[i];
  }
  stack<Point> S;
  S.push(P[0]);
  S.push(P[1]);
  S.push(P[2]);
  for (int i = 3; i < m; i++) {
    while (orientation(nextToTop(S), S.top(), P[i]) >= 0) S.pop();
    S.push(P[i]);
  }
  int cnt = 0;
  while (!S.empty()) {
    Point p = S.top();
    ans[cnt++] = p;
    S.pop();
  }
  for (int i = cnt - 1; i >= 0; i--) V.push_back(ans[i]);
  int sz = V.size();
  return sz;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed;
  int n;
  cin >> n;
  int x[n];
  int y[n];
  int minx = 1e9 + 2;
  int maxx = -1e9 + 2;
  int miny = 1e9 + 2;
  int maxy = -1e9 + 2;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    maxx = max(maxx, x[i]);
    minx = min(minx, x[i]);
    maxy = max(maxy, y[i]);
    miny = min(miny, y[i]);
  }
  int ans3 = 0;
  for (int i = 0; i < n; i++) {
    ans3 = max(ans3, maxx - x[i] + maxy - y[i]);
    ans3 = max(ans3, maxx - x[i] + y[i] - miny);
    ans3 = max(ans3, x[i] - minx + maxy - y[i]);
    ans3 = max(ans3, x[i] - minx + y[i] - miny);
  }
  cout << ans3 * 2;
  int max3 = 0;
  for (int i = 3; i < n; i++) {
    cout << " " << (maxx - minx + maxy - miny) * 2;
  }
  return 0;
}
