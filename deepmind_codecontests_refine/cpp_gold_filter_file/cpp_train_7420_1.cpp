#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  cin >> n >> m;
  if (n > m) swap(n, m);
  if (n == 1) {
    cout << m;
    return 0;
  }
  int ans = 0;
  if (n == 2) {
    ans = max(4, m);
    if (m > 4) {
      ans = max(ans, m / 4 * 4 + min(2, m % 4) * 2);
    }
  }
  if (n >= 3) {
    ans = max(4, m);
    if (m >= 3) {
      ans = max(ans, (m * n + 1) / 2);
    }
  }
  cout << ans;
}
