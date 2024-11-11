#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7, N = 1e6 + 60;
bool isPalindrome(string s) {
  for (int i = 0; i < s.length(); i++) {
    if (s[i] != s[s.length() - 1 - i]) return false;
  }
  return true;
}
bool solve(string s) {
  string t = s;
  for (int i = 0; i < s.length(); i++) {
    t = t.back() + t;
    t.pop_back();
    if (s != t && isPalindrome(t)) {
      return true;
    }
  }
  return false;
}
void solve() {
  string s;
  cin >> s;
  int nt = 0;
  for (int i = 0; i < s.length(); i++) {
    nt += (s[i] != s[0]);
  }
  if (nt > 1) {
    cout << (solve(s) ? 1 : 2);
  } else {
    cout << "Imposible";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tt = 1;
  while (tt--) solve();
}
