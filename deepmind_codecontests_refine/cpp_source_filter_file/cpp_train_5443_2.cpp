#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long l, r;
    cin >> l >> r;
    if (r % (2 * l) >= l)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
