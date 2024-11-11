#include <bits/stdc++.h>
using namespace std;
unordered_map<char, int> mm;
int main() {
  string str = "abcdefghijklmnopqrstuvwxyz";
  string s;
  string p;
  int i, j, k, l, len, temp, d;
  cin >> k;
  cin >> s;
  len = s.size();
  int flag = 1;
  for (i = 0; i < len; i++) mm[s[i]]++;
  for (i = 0; i < 26; i++) {
    if (mm[str[i]] != 0) {
      temp = mm[str[i]];
      if (temp % k == 0) {
        d = temp / k;
        while (d--) p += str[i];
      } else {
        flag = 0;
        break;
      }
    }
  }
  if (flag == 0)
    cout << -1 << endl;
  else {
    while (k--) cout << p;
    cout << endl;
  }
  return 0;
}
