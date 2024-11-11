#include <bits/stdc++.h>
using namespace std;
double a, b, c;
double xa, ya, xb, yb;
struct node {
  double x, y;
};
vector<node> po[2];
double dis(node a, node b, int id) {
  if (id == 1)
    return abs(a.x - b.x) + abs(a.y - b.y);
  else
    return hypot(a.x - b.x, a.y - b.y);
}
void deal(double x, int id, int a_b) {
  if (id == 1) {
    double y = (-c - a * x) / b;
    node p;
    p.x = x;
    p.y = y;
    po[a_b].push_back(p);
  } else {
    double y = (-c - b * x) / a;
    node p;
    p.x = y;
    p.y = x;
    po[a_b].push_back(p);
  }
}
int main() {
  cin >> a >> b >> c;
  cin >> xa >> ya >> xb >> yb;
  double ans = abs(xa - xb) + abs(ya - yb);
  if (a == 0 || b == 0) {
    printf("%0.10\n", ans);
    return 0;
  }
  deal(xa, 1, 0);
  deal(ya, 2, 0);
  deal(xb, 1, 1);
  deal(yb, 2, 1);
  double now;
  node A = {xa, ya};
  node B = {xb, yb};
  for (auto i : po[0]) {
    for (auto j : po[1]) {
      now = dis(A, i, 1) + dis(i, j, 2) + dis(j, B, 1);
      ans = min(ans, now);
    }
  }
  printf("%0.10lf", ans);
}
