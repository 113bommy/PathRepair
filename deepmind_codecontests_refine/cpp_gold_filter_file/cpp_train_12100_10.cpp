#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b, x, y, sum;
    cin >> a >> b >> x >> y;
    sum = x + y;
    if ((b - a) % sum == 0) {
      cout << (b - a) / sum << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
