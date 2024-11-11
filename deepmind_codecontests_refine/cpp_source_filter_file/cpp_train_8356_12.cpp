#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 1 || n == 3 || n == 4) {
      cout << -1 << endl;
      continue;
    }
    if (n % 3 == 0) {
      cout << n / 3 << " " << 0 << " " << 0 << endl;
    } else if (n % 3 == 1) {
      cout << (n - 7) / 3 << " " << 0 << " " << 1 << endl;
    } else {
      cout << (n - 5) / 3 << " " << 1 << " " << 0 << endl;
    }
  }
  return 0;
}
