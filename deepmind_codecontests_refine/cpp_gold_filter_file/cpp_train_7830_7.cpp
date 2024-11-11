#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int l = 0, r = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(')
      l++;
    else
      r++;
  }
  if (l != r)
    cout << "-1";
  else {
    int a = 0, b = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '(')
        a++;
      else
        b++;
      if (b > a) {
        int tmp = 1;
        for (int j = i + 1; j < n; ++j) {
          if (s[j] == ')')
            b++;
          else
            a++;
          tmp++;
          if (a == b) {
            i = j;
            break;
          }
        }
        ans += tmp;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
