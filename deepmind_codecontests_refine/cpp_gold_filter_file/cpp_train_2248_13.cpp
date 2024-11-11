#include <bits/stdc++.h>
using namespace std;
string s;
int k;
bool ch(int len) {
  int cur = 0, num = 0;
  int i = 0, c = 1;
  while (i < s.length()) {
    while (i != s.length() && s[i] != '-' && s[i] != ' ') {
      i++;
      c++;
    }
    if (i == s.length()) c--;
    if (c > len) return false;
    if (c <= len - cur) {
      cur += c;
      if (num == 0) num = 1;
      i++;
      c = 1;
    } else {
      num++;
      i++;
      cur = c;
      c = 1;
    }
  }
  if (num <= k) return true;
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> k;
  getline(cin, s);
  getline(cin, s);
  int l = 1, r = s.length();
  while (r - l > 1) {
    int mid = (r + l) / 2;
    if (ch(mid))
      r = mid;
    else
      l = mid;
  }
  if (ch(l))
    cout << l;
  else
    cout << l + 1;
  return 0;
}
