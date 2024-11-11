#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long l, r;
    cin >> l >> r;
    if (l == r) {
      cout << 0 << endl;
    } else if (l * 2 <= r) {
      cout << (r + 1) / 2 - 1 << endl;
    } else {
      cout << r % l << endl;
    }
  }
}
