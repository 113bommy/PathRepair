#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, str[1010], ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> str[i];
  if (n < 3 || n & 1 == 0) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = n - 1; i > 1; i -= 2) {
    int m = max(str[i], str[i - 1]);
    ans += m;
    str[i] = 0;
    str[i - 1] = 0;
    if (m < str[(i - 1) / 2])
      str[(i - 1) / 2] -= m;
    else
      str[(i - 1) / 2] = 0;
  }
  ans += max(str[0], str[1]);
  cout << ans << endl;
  return 0;
}
