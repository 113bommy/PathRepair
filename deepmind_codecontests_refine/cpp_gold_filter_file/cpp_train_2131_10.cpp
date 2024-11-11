#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long x;
  cin >> x;
  for (long long i = 1; i <= 50; i++) {
    long long val = abs(x + i);
    while (val != 0) {
      if (val % 10 == 8) {
        cout << i;
        return 0;
      }
      val /= 10;
    }
  }
  return 0;
}
