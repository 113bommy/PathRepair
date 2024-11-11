#include <bits/stdc++.h>
using namespace std;
int main(void) {
  long long int t, a, b, a1, b1;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    a1 = max(a, b);
    b1 = min(a, b);
    if (a1 >= (2 * b1)) {
      cout << b1 << endl;
    } else {
      cout << (a1 - b1) + (2 * ((b1 - (a1 - b1)) / 3)) +
                  (((b1 - (a1 - b1)) % 3) == 2 ? 1 : 0)
           << endl;
    }
  }
  return 0;
}
