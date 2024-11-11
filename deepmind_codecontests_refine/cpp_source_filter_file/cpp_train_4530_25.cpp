#include <bits/stdc++.h>
using namespace std;
int n;
long long r, v;
double esp = 1e-6;
double HF;
int check(double t) {
  double x = t * v;
  if (x + sin(x / r) * r >= HF + esp) return 1;
  if (x - sin(x / r) * r >= HF + esp) return 1;
  return 0;
}
int main() {
  scanf("%d%lld%lld", &n, &r, &v);
  for (int i = 0; i < n; i++) {
    long long s, f;
    scanf("%lld%lld", &s, &f);
    long long L = f - s;
    HF = L / 2.0;
    double l = 0, r = HF / v;
    while ((r - l) >= esp) {
      double mid = (l + r) / 2.0;
      if (check(mid))
        r = mid;
      else
        l = mid;
    }
    printf("%.12f\n", 2 * l);
  }
  return 0;
}
