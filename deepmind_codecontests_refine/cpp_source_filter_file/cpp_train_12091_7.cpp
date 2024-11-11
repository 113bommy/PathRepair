#include <bits/stdc++.h>
using namespace std;
int n, m, k, x1 = -1, x2 = -1;
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    int g;
    scanf("%d", &g);
    if (g > x1) {
      x2 = x1;
      x1 = g;
    } else if (g > x2)
      x2 = g;
  }
  long long ans, lun = m / (k + 1);
  ans = lun * (x1 * k + x2) + (m - lun * (k + 1)) * x1;
  cout << ans << endl;
}
