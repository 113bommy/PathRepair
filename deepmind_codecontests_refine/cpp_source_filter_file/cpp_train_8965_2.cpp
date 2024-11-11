#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int l, r, l1, r1;
    cin >> l >> r >> l1 >> r1;
    cout << l << ' ';
    if (l != r1)
      cout << r1;
    else
      cout << r1 + 1;
    cout << '\n';
  }
  return 0;
}
