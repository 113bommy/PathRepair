#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, ans;
  cin >> n >> k;
  if (n % 2 == 0) {
    if (k <= n / 2) {
      ans = 2 * k - 1;
    } else {
      ans = 2 * k - n;
    }
  } else {
    if (k <= (n / 2) + 1) {
      ans = 2 * k - 1;
    } else {
      ans = 2 * k - n - 1;
    }
  }
  cout << ans;
  return 0;
}
