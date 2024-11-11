#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  if ((n == 0) && (n == 1)) {
    cout << '0';
  }
  if (n > 1) {
    long long d1 = 0, ned1 = 0, d2 = 0, ned2 = 0;
    ned1 = 3;
    d1 = 0;
    for (int i = 1; i < n - 1; i++) {
      ned2 = (ned1 * 2 + d1 * 3) % 1000000007;
      d2 = (ned1) % 1000000007;
      d1 = (d2) % 1000000007;
      ned1 = (ned2) % 1000000007;
    }
    cout << ned1;
  }
  return 0;
}
