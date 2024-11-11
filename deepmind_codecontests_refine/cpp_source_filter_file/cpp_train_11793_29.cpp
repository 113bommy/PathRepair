#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
const double PI = 3.141592653589793;
const double eps = 1e-6;
int n, r, R;
double x;
int main() {
  scanf("%d %d %d", &n, &R, &r);
  if (n == 1) {
    if (r == R)
      printf("YES\n");
    else
      printf("NO\n");
    return 0;
  }
  if (r > R / 2) {
    printf("NO\n");
    return 0;
  }
  x = asin(r * 1.0 / (R - r)) * 180.0 / PI;
  if (2 * n * x > 360 + eps)
    printf("NO\n");
  else
    printf("YES\n");
  return 0;
}
