#include <bits/stdc++.h>
using namespace std;
string t;
int num[10] = {0};
bool is_ok() {
  for (int i = 0; i < t.size(); i++) {
    if (num[t[i] - '0'] < 1) return 0;
    num[t[i] - '0']--;
  }
  return 1;
}
int main() {
  cin >> t;
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '9') {
      s[i] = '6';
    }
    if (s[i] == '5') {
      s[i] = '2';
    }
    num[s[i] - '0']++;
  }
  for (int i = 0; i < t.size(); i++) {
    if (t[i] == '9') {
      t[i] = '6';
    }
    if (t[i] == '5') {
      s[i] = '2';
    }
  }
  int ans = 0;
  while (1) {
    if (is_ok())
      ans++;
    else
      break;
  }
  printf("%d\n", ans);
  return 0;
}
