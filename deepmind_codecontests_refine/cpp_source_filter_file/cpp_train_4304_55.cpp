#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << "1";
    return 0;
  }
  long long cd = n * 3 - 2, ans = 0;
  for (int i = 1; i <= cd; i++) {
    ans += i;
  }
  ans *= 2;
  for (int i = 1; i <= n; i++) {
    ans -= i + 1;
  }
  for (int i = n - 1; i >= 1; i--) {
    ans -= i + 1;
  }
  cout << ans;
  return 0;
}
