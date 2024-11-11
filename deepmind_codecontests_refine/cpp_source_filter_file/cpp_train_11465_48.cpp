#include <bits/stdc++.h>
using namespace std;
int t;
double d;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> d;
    if (d > 0 && d < 4) {
      cout << "N\n";
      continue;
    }
    double x = d / 2;
    double y = sqrt(d * d - 4 * d) / 2;
    double z = x + y;
    cout << fixed << setprecision(12) << z << ' ' << d - z << '\n';
  }
  return 0;
}
