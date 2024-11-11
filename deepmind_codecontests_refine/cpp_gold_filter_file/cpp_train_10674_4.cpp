#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, min, max;
  while (cin >> n) {
    if (n % 7 == 0)
      min = max = n / 7 * 2;
    else if (n % 7 <= 2) {
      max = n / 7 * 2 + n % 7;
      min = n / 7 * 2;
    } else if (n % 7 > 2 && n % 7 < 6) {
      min = n / 7 * 2;
      max = n / 7 * 2 + 2;
    } else if (n % 7 >= 6) {
      max = n / 7 * 2 + 2;
      min = n / 7 * 2 + (n / 7 + 1) * 7 - n;
    }
    cout << min << " " << max << endl;
  }
  return 0;
}
