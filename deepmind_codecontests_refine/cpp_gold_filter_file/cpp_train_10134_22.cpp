#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  double a, d, t, v, res, pre;
  cin >> n >> a >> d;
  pre = -1.0;
  while (n--) {
    cin >> t >> v;
    if (v * v / a / 2 >= d)
      res = sqrt(d * 2 / a);
    else
      res = d / v + v / a / 2;
    res += t;
    if (res - pre <= 0) res = pre;
    printf("%.9f\n", res);
    pre = res;
  }
}
