#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c, a2, b2, c2;
    cin >> a >> b >> c >> a2 >> b2 >> c2;
    long long sum = 0;
    c2 = max((long long)0, (c2 - a));
    if (c != 0) {
      sum = sum + ((min(c, b2)) * 2);
      b2 -= min(c, b2);
    }
    b = max((long long)0, (b - (b2 + a2)));
    if (b > 0) {
      sum = sum - min(b, c2) * 2;
    }
    cout << sum;
    cout << endl;
  }
  return 0;
}
