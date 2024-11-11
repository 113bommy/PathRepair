#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long l, r;
    cin >> l >> r;
    if (2 * l > r)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
