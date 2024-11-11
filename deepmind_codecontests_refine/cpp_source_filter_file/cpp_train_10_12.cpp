#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int q, l, r, d;
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> l >> r >> d;
    if (l <= d && r >= d) {
      cout << (((r / d) + 1) * d);
    } else {
      cout << d << "\n";
    }
  }
  return 0;
}
