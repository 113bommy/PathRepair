#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int l, r;
  cin >> l >> r;
  if (r - l < 2) {
    cout << "-1";
  } else {
    if (l % 2 == 0) {
      cout << l << " " << l + 1 << " " << l + 2;
    } else {
      if (r - l == 2) {
        cout << "-1";
      } else {
        cout << l + 1 << " " << l + 2 << " " << l + 3;
      }
    }
  }
  return 0;
}
