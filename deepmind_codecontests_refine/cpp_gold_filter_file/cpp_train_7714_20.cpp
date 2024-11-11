#include <bits/stdc++.h>
using namespace std;
int main() {
  long long l, r, x, o;
  cin >> l >> r;
  x = (r - l + 1) / 2;
  o = l;
  cout << "YES" << endl;
  while (x--) {
    cout << o << " " << o + 1 << endl;
    o += 2;
  }
  return 0;
}
