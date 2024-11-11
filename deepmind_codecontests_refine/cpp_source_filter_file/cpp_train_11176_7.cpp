#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a1, b1, c1, a2, b2, c2;
  cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
  if (!a1 && !b1 && !c1 || !a2 && !b2 && !c2) {
    cout << 0;
  } else if (a1 * b2 == a2 * b1) {
    if (!b1 && !b2) {
      cout << (a1 * c2 == a2 * c1 ? -1 : 0);
    } else {
      cout << (b1 * c2 == b2 * c1 ? -1 : 0);
    }
  } else {
    cout << 1;
  }
  cout << '\n';
  return 0;
}
