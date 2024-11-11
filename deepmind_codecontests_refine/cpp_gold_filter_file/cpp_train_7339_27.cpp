#include <bits/stdc++.h>
using namespace std;
int Mark[10];
string s[10];
int main() {
  int w, b;
  w = b = 8;
  for (int i = 0; i < 8; i++) cin >> s[i];
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (s[i][j] == 'W' && !Mark[j]) w = min(w, i);
      if (s[i][j] != '.') Mark[j] = true;
    }
  }
  for (int i = 0; i < 8; i++) Mark[i] = false;
  for (int i = 7; i >= 0; i--) {
    for (int j = 0; j < 8; j++) {
      if (s[i][j] == 'B' && !Mark[j]) b = min(b, 7 - i);
      if (s[i][j] != '.') Mark[j] = true;
    }
  }
  if (b >= w)
    cout << "A" << endl;
  else
    cout << "B" << endl;
  return 0;
}
