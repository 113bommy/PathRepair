#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string fun(string s, string t) {
  int n = s.length();
  string ans = "";
  int ind;
  for (int i = 0; i < n; i++) {
    if (s[i] == t[i])
      ans += s[i];
    else {
      ind = i;
      break;
    }
  }
  if (t[ind] - s[ind] > 1) {
    char ch = s[ind] - 'a' + 98;
    ans += ch;
    for (int i = ind + 1; i < n; i++) ans += 'a';
    return ans;
  }
  if (ind == n - 1) return "No such string";
  bool fir = false;
  bool sec = false;
  for (int i = ind + 1; i < n; i++) {
    if (s[i] != 'z') {
      fir = true;
      break;
    }
  }
  if (fir) {
    ans += s[ind];
    for (int i = ind + 1; i < n; i++) ans += 'z';
    return ans;
  }
  for (int i = ind + 1; i < n; i++) {
    if (t[i] != 'a') {
      sec = true;
      break;
    }
  }
  if (sec) {
    ans += t[ind];
    for (int i = ind + 1; i < n; i++) ans += 'a';
    return ans;
  }
  return "No such string";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s, t;
  cin >> s >> t;
  cout << fun(s, t);
}
