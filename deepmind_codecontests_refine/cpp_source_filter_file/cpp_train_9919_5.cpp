#include <bits/stdc++.h>
using namespace std;
int main() {
  double t, n, x;
  cin >> t;
  while (t--) {
    cin >> n >> x;
    if (n < 3) {
      cout << n << endl;
    } else {
      cout << ceil((n - 2) / x) + 1 << endl;
    }
  }
}
