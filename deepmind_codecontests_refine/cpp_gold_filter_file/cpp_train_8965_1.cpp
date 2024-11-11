#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if (r1 != r2) {
      cout << r1 - 1 << " " << r2 - 1;
    } else if (l1 != l2) {
      cout << l1 + 1 << " " << l2 + 1;
    } else {
      cout << l1 << " " << r2;
    }
    cout << endl;
  }
  return 0;
}
