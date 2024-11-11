#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int i = 0, x = -1, ans = 0;
  while (i < s.length()) {
    if (s[i] % 3 == 0) {
      x = i;
      ans++;
    } else {
      int j = i, sum = 0;
      while (j > x) {
        sum += s[j];
        if (sum % 3 == 0) {
          j = x;
          x = i;
          ans++;
        }
        j--;
      }
    }
    i++;
  }
  cout << ans << endl;
}
