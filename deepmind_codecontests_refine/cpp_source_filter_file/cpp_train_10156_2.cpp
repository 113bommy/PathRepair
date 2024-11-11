#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int tmp = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] != 'a') {
      s[i]--;
      tmp++;
    }
    if (s[i] == 'a' && tmp > 0) {
      cout << s << endl;
      return 0;
    }
  }
  if (tmp == 0) {
    s[s.length() - 1] = 'z';
    cout << s << endl;
    return 0;
  }
  cout << s << endl;
  return 0;
}
