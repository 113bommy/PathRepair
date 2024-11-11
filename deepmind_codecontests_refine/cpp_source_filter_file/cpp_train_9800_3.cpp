#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
int main() {
  string s;
  cin >> s;
  while (s != "end" && s != "mistake") {
    int l = 0, r = 1;
    do {
      cout << "? " << l << " " << r << endl;
      cin >> s;
      if (s == "y") l = r, r <<= 1;
    } while (s == "y");
    while (r - l > 1) {
      int mid = (l + r) >> 1;
      cout << "? " << mid << " " << r << endl;
      cin >> s;
      if (s == "y")
        l = mid;
      else
        r = mid;
    }
    cout << "! " << l + 1 << endl;
    cin >> s;
  }
  return 0;
}
