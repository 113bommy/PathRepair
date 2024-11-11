#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  string s;
  cin >> s;
  int a[26] = {0};
  for (int i = 0; i < s.size(); i++) {
    a[s[i] % 97]++;
  }
  string ans = "";
  for (int i = 0; i < 26; i++) {
    if ((a[i] % k) != 0) {
      cout << -1;
      return 0;
    } else {
      if (a[i] != 0) {
        for (int j = 0; j < (a[i] / k); j++) ans += (char)(i + 97);
      }
    }
  }
  for (int i = 0; i < k; i++) cout << ans;
  return 0;
}
