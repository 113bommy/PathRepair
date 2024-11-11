#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, a, b;
  cin >> n >> k >> a >> b;
  if (k == 1) {
    cout << (n - 1) * a;
    return 0;
  }
  long long res = 0;
  while (n > 1) {
    if (n % k == 0) {
      if (n / k == 1) {
        res += min(b, a * (k - 1));
        n = 1;
      } else {
        res += min(b, a * (n - n / k));
        n /= k;
      }
    } else {
      if (n > k) {
        res += (n % k) * a;
        n = n - n % k;
      } else {
        res += (n % k - 1) * a;
        n = 1;
      }
    }
  }
  cout << res;
  return 0;
}
