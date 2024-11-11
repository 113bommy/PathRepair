#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  string t = "bear";
  int l = -1, r = -1, flag = 0;
  int n = s.length();
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (l >= i)
      ans += (n - r);
    else {
      flag = 0;
      for (int j = i; j < n - 3; j++) {
        if (s[j] == 'b' && s[j + 1] == 'e' && s[j + 2] == 'a' &&
            s[j + 3] == 'r')
          l = j, r = j + 3, flag = 1;
        if (flag == 1) break;
      }
      if (flag == 0) break;
      ans += (n - r);
    }
  }
  cout << ans << "\n";
  return 0;
}
