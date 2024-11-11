#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  bool isMagic = true;
  int i = 0;
  for (i = 0; i < s.size(); i++) {
    if (s[0] == '4') {
      isMagic = false;
      break;
    } else if (s[i] == '1')
      continue;
    else if (s[i] == '4') {
      int consec_four = 0;
      while (i < s.size() && s[i] == '4') {
        consec_four++;
        i++;
      }
      if (consec_four > 2) {
        isMagic = false;
        break;
      }
    } else {
      isMagic = false;
      break;
    }
  }
  if (isMagic)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
