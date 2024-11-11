#include <bits/stdc++.h>
using namespace std;
int n;
double r;
double odis(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
double fnx[55], fny[55];
int main() {
  cin >> n >> r;
  for (int i = 0; i < (n); ++i) {
    cin >> fnx[i];
    fny[i] = r;
    for (int j = 0; j < (i); ++j) {
      double xx = abs(fnx[i] - fnx[j]);
      if ((xx - 2 * r) >= 1e-10)
        continue;
      else {
        double yy = sqrt(4 * r * r - xx * xx);
        fny[i] = (yy + fny[j] - fny[i] > 1e-10) ? (yy + fny[j]) : (fny[i]);
      }
    }
  }
  for (int i = 0; i < (n); ++i) {
    cout << setprecision(15) << fny[i] << ' ';
  }
  return 0;
}
