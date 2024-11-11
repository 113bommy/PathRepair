#include <bits/stdc++.h>
using namespace std;
int k, l, r, l1, r1;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> l >> r >> l1 >> r1;
    cout << l << " ";
    if (l != l1)
      cout << l1;
    else
      cout << l1 + 1;
    cout << endl;
  }
  return 0;
}
