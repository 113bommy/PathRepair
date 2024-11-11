#include <bits/stdc++.h>
using namespace std;
long long a, b, sum;
bool check(long long x, long long y) {
  for (long long i = x; i >= 1; i--) {
    if (!(a % i) && a / i <= y) return true;
    if (!(b % i) && b / i <= y) return true;
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  while (cin >> a >> b) {
    sum = a + b;
    long long ans = 1e14;
    for (long long i = 1; i * i <= sum; i++) {
      if (!(sum % i)) {
        long long x = i, y = sum / i;
        if (check(x, y)) {
          ans = min(ans, 2 * (x + y));
        }
      }
    }
    cout << ans << endl;
  }
}
