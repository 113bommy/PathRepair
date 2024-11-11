#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    double n;
    cin >> n;
    if (n == 0) {
      cout << "Y 0.0000000000 0.0000000000" << endl;
      continue;
    }
    if (n < 4) {
      cout << "N" << endl;
      continue;
    }
    double k = sqrt(n * (n - 4));
    double a1 = (n - k) / 2.0;
    double a2 = (n + k) / 2.0;
    cout << fixed << setprecision(12) << "Y " << a1 << " " << a2 << endl;
  }
}
