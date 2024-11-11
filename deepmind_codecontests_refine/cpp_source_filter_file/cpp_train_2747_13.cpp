#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000,100000000")
using namespace std;
const int N = 100005;
int n, x[N], y[N], k;
double sqr(double d) { return d * d; }
double dist(int i, int j) { return sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j])); }
int main() {
  double ans = 1e18;
  scanf("%d %d", &n, &k);
  k--;
  for (int i = 0; i < n; i++) scanf("%d", x + i);
  scanf("%d %d", x + n, y + n);
  if (k == n) {
    sort(x, x + n);
    ans = min(dist(n, 0), dist(n, n - 1)) + dist(0, n - 1);
  } else {
    k = x[k];
    sort(x, x + n);
    k = lower_bound(x, x + n, k) - x;
    ans = min(ans, dist(k, 0) + dist(0, n - 1) + dist(n - 1, n));
    ans = min(ans, dist(k, n - 1) + dist(n - 1, 0) + dist(0, n));
    for (int i = k; i < n - 1; i++) {
      ans = min(ans, dist(0, i) +
                         min(dist(k, i) + dist(0, n), dist(k, 0) + dist(i, n)) +
                         min(dist(n, i + 1), dist(n, n - 1)) +
                         dist(i + 1, n - 1));
    }
    for (int i = 1; i < k; i++) {
      ans = min(ans, dist(i, n - 1) +
                         min(dist(k, i) + dist(n - 1, n),
                             dist(k, n - 1) + dist(i, n)) +
                         min(dist(n, 0), dist(n, i - 1)) + dist(0, i - 1));
    }
  }
  printf("%.10f\n", ans);
  return 0;
}
