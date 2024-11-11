#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-5;
const int MAX = 1000 + 10;
struct Point {
  long double first, second;
  Point(long double a = 0, long double b = 0) : first(a), second(b) {}
};
Point operator+(const Point& a, const Point& b) {
  return Point(a.first + b.first, a.second + b.second);
}
Point operator-(const Point& a, const Point& b) {
  return Point(a.first - b.first, a.second - b.second);
}
long double chaji(const Point& a, const Point& b) {
  return a.first * b.second - a.second * b.first;
}
int operator==(const Point& a, const Point& b) {
  return abs(a.first - b.first) < EPS && abs(a.second - b.second) < EPS;
}
const long double EPS2 = 1e-8;
int operator<(const Point& a, const Point& b) {
  if (abs(a.first - b.first) < EPS2) return a.first < b.first;
  return a.second < b.second;
}
long double dist(const Point& a, const Point& b) {
  return ((a.first - b.first) * (a.first - b.first)) +
         ((a.second - b.second) * (a.second - b.second));
}
int n;
Point s[MAX], t[MAX];
int top;
Point c[MAX];
long double d[MAX];
int findMax() {
  sort(d + 1, d + top + 1);
  int ans = 0;
  for (int i = 1; i <= top;) {
    int num = 0;
    long double first = d[i];
    for (; i <= top && abs(d[i] - first) <= 1e-5; ++i) ++num;
    ans = max(ans, num);
  }
  return ans;
}
int Work(int u) {
  int i;
  top = 0;
  for ((i) = (1); (i) <= (n); ++(i)) {
    if (i == u || t[i] == t[u]) continue;
    if (abs(chaji(s[i] - s[u], t[i] - t[u])) < EPS) c[++top] = t[u] - t[i];
  }
  sort(c + 1, c + top + 1);
  int tmp = 0;
  for ((i) = (1); (i) <= (top); ++(i))
    if (i == 1 || abs(c[i].first - c[i - 1].first) > EPS2 ||
        abs(c[i].second - c[i - 1].second) > EPS2)
      c[++tmp] = c[i];
  top = tmp;
  for ((i) = (1); (i) <= (top); ++(i)) {
    d[i] = atan2(c[i].second, c[i].first);
    if (d[i] < 0) d[i] += M_PI;
  }
  return findMax() + 1;
}
int Work2(int u) {
  int i;
  top = 0;
  for ((i) = (1); (i) <= (n); ++(i)) {
    if (i == u || t[i] == t[u]) continue;
    if (abs(chaji(s[i] - s[u], t[i] - t[u])) < EPS) {
      long double lamda;
      if (abs(t[i].first - t[u].first) > EPS)
        lamda = (s[i].first - s[u].first) / (t[i].first - t[u].first);
      else
        lamda = (s[i].second - s[u].second) / (t[i].second - t[u].second);
      d[++top] = lamda;
    }
  }
  return findMax() + 1;
}
int main() {
  int i;
  cin >> n;
  for ((i) = (1); (i) <= (n); ++(i)) {
    double t1, t2;
    double x1, y1, x2, y2;
    scanf("%lf%lf%lf%lf%lf%lf", &t1, &x1, &y1, &t2, &x2, &y2);
    long double dx = x2 - x1;
    long double dy = y2 - y1;
    long double dt = t2 - t1;
    dx /= dt;
    dy /= dt;
    x1 -= t1 * dx;
    y1 -= t1 * dy;
    s[i] = Point(x1, y1);
    t[i] = Point(dx, dy);
  }
  int ans = 1;
  for ((i) = (1); (i) <= (n); ++(i)) {
    ans = max(ans, Work(i));
    ans = max(ans, Work2(i));
  }
  cout << ans << endl;
  return 0;
}
