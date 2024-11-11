#include <bits/stdc++.h>
using namespace std;
long long int t, x, y, a, b;
int main() {
  cin >> t;
  while (t--) {
    cin >> x >> y >> a >> b;
    if ((y - x) % (a + b) == 0)
      cout << (y - x) / (a + b) << endl;
    else
      cout << -1 << endl;
  }
}
