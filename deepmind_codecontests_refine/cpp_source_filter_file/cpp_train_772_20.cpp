#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int k;
  cin >> s >> k;
  int len = s.length();
  int ans;
  for (int res = len + k; res >= 2 * k; res--) {
    if (res % 2) continue;
    int check = 0;
    for (int i = 0; i <= k + len - 1 - res + 1; i++) {
      int check2 = 0;
      int suc = 0;
      for (int j = i; j <= i + res / 2 - 1; j++) {
        if (j + res / 2 >= len) {
          suc = 1;
          break;
        }
        if (s[j] != s[j + res / 2]) {
          check2 = 1;
          break;
        }
      }
      if (suc || check2 == 0) {
        ans = res;
        check = 1;
        goto stop;
      }
    }
  }
stop:
  cout << ans << endl;
  return 0;
}
