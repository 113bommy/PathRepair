#include <bits/stdc++.h>
using namespace std;
int main() {
  int a1, a2, a3, am;
  cin >> a1 >> a2 >> a3 >> am;
  int b1, b2, b3;
  b3 = max(am, a3);
  b2 = max(max(b3 + 1, a2), 2 * am + 1);
  b1 = max(b2 + 1, a1);
  if (b3 > 2 * a3 || b2 > 2 * a2 || b1 > 2 * a1 || b3 > 2 * am) {
    cout << -1 << endl;
  } else {
    cout << b1 << endl << b2 << endl << b3 << endl;
  }
  return 0;
}
