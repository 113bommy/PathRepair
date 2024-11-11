#include <bits/stdc++.h>
using namespace std;
long long fun(long long x, long long y) {
  if (x % y == 0)
    return x / y;
  else
    return x / y + 1;
}
int main() {
  int hh, mm;
  cin >> hh >> mm;
  int x = 20;
  double ans2 = 0.00;
  int total = 0;
  if (mm > 0) total = 60 - mm, x = x - 1;
  total += (x - hh) * 60;
  long long H, D, C, N;
  cin >> H >> D >> C >> N;
  double ans1 = (double)fun(H, N) * C;
  ans2 = (double)fun(H + total * D, N) * (C * 80.00) / 100.00;
  if (hh == 20 && mm > 0 || hh > 20) {
    printf("%.5lf", ans2);
    return 0;
  }
  printf("%.5lf", min(ans1, ans2));
}
