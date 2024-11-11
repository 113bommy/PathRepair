#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  cin >> n >> m;
  if (n == 1 && m == 1) {
    puts("1.0000000000000");
    return 0;
  }
  double ans;
  ans = 0;
  ans += 1.0 / n;
  ans += 1.0 * (n - 1) * m * (m - 1) / (1.0 * n * m * (n * m - 1));
  printf("%.10f\n", ans);
  return 0;
}
