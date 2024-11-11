#include <bits/stdc++.h>
using namespace std;
int main() {
  string s[12];
  bool emp = false;
  int x, y;
  for (int i = 0; i < 11; i++) getline(cin, s[i]);
  cin >> x >> y;
  x = (x + 2) % 3;
  y = (y + 2) % 3;
  for (int i = x * 4; i < x * 4 + 3; i++)
    for (int j = y * 4; j < y * 4 + 3; j++)
      if (s[j][i] == '.') emp = true;
  if (emp) {
    for (int i = x * 4; i < x * 4 + 3; i++)
      for (int j = y * 4; j < y * 4 + 3; j++)
        if (s[j][i] == '.') s[j][i] = '!';
  } else {
    for (int i = 0; i < 12; i++)
      for (char &c : s[i])
        if (c == '.') c = '!';
  }
  for (int i = 0; i < 12; i++) cout << s[i] << endl;
  return 0;
}
