#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b, c;
    cin >> a >> b >> c;
    if (a < c)
      cout << 1 << " ";
    else
      cout << -1 << " ";
    if ((a * b) > c)
      cout << b << endl;
    else
      cout << -1 << endl;
  }
}
