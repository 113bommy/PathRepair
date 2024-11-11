#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int str, intl, exp, cnt = 0;
    cin >> str >> intl >> exp;
    if (str + exp <= intl) {
      cout << 1 << "\n";
      continue;
    }
    if (exp == 0) {
      cout << 1 << "\n";
      continue;
    }
    if (str - intl > exp) {
      cout << exp + 1 << "\n";
      continue;
    } else {
      int res = str + exp;
      cnt = (res - intl + 1) / 2;
      cout << cnt << "\n";
    }
  }
  return 0;
}
