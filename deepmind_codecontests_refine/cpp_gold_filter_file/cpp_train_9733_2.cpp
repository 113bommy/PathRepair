#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, mn1, mx1, mn2, mx2, mn3, mx3;
  cin >> n >> mn1 >> mx1 >> mn2 >> mx2 >> mn3 >> mx3;
  while (mn1 + mn2 + mn3 < n) {
    if (mn1 < mx1)
      mn1++;
    else if (mn2 < mx2)
      mn2++;
    else if (mn3 < mx3)
      mn3++;
  }
  cout << mn1 << " " << mn2 << " " << mn3 << endl;
  return 0;
}
