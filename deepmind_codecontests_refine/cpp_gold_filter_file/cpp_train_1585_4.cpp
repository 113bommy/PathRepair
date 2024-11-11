#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int i, n, c = 0, od = 0;
    cin >> n;
    string s;
    cin >> s;
    for (int i = n - 1; i >= 0; i--) {
      if (int(s[i] - '0') % 2 != 0) {
        od++;
      }
    }
    for (i = n - 1; i >= 0; i--) {
      if (int(s[i] - '0') % 2 == 0) {
        s[i] = 'k';
        c++;
      } else {
        if (od % 2 == 0) {
          break;
        } else {
          s[i] = 'k';
          c++;
          od--;
          if (i != 0 && int(s[i - 1] - '0') % 2 == 0) {
            continue;
          } else
            break;
        }
      }
    }
    if (c == n) {
      cout << "-1" << endl;
    } else {
      for (i = 0; i < n; i++) {
        if (s[i] != 'k') cout << s[i];
      }
      cout << endl;
    }
  }
}
