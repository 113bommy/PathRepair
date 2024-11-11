#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, i;
    cin >> n;
    for (i = 1; n > 1 && i < n; i++) {
      if (n % 2 == 0)
        n /= 2;
      else if (n % 3 == 0)
        n = (2 * n) / 3;
      else if (n % 5 == 0)
        n = (4 * n) / 5;
      else
        break;
    }
    if (n > 1)
      cout << "-1" << endl;
    else
      cout << i - 1 << endl;
  }
  return 0;
}
