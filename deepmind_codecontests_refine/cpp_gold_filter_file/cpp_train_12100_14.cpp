#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long x, y, a, b;
    cin >> x >> y >> a >> b;
    if (((x - y) % (a + b)) == 0) {
      cout << labs(x - y) / (a + b) << endl;
    } else {
      cout << "-1" << endl;
    }
  }
  return 0;
}
