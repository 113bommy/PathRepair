#include <bits/stdc++.h>
using namespace std;
long long n, a, b, c;
int main() {
  cin >> n >> a >> b >> c;
  long long ans = 1e18;
  if (n % 4 == 0) {
    ans = 0;
  } else if (n % 4 == 3) {
    ans = min(ans, a);
    ans = min(ans, 3 * c);
    ans = min(ans, b + c);
  } else if (n % 4 == 2) {
    ans = min(ans, 2 * a);
    ans = min(ans, b);
    ans = min(ans, 2 * c);
  } else if (n % 4 == 1) {
    ans = min(ans, b);
    ans = min(ans, 3 * a);
    ans = min(ans, a + b);
  }
  cout << ans << endl;
  return 0;
}
