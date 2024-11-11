#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, n;
  cin >> a >> b >> n;
  string ans = to_string(-1);
  for (int i = 0; i <= 9; i++) {
    if ((a * 10 + i) % b == 0) {
      ans = to_string((a * 10 + i));
      for (int j = 1; j < n; j++) {
        ans += '0';
      }
      break;
    }
  }
  cout << ans;
  return 0;
}
