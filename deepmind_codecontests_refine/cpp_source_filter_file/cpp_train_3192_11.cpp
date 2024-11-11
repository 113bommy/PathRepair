#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, flag = 0, p;
  string s;
  cin >> n;
  cin >> s;
  for (i = 1; i < s.size(); i++) {
    if (s[i] == s[i - 1] && s[i] != '?') {
      cout << "no";
      return 0;
    }
  }
  for (i = 0; i < s.size(); i++) {
    if (s[i] == '?') {
      flag++;
      p = i;
    }
  }
  if (flag > 1) {
    if (s[0] == '?' || s[n - 1] == '?') {
      cout << "yes";
      return 0;
    }
    for (i = 1; i < s.size() - 1; i++) {
      if (s[i] == '?' && (s[i - 1] == s[i + 1]) || s[i + 1] == '?') {
        cout << "yes";
        return 0;
      }
    }
    cout << "no";
    return 0;
  }
  if (flag == 1) {
    if (s[0] == '?' || s[n - 1] == '?') {
      cout << "yes";
      return 0;
    }
    if (s[p - 1] != s[p + 1]) {
      cout << "no";
      return 0;
    } else {
      cout << "yes";
      return 0;
    }
  } else {
    cout << "no";
  }
  return 0;
}
