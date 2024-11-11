#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, i, ctr1 = 0, ctr2 = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x;
    if (x % 2 == 0)
      ctr1++;
    else
      ctr2++;
  }
  if (ctr2 % 2 != 0)
    cout << 1 << endl;
  else
    cout << ctr1 << endl;
}
