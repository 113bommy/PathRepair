#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int k;
  while (cin >> s >> k) {
    int len = s.length();
    int ans = 0;
    for (int i = 1; i <= len + k; i++) {
      for (int j = 0; j + 2 * i <= len + k; j++) {
        bool flag = 0;
        for (int p = j; p <= i; p++) {
          if (p + i >= len) {
            break;
          }
          if (s[p] != s[p + i]) {
            flag = 1;
            break;
          }
        }
        if (!flag) {
          ans = i * 2;
          break;
        }
      }
    }
    cout << ans << endl;
  }
}
