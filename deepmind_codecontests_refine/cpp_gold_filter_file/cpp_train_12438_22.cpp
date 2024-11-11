#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n;
int ar[N];
bool valid(double g) {
  double last = -2e9, station = 0;
  for (int i = 1; i <= n; i++) {
    if (last + g * 2 < ar[i]) {
      last = ar[i];
      station++;
    }
  }
  return station <= 3;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  sort(ar + 1, ar + n + 1);
  int counter = 400;
  double lef = 0, R = 2e9;
  while (counter--) {
    double mid = lef + (R - lef) / 2;
    if (valid(mid)) {
      R = mid;
    } else {
      lef = mid;
    }
  }
  cout << fixed << setprecision(6) << R << '\n';
  double last = -2e9;
  vector<double> p;
  for (int i = 1; i <= n; i++) {
    if (last + 2 * R < ar[i]) {
      last = ar[i];
      p.push_back(ar[i] + R);
    }
  }
  for (int i = 0; i < 3; i++) cout << p[i] << " ";
  return 0;
}
