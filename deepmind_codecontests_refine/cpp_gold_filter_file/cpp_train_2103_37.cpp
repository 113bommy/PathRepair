#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, k, T;
  cin >> T;
  while (T--) {
    cin >> a >> b >> c >> d >> k;
    int sum = (a / c + (a % c == 0 ? 0 : 1) + b / d + (b % d == 0 ? 0 : 1));
    if (sum <= k) {
      cout << a / c + (a % c == 0 ? 0 : 1) << " "
           << b / d + (b % d == 0 ? 0 : 1) << endl;
    } else
      cout << "-1" << endl;
  }
}
