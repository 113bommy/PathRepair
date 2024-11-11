#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned int t;
  cin >> t;
  while (t--) {
    unsigned long long n;
    cin >> n;
    unsigned long long rem = n % 3;
    if (n < 3) {
      if (n == 1)
        cout << 1 << " " << 0 << "\n";
      else {
        cout << 0 << " " << 2 << "\n";
      }
    } else {
      if (rem == 1) {
        cout << (n / 3) + 1 << " " << (n / 3) << "\n";
      } else if (rem == 2) {
        cout << (n / 3) << " " << (n / 3) + 1 << "\n";
      } else {
        cout << (n / 3) << " " << (n / 3) << "\n";
      }
    }
  }
  return 0;
}
