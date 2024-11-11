#include <bits/stdc++.h>
using namespace std;
int main() {
  int l, r, a, i = 0;
  cin >> l >> r >> a;
  while (a--) {
    if (l >= r) {
      r++;
    } else {
      l++;
    }
  }
  cout << 2 * ((l < r) ? l : r) << endl;
  return 0;
}
