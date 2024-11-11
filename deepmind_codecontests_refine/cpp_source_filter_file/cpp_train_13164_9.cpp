#include <bits/stdc++.h>
using namespace std;
int n, i, j, k, x, y, z;
double answer, a[5001][4], b[5000], p = 10000000000.00, s;
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];
  }
  x = a[0][0];
  y = a[0][1];
  z = a[0][2];
  for (i = 0; i < n - 1; i++) {
    b[i] = sqrt((x - a[i + 1][0]) * (x - a[i + 1][0]) +
                (y - a[i + 1][1]) * (y - a[i + 1][1]) +
                (z - a[i + 1][2]) * (y - a[i + 1][2]));
  }
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - 1; j++) {
      if (j != i) {
        s = sqrt((a[j + 1][0] - a[i + 1][0]) * (a[j + 1][0] - a[i + 1][0]) +
                 (a[j + 1][1] - a[i + 1][1]) * (a[j + 1][1] - a[i + 1][1]) +
                 (a[j + 1][2] - a[i + 1][2]) * (a[j + 1][2] - a[i + 1][2]));
        p = min(p, s + b[i] + b[j]);
      }
    }
  }
  answer = p / 2;
  cout.precision(12);
  cout << answer;
}
