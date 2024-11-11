#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n, k;
  cin >> n >> k;
  int64_t r = n % (2 * k + 1);
  int64_t q = 0;
  int64_t ans = (n - 1) / (2 * k + 1) + 1;
  if (r == 0) {
    q = k;
    goto print;
  }
  if (r > k) {
    q = k;
    goto print;
  }
  if (r <= k) {
    q = k + 1 - r;
    goto print;
  }
print:
  cout << ans << endl;
  while (n > q) {
    cout << q + 1 << ' ';
    q += 2 * k + 1;
  }
  return 0;
}
