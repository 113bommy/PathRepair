#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  long long int l1, l2, r1, r2;
  cin >> q;
  while (q--) {
    cin >> l1 >> r1 >> l2 >> r2;
    cout << l1 << " ";
    if (r1 >= l2)
      cout << r1 << endl;
    else
      cout << l2 << endl;
  }
  return 0;
}
