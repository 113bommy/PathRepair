#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int l1, r1, l2, r2, l, r;
    cin >> l1 >> r1 >> l2 >> r2;
    if (l1 < l2)
      l = l1, r = r2;
    else
      l = r1, r = l2;
    cout << l << ' ' << r << endl;
  }
  return 0;
}
