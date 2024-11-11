#include <bits/stdc++.h>
using namespace std;
int64_t t, x, y, k;
int main() {
  cin >> t;
  while (t--) {
    cin >> x >> y >> k;
    int64_t all = k * (y + 1) - 1, st = x - 1;
    cout << (all / st) + k + (all % st != 0);
    cout << endl;
  }
  return 0;
}
