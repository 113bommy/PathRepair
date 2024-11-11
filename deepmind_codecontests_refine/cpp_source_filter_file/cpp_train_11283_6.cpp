#include <bits/stdc++.h>
using namespace std;
int main() {
  long int n, m, k, l, ans, sum, i;
  cin >> n >> k;
  sum = 0;
  for (i = 0; i < n; i++) {
    cin >> l >> m;
    sum = sum + m - l + 1;
  }
  ans = 0;
  if (sum == k) {
    ans = 0;
  } else if (sum > k) {
    while (sum % k != 0) {
      ans++;
      sum++;
    }
  } else {
    ans = sum % k;
  }
  cout << ans << endl;
  return 0;
}
