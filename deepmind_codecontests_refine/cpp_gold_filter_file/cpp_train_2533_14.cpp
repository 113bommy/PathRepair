#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin >> n;
  int ans = 0, c = n;
  while (c != 1) {
    ans += c;
    for (int i = 2; i <= n; i++) {
      if (n % i == 0) {
        c = n / i;
        n = c;
        break;
      }
    }
  }
  ans++;
  cout << ans;
  cin >> n;
  return 0;
}
