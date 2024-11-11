#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int tc;
  cin >> tc;
  while (tc--) {
    long long int a, b, c;
    cin >> a >> b >> c;
    long long int n = a + b + c;
    long long int x, y, z;
    cin >> x >> y >> z;
    long long int gain = min(c, y);
    c -= gain;
    y -= gain;
    n -= gain;
    long long int loss = 0;
    if (z > 0) {
      z -= min(c, z);
      c -= min(c, z);
      z -= min(a, z);
      a -= min(a, z);
    }
    loss = z;
    cout << abs(gain - loss) * 2 << endl;
  }
  return 0;
}
