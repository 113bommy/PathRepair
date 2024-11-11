#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    double n, x;
    cin >> n >> x;
    if (n <= 2) {
      cout << 1 << "\n";
    } else {
      cout << ceil((n - 3) / x) + 1 << "\n";
    }
  }
}
