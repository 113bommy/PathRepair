#include <bits/stdc++.h>
using namespace std;
int n;
double x[105], y[105], z[105], centerX, centerY, centerZ, maxD, currD;
double dist(double a, double b, double c) { return a * a + b * b + c * c; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i] >> z[i];
    centerX += x[i];
    centerY += y[i];
    centerZ += z[i];
  }
  centerX /= n;
  centerY /= n;
  centerZ /= n;
  double P = 0.1;
  for (int i = 0; i < 70000; ++i) {
    maxD = dist(centerX - x[0], centerY - y[0], centerZ - z[0]);
    int at = 0;
    for (int j = 1; j < n; ++j) {
      currD = dist(centerX - x[j], centerY - y[j], centerZ - z[j]);
      if (currD > maxD) {
        maxD = currD;
        at = j;
      }
    }
    centerX += (x[at] - centerX) * P;
    centerY += (y[at] - centerY) * P;
    centerZ += (z[at] - centerZ) * P;
    P *= 0.997;
  }
  cout.precision(10);
  cout << fixed << centerX << " " << centerY << " " << centerZ << '\n';
  return 0;
}
