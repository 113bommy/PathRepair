#include <bits/stdc++.h>
using namespace std;
int main() {
  int l;
  cin >> l;
  string s;
  cin >> s;
  if (s.size() % l) {
    string ans = "1";
    for (int i = 1; i < l; i++) ans += "0";
    for (int i = 0; i < s.size() / l + 1; i++) {
      cout << ans;
    }
    cout << endl;
    return 0;
  }
  string ans = "";
  string final2 = "";
  for (int i = 0; i < l; i++) {
    ans += s[i];
  }
  for (int i = 0; i < s.size() / l; i++) final2 += ans;
  if (final2.compare(s) > 0) {
    cout << final2 << endl;
    return 0;
  }
  int index = l - 1;
  while (index > 0 && ans[index] == '9') {
    ans[index] = '0';
    index--;
  }
  if (index != 0) {
    ans[index] = ans[index] + 1;
  } else {
    ans = "1";
    for (int i = 1; i < l; i++) ans += "0";
    for (int i = 0; i < s.size() / l + 1; i++) cout << ans;
    cout << endl;
    return 0;
  }
  for (int i = 0; i < s.size() / l; i++) cout << ans;
  cout << endl;
}
