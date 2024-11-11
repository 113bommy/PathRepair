#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, flag = 0, j, m = -1, ans = 0, count = 0;
  cin >> n;
  string s, str, str2, str3;
  cin >> s;
  for (long long i = 0; i < n; ++i) {
    if (s[i] == '(') flag = 1;
    if (s[i] == ')') flag = 0;
    if (flag == 0) {
      if (s[i] == ')') str2 += ')';
      str += s[i];
    }
    if (flag == 1) {
      if (s[i] == '(') str += '(';
      str2 += s[i];
    }
  }
  str += '_';
  for (long long i = 0; i < str.length(); ++i) {
    for (int j = i + 1; j < str.length(); j++) {
      if (str[i] == '_' || str[i] == ')') {
        if (str[j] == '_' || str[j] == '(') {
          ans = j - i - 1;
          break;
        }
      }
    }
    m = max(m, ans);
  }
  for (long long i = 0; i < str2.length(); ++i) {
    for (int j = i + 1; j < str2.length(); j++) {
      if (str2[i] == '(' || str2[i] == '_') {
        if (str2[j] != '_' && str2[j] != ')') str3 += str2[j];
        if (str2[j] == '_' || str2[j] == ')') break;
      }
    }
    int h = str3.length();
    if (h != 0) {
      count++;
      str3 = "";
    }
  }
  cout << m << " " << count << endl;
  return 0;
}
