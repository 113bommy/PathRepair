#include <bits/stdc++.h>
using namespace std;
void test_case() {
  int n, s;
  cin >> n >> s;
  if (s == 0 && n > 1 || s > n * 9) {
    cout << "-1 -1\n";
    return;
  }
  int am9 = (s - 1) / 9;
  string ans = "";
  for (int i = 1; i <= n; i++) {
    if (i <= am9)
      ans += '9';
    else if (i == am9 + 1 && i == n)
      ans += (s - am9 * 9) + '0';
    else if (i == am9 + 1 && i != n)
      ans += (s - am9 * 9 - 1) + '0';
    else if (i > am9 + 1 && i != n)
      ans += '0';
    else
      ans += '1';
  }
  reverse(ans.begin(), ans.end());
  cout << ans << " ";
  am9 = s / 9;
  ans = "";
  for (int i = 1; i <= n; i++) {
    if (i <= am9)
      ans += '9';
    else if (i == am9 + 1)
      ans += (s - am9 * 9) + '0';
    else
      ans += '0';
  }
  cout << ans << "\n";
}
int main() {
  int t = 1;
  while (t--) {
    test_case();
  }
  return 0;
}
