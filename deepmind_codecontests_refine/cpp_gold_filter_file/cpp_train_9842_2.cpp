#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
const double pp = 3.14159265358979323846;
double dist(double x1, double x2, double y1, double y2) {
  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
void solve() {
  double d, h, v, e;
  cin >> d >> h >> v >> e;
  v = v * 4 / (pp * pow(d, 2));
  if (v > e)
    cout << "YES\n" << fixed << setprecision(9) << h / (v - e);
  else
    cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t = 1;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
