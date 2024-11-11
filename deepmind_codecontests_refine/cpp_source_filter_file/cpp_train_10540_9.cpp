#include <bits/stdc++.h>
using namespace std;
vector<string> ans;
int main() {
  string s;
  cin >> s;
  int len = s.length();
  int a, b, c, x;
  a = b = c = 0;
  for (int i = 0; i < len; i++) {
    a += s[i] == '1';
    b += s[i] == '0';
    c += s[i] == '?';
  }
  if (b + c > a) ans.push_back("00");
  if (a + c > b + 1) ans.push_back("11");
  if (s[len - 1] == '0') {
    x = (c + a - b + len % 2) / 2;
    if (x >= 0 && c - x >= 0)
      ans.push_back("10");
    else {
      x = (c + b - a + len % 2) / 2;
      if (x >= 0 && c - x >= 0) ans.push_back("10");
    }
  } else if (s[len - 1] == '1') {
    x = (c + a - b + len % 2) / 2;
    if (x >= 0 && c - x >= 0)
      ans.push_back("01");
    else {
      x = (c + b - a + len % 2) / 2;
      if (x >= 0 && c - x >= 0) ans.push_back("01");
    }
  } else {
    c--, b++;
    x = (c + a - b + len % 2) / 2;
    if (x >= 0 && c - x >= 0)
      ans.push_back("10");
    else {
      x = (c + b - a + len % 2) / 2;
      if (x >= 0 && c - x >= 0) ans.push_back("10");
    }
    b--, a++;
    x = (c + a - b + len % 2) / 2;
    if (x >= 0 && c - x >= 0)
      ans.push_back("01");
    else {
      x = (c + b - a + len % 2) / 2;
      if (x >= 0 && c - x >= 0) ans.push_back("01");
    }
  }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << "\n";
  return 0;
}
