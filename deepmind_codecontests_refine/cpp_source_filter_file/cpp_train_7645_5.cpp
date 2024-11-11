#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  double ans = n;
  for (int i = 1; i <= n; ++i) ans -= pow(1.0 * i / n, m);
  printf("%.10f\n", ans);
  return 0;
}
