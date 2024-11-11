#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int k, d, t;
  cin >> k >> d >> t;
  long long int s = k * 2LL + (d - k % d);
  long long int s1 = k + (d - k % d);
  t *= 2;
  double ans = (double)((t / s) * s1);
  long long int sp = t % s;
  if (sp <= k * 2) {
    double cp = (double)sp;
    ans += (cp / 2.0);
  } else {
    ans += (double)k;
    sp -= k * 2;
    ans += (double)sp;
  }
  printf("%.10lf\n", ans);
}
