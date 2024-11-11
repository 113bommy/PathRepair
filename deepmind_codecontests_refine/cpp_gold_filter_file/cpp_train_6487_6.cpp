#include <bits/stdc++.h>
using namespace std;
const long long int q = 1e9 + 7;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  long long int ans = 1;
  if (k > n || k == 1) {
    ans = 1;
    for (int i = 1; i <= n; i++) {
      ans = (ans * m) % q;
    }
  } else if (k % 2 == 0) {
    if (k == n) {
      for (int i = 1; i <= n / 2; i++) {
        ans = (ans * m) % q;
      }
    } else {
      ans = m;
    }
  } else if (k % 2 == 1) {
    if (k == n) {
      for (int i = 1; i <= n / 2 + 1; i++) {
        ans = (ans * m) % q;
      }
    } else {
      ans = m * m;
    }
  }
  cout << ans << "\n";
  return 0;
}
