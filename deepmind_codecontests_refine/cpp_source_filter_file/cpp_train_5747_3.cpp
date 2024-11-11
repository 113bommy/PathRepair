#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  long long mn = 1;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      mn = i;
      break;
    }
  }
  if (mn == 1) {
    cout << n << '\n';
    return 0;
  }
  long long tmp = n;
  while (n % mn == 0) {
    n /= mn;
  }
  if (n == 1) {
    cout << tmp / mn << '\n';
    return 0;
  }
  cout << 1 << '\n';
  return 0;
}
