#include <bits/stdc++.h>
using namespace std;
long long C(long long n, long long k) {
  long long ans = 1;
  k = k > n - k ? n - k : k;
  long long j = 1;
  for (; j <= k; j++, n--) {
    if (n % j == 0) {
      ans *= n / j;
    } else if (ans % j == 0) {
      ans = ans / j * n;
    } else {
      ans = (ans * n) / j;
    }
  }
  return ans;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;
    long long a1 = a, b1 = b, x1 = x, y1 = y, n1 = n;
    long long ans;
    long long c;
    c = min(n, a - x);
    a -= c;
    n -= c;
    if (n) {
      c = min(n, b - y);
      b -= c;
    }
    ans = a * b;
    c = min(n1, a1 - x1);
    a1 -= c;
    n1 -= c;
    if (n1) {
      c = min(n1, b1 - y1);
      b1 -= c;
    }
    ans = min(ans, a1 * b1);
    cout << ans << '\n';
  }
}
