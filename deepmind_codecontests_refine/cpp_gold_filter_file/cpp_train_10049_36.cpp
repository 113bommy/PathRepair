#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, i, j, ans = 0, product = 1;
  ;
  cin >> n >> k;
  if (k >= n / 2) {
    cout << n * (n - 1) / 2;
    return 0;
  }
  for (i = 0; i < k; i++) {
    ans = ans + n - 1 - i;
  }
  ans = ans + (n - 2 * k) * (k);
  product = k * (k - 1) / 2;
  ans = ans + product;
  cout << ans;
}
