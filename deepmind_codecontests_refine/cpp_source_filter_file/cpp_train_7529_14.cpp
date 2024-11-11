#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int x;
      cin >> x;
      if (i == j || i == n - j + 1 || i == n / 2 || j == n / 2) {
        ans += x;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
