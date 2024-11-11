#include <bits/stdc++.h>
using namespace std;
long long tell(long long n, long long nn) {
  if (nn == n) return 1;
  long long ans = 0;
  long long u = 2 * nn;
  long long uu = u - 1;
  long long uy = u / 10;
  long long k;
  for (k = nn; k <= n; k += u) {
    if (k + u <= n) {
      ans = ans + (((k / u) + 1) * u) - 1;
    }
  }
  k -= u;
  ans = ans + ((k / u) + 1) * (n - k + 1);
  if (k + nn - 1 <= n) {
    ans--;
  }
  return ans;
}
int main() {
  long long n, ans = 0, nn;
  cin >> n;
  if (n < 5) {
    ans = (n * (n - 1)) / 2;
    cout << ans;
    return 0;
  } else if (n >= 500000000) {
    nn = 500000000;
  } else if (n >= 50000000) {
    nn = 50000000;
  } else if (n >= 5000000) {
    nn = 5000000;
  } else if (n >= 500000) {
    nn = 500000;
  } else if (n >= 50000) {
    nn = 50000;
  } else if (n >= 5000) {
    nn = 5000;
  } else if (n >= 500) {
    nn = 500;
  } else if (n >= 50) {
    nn = 50;
  } else if (n >= 5) {
    nn = 5;
  }
  cout << tell(n, nn) << endl;
  return 0;
}
