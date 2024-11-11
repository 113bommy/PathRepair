#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  string res;
  int n0, n1, n2;
  while (t--) {
    cin >> n0 >> n1 >> n2;
    res = "";
    if (n1 == 0) {
      if (n0 > 0)
        for (int i = 0; i <= n0; i++) res += "0";
      if (n2 > 0)
        for (int i = 0; i <= n2; i++) res += "1";
      cout << res << endl;
      continue;
    }
    if (n1 % 2 == 0) res += "0", n1--;
    for (int i = 0; i <= n2; i++) res += "1";
    for (int i = 0; i <= n0; i++) res += "0";
    n1--;
    int c = 1;
    for (int i = 0; i < n1; i++) {
      res += char(c + '0');
      c ^= 1;
    }
    cout << res << endl;
  }
}
