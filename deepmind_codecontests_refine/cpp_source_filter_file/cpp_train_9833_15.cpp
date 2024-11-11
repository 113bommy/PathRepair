#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  double ans;
  cin >> n >> m;
  if (m * n == 1) {
    cout << 1;
    return 0;
  }
  ans = (double)1 / (double)n +
        (double)(n - 1) / ((double)m * n - 1) * (n - 1) / (double)n;
  printf("%.10f", ans);
  return 0;
}
