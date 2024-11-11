#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int c = 1, i = 0, j = 1, main_c = 0, ans = 0;
  int length = 0;
  cin >> s;
  length = s.size();
  while (length) {
    if (s[i] == s[j]) {
      c++;
      j++;
    } else {
      i = j;
      j++;
      main_c = c;
      if (!main_c % 2) {
        ans++;
      }
      c = 1;
    }
    length--;
  }
  cout << ans;
  return 0;
}
