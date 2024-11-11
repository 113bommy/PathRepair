#include <bits/stdc++.h>
using namespace std;
const int N = 1510;
const double PI = acos(-1);
const double eps = 1e-10;
double R, C, inf;
int n;
vector<pair<double, double> > a;
deque<pair<double, int> > s;
void ad(double l, double r) {
  s.push_back(make_pair(l, 1));
  s.push_back(make_pair(r, -1));
}
void ad2(double l, double r) {
  s.push_back(make_pair(l, 2000));
  s.push_back(make_pair(r, -2000));
}
void cut(double r, pair<double, double> p, pair<double, double> q) {
  double d = sqrt((p.first - q.first) * (p.first - q.first) +
                  (p.second - q.second) * (p.second - q.second));
  if (d > 2 * r || d < eps) return;
  double alpha = atan2(q.first - p.first, q.second - p.second);
  double theta = acos(d * .5 / r);
  double le, ri;
  le = alpha - theta;
  ri = alpha + theta;
  if (ri > PI) {
    ad(le, PI);
    ad(-PI, ri - 2 * PI);
  } else if (le < -PI) {
    ad(-PI, ri);
    ad(le + 2 * PI, PI);
  } else
    ad(le, ri);
}
void intersect(pair<double, double> p, double r) {
  double theta;
  if (p.first < r) {
    theta = acos(p.first / r);
    ad2(-PI * .5 - theta, -PI * .5 + theta);
  }
  if (p.first + r > R) {
    theta = acos((R - p.first) / r);
    ad2(PI * .5 - theta, PI * .5 + theta);
  }
  if (p.second < r) {
    theta = acos(p.second / r);
    ad2(PI - theta, PI);
    ad2(-PI, -PI + theta);
  }
  if (p.second + r > C) {
    theta = acos((C - p.second) / r);
    ad2(-theta, theta);
  }
}
int ipan(double r, int t) {
  int i, sum = 0;
  for (i = 0; i < n; i++)
    if (i != t) {
      cut(r, a[t], a[i]);
    }
  intersect(a[t], r);
  sort(s.begin(), s.end());
  double last = -PI;
  for (; !s.empty(); s.pop_front()) {
    pair<double, int> now = s.front();
    if (sum < 2 && now.first > last) {
      return 1;
    }
    sum += now.second;
    last = now.first;
  }
  return 0;
}
void iWork() {
  cin >> R >> C >> n;
  int i;
  double x, y, ans = -1;
  for (i = 1; i <= n; i++) {
    scanf("%lf %lf", &x, &y);
    a.push_back(make_pair(x, y));
  }
  random_shuffle(a.begin(), a.end());
  inf = sqrt(R * R + C * C);
  for (i = 0; i < n; i++) {
    if (ans != -1 && ipan(ans, i) == 0) continue;
    double L, M, R;
    L = ans;
    R = inf;
    for (int j = 1; j <= 60; j++) {
      M = (L + R) * .5;
      if (ipan(M, i))
        L = M;
      else
        R = M;
    }
    ans = max(ans, R);
  }
  printf("%.10lf\n", ans);
}
int main() {
  iWork();
  return 0;
}
