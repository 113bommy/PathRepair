#include <bits/stdc++.h>
using namespace std;
int main(void) {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int t, l1, l2, r2, r1;
  cin >> t;
  while (t--) {
    cin >> l1 >> r1 >> l2 >> r2;
    cout << r1 << " ";
    if (r1 != l2)
      cout << r2 << endl;
    else
      cout << r2 + 1 << endl;
  }
  return 0;
}
