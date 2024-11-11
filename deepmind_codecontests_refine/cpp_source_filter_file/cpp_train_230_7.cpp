#include <bits/stdc++.h>
using namespace std;
void sol() {
  double pi = 2 * acos(0.0);
  double n;
  cin >> n;
  n *= 2.0;
  double ang = 360.0 / n;
  double ans1 = cos(ang / 4.0 * pi / 180.0);
  double ans2 = sin(ang / 2.0 * pi / 180.0);
  ans1 /= ans2;
  printf("%f", ans1);
}
int main() {
  int t;
  cin >> t;
  while (t > 0) {
    t--;
    sol();
  }
  return 0;
}
