#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
const double PI = acos(-1);
struct Node {
  double x, y;
  Node(void) {}
  Node(double a, double b) : x(a), y(b) {}
} Po[MAXN];
struct Line {
  Node p, v;
  Line(void) {}
  Line(Node a, Node b) : p(a), v(b) {}
};
Node operator+(const Node &a, const Node &b) {
  return Node(a.x + b.x, a.y + b.y);
}
Node operator-(const Node &a, const Node &b) {
  return Node(a.x - b.x, a.y - b.y);
}
Node operator*(const Node &a, const double &b) {
  return Node(a.x * b, a.y * b);
}
double operator*(const Node &a, const Node &b) { return a.x * b.x + a.y * b.y; }
double operator^(const Node &a, const Node &b) { return a.x * b.y - a.y * b.x; }
double a;
int N;
double sqr(const double &a) { return a * a; }
double Dis(const Node &a, const Node &b) { return sqrt((a - b) * (a - b)); }
void Treat(double &x) {
  if (x < 0) x += 2 * PI;
  if (x > 2 * PI) x -= 2 * PI;
}
bool cmp(const Node &a, const Node &b) {
  return a.x < b.x || a.x == b.x && a.y < b.y;
}
bool Test(double l) {
  static Node Event[MAXN];
  Node B = Node(a, 0);
  int cnt = 0;
  for (int i = 1; i <= N; i++) {
    double r = Dis(Po[i], Node(-a, 0)), dis = Dis(Po[i], B);
    if (l + r < dis || fabs(l - r) > dis) continue;
    double base = atan2(Po[i].y - B.y, Po[i].x - B.x),
           alpha = acos((sqr(l) + sqr(dis) - sqr(r)) / (2 * l * dis));
    double ll = base - alpha, rr = base + alpha;
    Treat(ll), Treat(rr);
    if (ll > rr) rr += 2 * PI;
    if (rr - ll > PI) swap(ll, rr);
    if (ll > rr) rr += 2 * PI;
    Event[++cnt] = Node(ll + 2 * PI, rr + 2 * PI);
    Event[++cnt] = Node(ll, rr);
  }
  sort(Event + 1, Event + cnt + 1, cmp);
  static priority_queue<double, vector<double>, greater<double> > Q;
  while (!Q.empty()) Q.pop();
  for (int i = 1; i <= cnt; i++) {
    for (; !Q.empty() && Q.top() < Event[i].x; Q.pop())
      ;
    if (!Q.empty() && Q.top() < Event[i].y) return 1;
    Q.push(Event[i].y);
  }
  return 0;
}
int main() {
  scanf("%d%lf", &N, &a);
  for (int i = 1; i <= N; i++) scanf("%lf%lf", &Po[i].x, &Po[i].y);
  double tmp, l = 0, r = 2 * a, mid;
  for (int i = 1; i <= 50; i++) {
    mid = (l + r) / 2;
    if (Test(mid))
      tmp = mid, r = mid - 1e-8;
    else
      l = mid + 1e-8;
  }
  printf("%.8f\n", tmp);
  return 0;
}
