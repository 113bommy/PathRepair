#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int l, r, d;
    cin >> l >> r >> d;
    if (l > d)
      cout << d << endl;
    else
      cout << (r + d) - (r % d);
  }
  return 0;
}
