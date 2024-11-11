#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long n;
  cin >> n;
  if (n % 2) {
    cout << 0;
    return 0;
  }
  long long ans = pow(2, n / 2);
  cout << ans;
  return 0;
}
