#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int ans = 0;
  int n, m, k;
  cin >> n >> m >> k;
  if (k == 1 || k > n) {
    ans = 1;
    for (int i = 0; i < n; i++) {
      ans = ans * m;
      ans %= 1000 * 1000 * 1000 + 7;
    }
  } else if (k == n) {
    ans = 1;
    for (int i = 0; i < n / 2 + n % 2; i++) {
      ans = ans * m;
      ans %= 1000 * 1000 * 1000 + 7;
    }
  } else if (k % 2) {
    ans = m * m;
  } else {
    ans = m;
  }
  cout << ans;
  return 0;
}
