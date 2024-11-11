#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, i, j, a = 0, b = 0;
    string s;
    bool check = false, flag = true;
    cin >> n >> s;
    for (i = 0; i < n; i++) {
      if (s[i] == '1' && flag) {
        a = i;
        b = a;
        flag = false;
        check = true;
      } else if (s[i] == '1') {
        b = i;
      }
    }
    if (check)
      cout << 2 * max(n - a, b + 1) << "\n";
    else {
      cout << n << "\n";
    }
  }
}
