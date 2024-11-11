#include <bits/stdc++.h>
using namespace std;
int main() {
  long long l, r, x = 1, d;
  int q;
  cin >> q;
  while (q--) {
    long long i = l;
    cin >> l >> r >> d;
    if (l != d && l / d >= 1)
      cout << d << endl;
    else
      cout << (r / d + 1) * d << endl;
  }
  return 0;
}
