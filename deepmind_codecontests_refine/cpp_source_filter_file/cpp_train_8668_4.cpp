#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  long long x, y, k;
  while (t--) {
    cin >> x >> y >> k;
    long long count = 0;
    if (x >= k + y * k) {
      cout << 2 << endl;
      continue;
    }
    count = ((k + y * k - x) / (x - 1)) + 1;
    if ((k + y * k - x) % (x - 1) == 0) {
      cout << count + k << endl;
    } else {
      cout << count + k + 1 << endl;
      ;
    }
  }
  return 0;
}
