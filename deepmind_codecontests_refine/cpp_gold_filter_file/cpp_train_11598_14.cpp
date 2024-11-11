#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int len = s.length();
  bool ismagic = true;
  for (int i = 0; i < len;) {
    if (s[i] == '1' & s[i + 1] == '4' && s[i + 2] == '4') {
      i += 3;
    } else if (s[i] == '1' && s[i + 1] == '4') {
      i += 2;
    } else if (s[i] == '1') {
      i++;
    } else {
      ismagic = false;
      break;
    }
  }
  if (ismagic == true)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
