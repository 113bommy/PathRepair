#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long c1, c2, c3, c4;
    for (long long i = 0; i < 1e3; i++) {
      if ((n - i) % 3 == 0) {
        c2 = (n - i) / 3;
        c1 = c2 + i;
        break;
      }
    }
    long long diff1 = c1 - c2;
    for (long long i = 0; i < 1e3; i++) {
      if ((n - 2 * i) % 3 == 0) {
        c3 = (n - 2 * i) / 3;
        c4 = c3 + i;
        break;
      }
    }
    long long diff2 = c4 - c3;
    if (diff1 <= diff2) {
      cout << c2 << " " << c1 << '\n';
    } else {
      cout << c3 << " " << c4 << '\n';
    }
  }
  return 0;
}
