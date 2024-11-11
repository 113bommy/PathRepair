#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int len = s.length();
  int pos1 = -1;
  int pos2 = -1;
  int pos3 = -1;
  for (int i = 0; i < len; i++)
    if (s[i] != '0' && s[i] != '.') {
      pos1 = i;
      break;
    }
  for (int j = len - 1; j >= 0; j--)
    if (s[j] != '0' && s[j] != '.') {
      pos2 = j;
      break;
    }
  for (int t = 0; t < len; t++)
    if (s[t] == '.') {
      pos3 = t;
      break;
    }
  if (pos1 == -1 && pos2 == -1)
    cout << "0" << endl;
  else if (pos3 == -1) {
    cout << s[pos1];
    if (pos2 - pos1 >= 1) cout << ".";
    for (int w = pos1 + 1; w <= pos2; w++) cout << s[w];
    if (len - pos1 - 1 != 0) cout << "E" << len - pos1 - 1 << endl;
  } else if (pos3 < pos1) {
    cout << s[pos1];
    if (pos2 - pos1 > 1) cout << ".";
    for (int w = pos1 + 1; w <= pos2; w++) cout << s[w];
    if (pos1 - pos3 != 0) cout << "E-" << pos1 - pos3 << endl;
  } else if (pos3 > pos2) {
    cout << s[pos1];
    if (pos2 - pos1 > 1) cout << ".";
    for (int w = pos1 + 1; w <= pos2; w++) cout << s[w];
    if (pos3 - pos1 - 1 != 0) cout << "E" << pos3 - pos1 - 1 << endl;
  } else if (pos3 > pos1 && pos3 < pos2) {
    cout << s[pos1] << ".";
    for (int w = pos1 + 1; w <= pos2; w++) {
      if (s[w] != '.') cout << s[w];
    }
    if (pos3 - pos1 - 1 != 0) cout << "E" << pos3 - pos1 - 1 << endl;
  }
  return 0;
}
