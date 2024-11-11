#include <bits/stdc++.h>
using namespace std;
int q, n;
int main() {
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> n;
    if (n < 4) {
      cout << 4 - n << "\n";
    } else {
      cout << (n % 2 == 0 ? 0 : 1) << "\n";
    }
  }
}
