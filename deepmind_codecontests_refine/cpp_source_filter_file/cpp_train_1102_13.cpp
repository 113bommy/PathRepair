#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  double a, b, ans;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    if (a == 0) {
      cout << 1 << "\n";
      continue;
      ;
    }
    if (b == 0) {
      cout << "0.5"
           << "\n";
      continue;
      ;
    }
    if (4 * b >= a) {
      ans = a * b + a * a / (2.0 * 4.0);
      ans /= (2.0 * a * b);
    } else {
      ans = 2 * a * b - 2 * b * b;
      ans /= 2 * a * b;
    }
    cout << fixed << setprecision(10) << ans << "\n";
  }
}
