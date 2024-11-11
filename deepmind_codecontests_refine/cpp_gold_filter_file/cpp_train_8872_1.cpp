#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  int x;
  for (int k = 0; k < q; k++) {
    cin >> x;
    if (x == 1) cout << 1 << endl;
    if (x >= 2) cout << x << endl;
  }
  return 0;
}
