#include <bits/stdc++.h>
using namespace std;
unsigned long long n, k, a, b;
int main() {
  cin >> n >> k >> a >> b;
  if (k == 1 || k > n) {
    cout << n * a << endl;
  } else {
    unsigned long long ans = 0;
    while (n != 1 && n >= k) {
      if (n % k == 0) {
        unsigned long long t = n / k;
        if ((n - t) * a > b)
          ans += b;
        else
          ans += (n - t) * a;
        n = t;
      } else {
        unsigned long long t = n / k * k;
        ans += (n - t) * a;
        n = t;
      }
    }
    if (n != 1) ans += (n - 1) * a;
    cout << ans << endl;
  }
  return 0;
}
