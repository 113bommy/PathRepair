#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p1, p2, p3, t1, t2;
  cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
  int a[n][2];
  int power = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1];
    power += (a[i][1] - a[i][0]) * p1;
    if (i != 0) {
      int t = a[i][0] - a[i - 1][1];
      if (t >= t1 + t2) {
        power += t1 * p1 + t2 * p2 + (t - t1 - t2) * p3;
      } else if (t >= t1) {
        power += t1 * p1 + (t - t1) * t2;
      } else {
        power += t * p1;
      }
    }
  }
  cout << power;
}
