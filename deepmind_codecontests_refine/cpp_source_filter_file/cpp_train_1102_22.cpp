#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int a, b;
    cin >> a >> b;
    if (a == 0 && b == 0)
      cout << 1 << endl;
    else if (a == 0)
      cout << 0.5 << endl;
    else if (b == 0)
      cout << 1 << endl;
    else if (b >= a / 4.0)
      cout << setprecision(9)
           << 1 - (0.5 * a * a / 4.0 + (b - a / 4.0) * a) / (a * 2 * b) << endl;
    else
      cout << setprecision(9) << 1 - (0.5 * b * b * 4.0) / (a * 2 * b) << endl;
  }
  return EXIT_SUCCESS;
}
