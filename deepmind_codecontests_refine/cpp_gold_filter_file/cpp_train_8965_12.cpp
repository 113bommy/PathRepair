#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  long int l1, l2, r1, r2, q;
  cin >> q;
  while (q--) {
    cin >> l1 >> r1 >> l2 >> r2;
    if (l2 != r1)
      cout << r1 << " " << l2 << endl;
    else if (l1 != r2)
      cout << l1 << " " << r2 << endl;
  }
  return 0;
}
