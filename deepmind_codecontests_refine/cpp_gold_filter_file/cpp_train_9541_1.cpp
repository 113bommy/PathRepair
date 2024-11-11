#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  string ans;
  int sz = s.size();
  bool pa = true;
  for (int i = 0, j = sz - 1; i < j; i++, j--) {
    if (s[i] != s[j]) {
      pa = false;
      break;
    }
  }
  if (pa) {
    cout << s << "\n";
    return 0;
  }
  string ans_left, ans_right;
  for (int i = 0, j = sz - 1; i <= j; i++, j--) {
    if (s[i] == s[j]) {
      ans_left += s[i];
      ans_right = s[j] + ans_right;
    } else {
      ans_left += s[i];
      ans_left += s[j];
      ans_right = s[i] + ans_right;
      ans_right = s[j] + ans_right;
    }
  }
  cout << ans_left + ans_right << "\n";
}
