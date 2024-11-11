#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n == 1) {
      cout << 1 << endl;
    } else {
      cout << n / 2 * 2 << endl;
    }
  }
  return 0;
}
