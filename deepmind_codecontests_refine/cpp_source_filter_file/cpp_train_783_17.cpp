#include <bits/stdc++.h>
using namespace std;
const double inf = 1e11, eps = 1e-10;
int n, w, v, u;
int main() {
  cin >> n >> w >> v >> u;
  int i, x, y;
  double left = inf, right = -inf;
  for (i = 1; i <= n; i++) {
    scanf("%d %d", &x, &y);
    left = min(left, 1.0 * x - 1.0 * y * v / u);
    right = max(right, 1.0 * x - 1.0 * y * v / u);
  }
  if (left >= eps || right <= eps)
    printf("%.10lf", 1.0 * w / u);
  else
    printf("%.10lf", right / v + 1.0 * w / u);
  return 0;
}
