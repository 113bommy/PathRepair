#include <bits/stdc++.h>
using namespace std;
string s[1005];
bool check(char x, char y) {
  if (isalpha(x)) x = tolower(x);
  if (isalpha(y)) y = tolower(y);
  if (x == '0' && y == 'o' || x == 'o' && y == '0') return true;
  if (x == '1' && y == 'l' || x == '1' && y == 'i' || x == 'l' && y == 'i' ||
      x == 'l' && y == '1' || x == 'i' && y == '1' || x == 'l' && y == 'i')
    return true;
  return false;
}
bool judge(char x, char y) {
  if (isalpha(x)) x = tolower(x);
  if (isalpha(y)) y = tolower(y);
  if (x == y) return 1;
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int i = 0, flag = 0, n;
  string t;
  cin >> t >> n;
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++) {
    if (s[i].size() == t.size()) {
      int cnt = 0;
      for (int k = 0; k < s[i].size(); k++) {
        if (judge(s[i][k], t[k]))
          cnt++;
        else {
          if (check(s[i][k], t[k]))
            cnt++;
          else
            break;
        }
      }
      if (cnt == s[i].size()) flag = 1;
    }
  }
  if (flag)
    puts("No");
  else
    puts("Yes");
  return 0;
}
