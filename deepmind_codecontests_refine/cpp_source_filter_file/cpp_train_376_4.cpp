#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, i, j, count = 0, sum = 0, sum2 = 0;
  cin >> a >> b;
  sum = abs(b - a);
  if (sum % 2 == 0) {
    sum2 = sum / 2;
    cout << (sum2 * (sum2 + 1)) / 2;
  } else if (sum % 2 != 0) {
    sum2 = sum / 2;
    cout << sum2 * (sum2 + 1) + sum2 + 1;
  }
  return 0;
}
