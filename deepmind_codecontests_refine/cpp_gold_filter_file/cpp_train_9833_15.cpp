#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  double ans = 0;
  cin >> n >> m;
  if (m * n == 1) {
    cout << 1;
    return 0;
  }
  ans = (double)1 / (double)n +
        (double)(m - 1) / ((double)m * n - 1) * (n - 1) / (double)n;
  printf("%.10f", ans);
  return 0;
}
