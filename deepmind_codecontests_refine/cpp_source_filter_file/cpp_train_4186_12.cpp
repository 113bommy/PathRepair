#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int l, mx = 0, flag = 0;
    cin >> l;
    string s;
    cin >> s;
    for (int i = 0; s[i]; i++) {
      if (s[i] == '1') {
        mx = max(i, mx);
        flag = 1;
      }
    }
    if (flag == 0) {
      cout << l << endl;
      continue;
    }
    for (int i = l - 1; i >= 0; i--) {
      if (s[i] == '1') mx = max(l - 1 - i, mx);
    }
    if (mx > (l / 2))
      cout << 2 * (mx + 1) << endl;
    else
      cout << l + 1 << endl;
  }
  return 0;
}
