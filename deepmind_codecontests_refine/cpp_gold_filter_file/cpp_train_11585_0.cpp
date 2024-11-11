#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b, temp, ans;
    cin >> a >> b;
    temp = abs(a - b);
    if (temp % 10 == 0) {
      ans = temp / 10;
      cout << ans << "\n";
    } else {
      ans = temp / 10 + 1;
      cout << ans << "\n";
    }
  }
  return 0;
}
