#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long n, k, a, b;
  cin >> n >> k >> a >> b;
  if (k == 1) {
    cout << a * (n - 1);
    return 0;
  }
  long long ans = 0;
  while (n > 1) {
    if (n % k == 0) {
      ans += min(a * (n - n / k), b);
      n /= k;
    } else {
      int next = (n / k) * k;
      if (next == 0) {
        next = 1;
      }
      ans += a * (n - next);
      n = next;
    }
  }
  cout << ans;
  return 0;
}
