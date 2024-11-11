#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int ans, n, first, last, t;
  string s;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> s;
    long long int flag = 1;
    ans = n;
    first = last = -1;
    for (long long int i = 0; i < n; i++)
      if (s[i] == '1') {
        if (flag) {
          first = i;
          flag = 0;
        }
        last = i;
      }
    if (first != -1)
      ans = n + 1;
    else {
      cout << ans << endl;
      continue;
    }
    cout << max(ans, max(2 * (n - first), 2 * (last + 1))) << endl;
  }
  return 0;
}
