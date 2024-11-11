#include <bits/stdc++.h>
using namespace std;
int main() {
  double t, y, j, n;
  cin >> t;
  while (t--) {
    cin >> n;
    j = n * n;
    j = j - 4 * n;
    if (j >= 0) {
      double x = sqrt(j);
      if ((-n - x) > 0)
        cout << "N";
      else {
        x = (n - x) / 2;
        if (x != 0)
          y = n / x;
        else
          y = 0;
        std::cout << std::fixed << "Y"
                  << " " << std::setprecision(9) << x << " " << y;
      }
    } else
      cout << "N";
    cout << endl;
  }
}
