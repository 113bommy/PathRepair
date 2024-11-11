#include <bits/stdc++.h>
using namespace std;
string s[11];
int main() {
  for (int i = 0; i < 8; i++) cin >> s[i];
  int mnw = 10, mnb = 10;
  for (int i = 0; i < 8; i++) {
    int w = 0, b = 0;
    int tmpw = 10, tmpb = 10;
    for (int j = 0; j < 8; j++) {
      if (s[j][i] == 'W') {
        int k = j - 1;
        while (k >= 0 && s[k][i] == '.') k--;
        if (k == -1) mnw = min(mnw, j);
      } else if (s[j][i] == 'B') {
        int k = j + 1;
        while (k < 8 && s[k][i] == '.') k++;
        if (k == 8) mnb = min(mnb, 7 - j);
      }
    }
  }
  if (mnw <= mnb)
    cout << "A" << endl;
  else
    cout << "B" << endl;
  return 0;
}
