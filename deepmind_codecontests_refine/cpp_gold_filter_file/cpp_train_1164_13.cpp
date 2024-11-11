#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  string ss, ans = "";
  cin >> ss;
  if (k == 0) {
    cout << ss << endl;
    return 0;
  }
  string s = "#";
  s += ss;
  for (int i = 1; i <= n && k > 0; i++) {
    if (s[i] != '4')
      continue;
    else if (s[i] == '4' && s[i + 1] != '7')
      continue;
    else {
      if (i % 2 == 1) {
        if (s[i + 2] != '7') {
          k--;
          s[i] = '4', s[i + 1] = '4';
          i++;
          continue;
        } else {
          if (k % 2 == 0)
            break;
          else {
            s[i] = '4', s[i + 1] = '4', s[i + 2] = '7';
            break;
          }
        }
      }
      if (i % 2 == 0) {
        if (s[i - 1] != '4') {
          k--;
          s[i] = '7', s[i + 1] = '7';
          i++;
          continue;
        } else {
          if (k % 2 == 0)
            break;
          else {
            s[i] = '7';
            break;
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) ans += s[i];
  cout << ans << endl;
  return 0;
}
