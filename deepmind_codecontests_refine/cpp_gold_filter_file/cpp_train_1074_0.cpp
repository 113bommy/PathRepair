#include <bits/stdc++.h>
using namespace std;
double area(int x, int y) {
  double a = ((y * y) - (x * x));
  return a;
}
int main() {
  int n;
  cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  double ans = 0;
  if (n % 2) {
    ans += a[1] * a[1];
    for (int i = 3; i <= n; i += 2) ans += area(a[i - 1], a[i]);
  } else {
    for (int i = 2; i <= n; i += 2) {
      ans += area(a[i - 1], a[i]);
    }
  }
  ans = ans * 3.1415926536;
  printf("%.10llf\n", ans);
  return 0;
}
