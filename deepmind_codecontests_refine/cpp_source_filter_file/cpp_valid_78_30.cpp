#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    int l, r, a, b;
    cin >> l >> r;
    a = r;
    if (l < (r / 2)) {
      b = ((r / 2) + 1);
    } else {
      b = l;
    }
    int largest = a % b;
    cout << largest;
  }
  return 0;
}
