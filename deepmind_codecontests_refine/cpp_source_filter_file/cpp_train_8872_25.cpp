#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  int x;
  for (int k = 0; k < q; k++) {
    cin >> x;
    if (x == 1) cout << 1 << endl;
    if (x >= 3) cout << x - 1 << endl;
  }
  return 0;
}
