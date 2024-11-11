#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans = 0;
  cin >> n;
  ans += n;
  for (int i = 2; i <= n - 1; i++) {
    if (n % i == 0) {
      n /= i;
      ans += n;
      i = 1;
    }
  }
  cout << ans + 1;
  return 0;
}
