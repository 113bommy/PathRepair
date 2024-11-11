#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  double n;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n * n - 4 * n < 0) {
      cout << "N" << endl;
      continue;
    }
    if (n == 0) {
      double x = 0, y = 0;
      cout << "Y " << fixed << setprecision(8) << x << " " << y << endl;
      continue;
    }
    double x = n + sqrt(n * n - 4 * n);
    x /= 2;
    double y = x / (x - 1);
    cout << "Y " << fixed << setprecision(8) << x << " " << y << endl;
  }
  return 0;
}
