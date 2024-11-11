#include <bits/stdc++.h>
using namespace std;
const long long INF = 2e6;
long long n, a[100005];
double k, d, t;
int main() {
  while (~scanf("%lf %lf %lf", &k, &d, &t)) {
    double ctt = ceil(k / d) * d;
    double ct = k + (ctt - k) / 2;
    double ans = ctt * floor(t / ct);
    double have = floor(t / ct) * ct;
    double lef = t - have;
    if (lef <= k) {
      ans += lef;
    } else {
      ans += k;
      lef -= k;
      ans += lef * 2;
    }
    printf("%.12f\n", ans);
  }
}
