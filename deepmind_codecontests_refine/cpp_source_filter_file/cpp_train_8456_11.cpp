#include <bits/stdc++.h>
long long int modinverse(long long int x, long long int y) {
  long long int res = 1;
  x = x % 1000000007;
  while (y > 0) {
    if (y & 1) res = (res * x) % 1000000007;
    y = y >> 1;
    x = (x * x) % 1000000007;
  }
  return res;
}
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long int n;
  long long int T;
  cin >> T;
  while (T--) {
    cin >> n;
    int k, a;
    for (k = (2); k <= (28); ++k) {
      a = pow(2, k) - 1;
      if (n % a == 0) break;
    }
    if (n / a > 0)
      cout << n / a << '\n';
    else
      cout << -1 << '\n';
  }
  return 0;
}
