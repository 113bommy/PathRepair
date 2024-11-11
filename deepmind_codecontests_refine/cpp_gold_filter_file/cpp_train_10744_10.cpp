#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  int a[3];
  while (q--) {
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    if (a[0] + a[1] >= a[2] - 1)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}
