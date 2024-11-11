#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int t = -1;
  for (int i = 0; i < s.size(); i++)
    if (s[i] == '.') {
      t = i;
      break;
    }
  if (t == -1) {
    if (s[(s.size()) - 1] == '9') {
      cout << "GOTO Vasilisa" << endl;
      return 0;
    }
    cout << s << endl;
    return 0;
  }
  if (t != 0 && s[t - 1] == '9') {
    cout << "GOTO Vasilisa" << endl;
    return 0;
  }
  if (s[t + 1] != '5' && s[t + 1] != '6' && s[t + 1] != '7' &&
      s[t + 1] != '8' && s[t + 1] != '9') {
    for (int i = 0; i < t; i++) cout << s[i];
    cout << endl;
    return 0;
  }
  int hey = t;
  t--;
  while (s[t] == '9' && t >= 0) {
    s[t] = '0';
    t--;
  }
  if (t == -1) {
    cout << 1;
    for (int i = 0; i < hey; i++) cout << s[i];
    cout << endl;
    return 0;
  }
  s[t]++;
  for (int i = 0; i < hey; i++) cout << s[i];
  cout << endl;
  return 0;
}
