#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(10);
  int n;
  cin >> n;
  while (n--) {
    double d;
    cin >> d;
    double delta = d * d - 4 * d;
    if (delta < 0) {
      cout << "N" << endl;
    } else {
      double x1 = (d + sqrt(delta)) / 2;
      double x2 = (d - sqrt(delta)) / 2;
      if (x1 < 0 || x2 < 0) {
        cout << "N" << endl;
      } else {
        cout << "Y " << x1 << " " << x2 << endl;
      }
    }
  }
}
