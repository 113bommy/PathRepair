#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:128000000")
using namespace std;
const double PI = acos(-1.0);
template <class T>
T SQR(const T &a) {
  return a * a;
}
void run() {
  int n, a, d;
  int Ans[100100];
  cin >> n >> a >> d;
  int T[100100], V[100100];
  double mx = 0;
  for (int i = (0), ei = (n); i < ei; i++) {
    double t, v;
    scanf("%lf%lf", &t, &v);
    double t1 = v / a;
    double d1 = a * t1 * t1 / 2;
    if (d1 > d) {
      d1 = d;
      t1 = sqrt(2.0 * d / a);
    }
    double t2 = (d - d1) / v;
    double r = t1 + t2 + t;
    if (r < mx)
      r = mx;
    else
      mx = r;
    printf("%.8lf\n", r - t);
  }
}
int main() {
  time_t beg = clock();
  run();
  return 0;
}
