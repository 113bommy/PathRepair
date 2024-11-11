#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int len = s.length();
    int count;
    int ones[50], oneslen = 0;
    int temp = 0;
    for (int i = 0; i < len; i++) {
      count = 0;
      if (s[i] == '1') {
        for (int j = i; j < len; j++) {
          if (s[j] == '1')
            count++;
          else
            break;
        }
        if (count > 0) {
          ones[temp] = count;
          temp++;
          oneslen++;
          i += count;
        }
      }
    }
    int ans = 0;
    if (oneslen > 0) {
      for (int i = 0; i < oneslen; i++) {
        for (int j = 0; j < oneslen; j++) {
          if (ones[i] > ones[j]) {
            temp = ones[i];
            ones[i] = ones[j];
            ones[j] = temp;
          }
        }
      }
    }
    if (oneslen > 0) {
      for (int i = 0; i < oneslen; i += 2) {
        ans += ones[i];
      }
    }
    cout << ans << endl;
  }
  return 0;
}
