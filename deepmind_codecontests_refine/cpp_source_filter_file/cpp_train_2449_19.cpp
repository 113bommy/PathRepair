#include <bits/stdc++.h>
using namespace std;
int main() {
  int l1, r1, l2, r2;
  cin >> l1 >> r1 >> l2 >> r2;
  if (r2 >= l1 - 1 && r2 < 2 * (l1 + 1) || l2 >= r1 - 1 && l2 < 2 * (r1 + 1))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
