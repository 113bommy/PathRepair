#include <bits/stdc++.h>
using namespace std;
int main() {
  long int n, sum = 0, m = 0, z = 0, x;
  cin >> n;
  while (n--) {
    cin >> x;
    if (x < 0) {
      sum = sum + ((-1 * x) - 1);
      m++;
    } else if (x > 0) {
      sum = sum + (x - 1);
    } else {
      z++;
    }
  }
  if (z == 0) {
    if (m % 2 == 0) {
      cout << sum << endl;
      return 0;
    } else {
      cout << sum + 2 << endl;
    }
  } else {
    cout << sum + z << endl;
  }
}
