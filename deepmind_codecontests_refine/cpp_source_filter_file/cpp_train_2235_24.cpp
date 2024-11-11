#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int main() {
  string s, t;
  int maxi = 2, c = 0, x, tot = 0;
  cin >> s >> t;
  for (int i = 0; i < s.size(); i++) maxi = max(maxi, s[i] - '0');
  for (int i = 0; i < t.size(); i++) maxi = max(maxi, t[i] - '0' - 1);
  string ans;
  if (s.size() < t.size()) {
    for (int i = 0; i < t.size() - s.size(); i++) ans += '0';
    ans += s;
    s = ans;
    ans = "";
  }
  if (t.size() < s.size()) {
    for (int i = 0; i < s.size() - t.size(); i++) ans += '0';
    ans += t;
    t = ans;
    ans = "";
  }
  for (int i = s.size() - 1; i > -1; i--) {
    x = s[i] + t[i] + c - '0' - '0';
    c = x / maxi;
    x %= maxi;
    tot++;
  }
  if (c) tot++;
  cout << tot;
  return 0;
}
