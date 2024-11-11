#include <bits/stdc++.h>
using namespace std;
int main() {
  string str, res;
  cin >> str >> res;
  int ans = 0;
  string Res, Str;
  Res = res;
  Str = str;
  for (int i = 1; i <= 10; i++) {
    str = Str;
    res = Res;
    int F1 = 0, F2 = 0;
    for (int j = 0; j < str.length(); j++) {
      if (str[j] - '0' >= i) F1 = 1;
    }
    for (int j = 0; j < res.length(); j++) {
      if (res[j] - '0' >= i) F2 = 1;
    }
    if (F1 | F2) continue;
    int l1 = str.length();
    int l2 = res.length();
    for (int j = 0; j < max(0, l2 - l1); j++) str = '0' + str;
    for (int j = 0; j < max(0, l1 - l2); j++) res = '0' + res;
    int carry = 0;
    int maxi = max(l1, l2);
    int Ans = 0;
    string s;
    for (int j = 0; j < maxi; j++) {
      int val = str[maxi - j - 1] - '0' + res[maxi - j - 1] - '0' + carry;
      stringstream ss;
      ss << (val % i);
      ss >> s;
      Ans += s.length();
      carry = val / i;
    }
    if (carry) {
      stringstream ss;
      ss << carry;
      ss >> s;
      Ans += s.length();
    }
    ans = max(Ans, ans);
  }
  cout << ans << endl;
  return 0;
}
