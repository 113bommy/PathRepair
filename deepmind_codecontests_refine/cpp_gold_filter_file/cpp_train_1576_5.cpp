#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-7;
int n, r;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> r;
  double deg = (pi / n);
  cout << fixed << setprecision(6) << r * sin(deg) / (1 - sin(deg)) << "\n";
  return 0;
}
