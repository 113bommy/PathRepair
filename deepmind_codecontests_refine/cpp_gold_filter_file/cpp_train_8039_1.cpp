#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string s) {
  int i = 0;
  int j = s.size() - 1;
  while (i <= j) {
    if (s[i] != s[j]) {
      return false;
    }
    i++;
    j--;
  }
  return true;
}
string helper(string &s) {
  string ans;
  for (int i = s.size() - 1; ~i; i--) {
    if (isPalindrome(string(s.begin(), s.begin() + i + 1))) {
      if (i - 0 + 1 > ans.size()) {
        ans = string(s.begin(), s.begin() + i + 1);
      }
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s.size() == 1) {
      cout << s << endl;
      continue;
    }
    string ans;
    long long int i = 0;
    long long int j = (int)s.size() - 1;
    while (s[i] == s[j] && (i < j)) {
      ans += s[i];
      i++;
      j--;
    }
    string newString;
    if (i <= j) {
      newString = string(s.begin() + i, s.begin() + j + 1);
    }
    string ans1 = helper(newString);
    reverse(newString.begin(), newString.end());
    string ans2 = helper(newString);
    string x = ans;
    reverse(x.begin(), x.end());
    ans = ans + (ans1.size() > ans2.size() ? ans1 : ans2) + x;
    cout << ans << endl;
  }
  return 0;
}
