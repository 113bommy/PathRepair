#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, x, y, k, a = 0;
  cin >> t;
  for (long long rep = 1; rep <= t; rep++) {
    a = 0;
    cin >> x >> y >> k;
    a = (k * (y + 1) - 1 + (x - 2)) / (x - 1);
    cout << a + k;
  }
}
