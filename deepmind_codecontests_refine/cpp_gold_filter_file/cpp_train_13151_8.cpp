#include <bits/stdc++.h>
using namespace std;
struct Node {
  double t;
  double v, size;
} q[100005];
int main(int argc, char** argv) {
  int n, a;
  double d;
  cin >> n >> a >> d;
  double t1, t2, t;
  double x1, x;
  for (int i = 0; i < n; i++) {
    scanf("%lf %lf", &q[i].t, &q[i].v);
    x1 = q[i].v * q[i].v / 2.0 / a;
    t1 = q[i].v / double(a);
    if (x1 < double(d)) {
      t2 = double(d - x1) / double(q[i].v);
      t = t1 + t2;
    } else {
      t = sqrt(2.0 * double(d) / double(a));
    }
    q[i].t += t;
    q[i].size = i;
  }
  double pre = -1.0;
  for (int i = 0; i < n; i++) {
    if ((q[i].t - pre) >= -1e-5) {
      printf("%.10lf\n", q[i].t);
      pre = q[i].t;
    } else {
      printf("%.10lf\n", pre);
    }
  }
  return 0;
}
