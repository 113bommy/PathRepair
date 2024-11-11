#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, x, ele, num, i, digits, sum;
  cin >> t;
  while (t--) {
    cin >> n >> x;
    if (n <= 2)
      cout << 1 << endl;
    else {
      cout << ((n - 3) / x) + 2 << endl;
    }
  }
  return 0;
}
