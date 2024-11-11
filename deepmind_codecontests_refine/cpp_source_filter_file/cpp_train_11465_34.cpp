#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int d;
    cin >> d;
    if (0 < d && d < 4) {
      cout << "N" << endl;
      continue;
    }
    double delta = sqrt(d * d - 4 * d);
    cout << "Y ";
    cout << fixed << setprecision(8);
    cout << (d + delta) / 2 << " " << (d - delta) / 2 << endl;
  }
}
