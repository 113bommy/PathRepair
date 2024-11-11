#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, h, x1, x2, t = 0, ans = 0;
  cin >> n >> h;
  long long a[n][2];
  for (long long i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1];
  }
  long long i = 0, j = 0;
  while (i < n) {
    t += a[i][1] - a[i][0];
    i++;
    if (a[i][0] - a[i - 1][1] >= h) {
      ans = max(ans, t + h);
      t -= a[j][1] - a[j][0];
      i--;
      t -= a[i][1] - a[i][0];
      j++;
      h += a[j][0] - a[j - 1][1];
      t -= a[j][0] - a[j - 1][1];
    } else {
      t += a[i][0] - a[i - 1][1];
      h -= a[i][0] - a[i - 1][1];
    }
    if (j == n - 1) break;
  }
  cout << max(ans, t + h);
}
