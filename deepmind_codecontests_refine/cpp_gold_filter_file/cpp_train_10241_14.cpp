#include <bits/stdc++.h>
using namespace std;
struct ball {
  double x, v;
  ball(double _x, double _v) : x(_x), v(_v) {}
  ball() { ball(0, 0); }
};
bool operator<(const ball& a, const ball& b) { return a.x < b.x; }
const int MAX_N = 500002;
ball balls[MAX_N];
int N;
bool check(double t) {
  double rightMost = -1e20;
  for (int i = 0; i < N; i++) {
    if (balls[i].v > 0) {
      rightMost = max(rightMost, balls[i].x + balls[i].v * t);
    } else if (rightMost > balls[i].x + balls[i].v * t) {
      return true;
    }
  }
  return false;
}
double solve() {
  sort(balls, balls + N);
  double low = 0, high = 1e10, mid;
  int loop = 80;
  while (loop--) {
    mid = (low + high) * 0.5;
    if (check(mid))
      high = mid;
    else
      low = mid;
  }
  if (high > 5e9) {
    puts("-1");
    exit(0);
  }
  return mid;
}
int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    double x, v;
    scanf("%lf%lf", &x, &v);
    balls[i] = ball(x, v);
  }
  printf("%.15f\n", solve());
  return 0;
}
