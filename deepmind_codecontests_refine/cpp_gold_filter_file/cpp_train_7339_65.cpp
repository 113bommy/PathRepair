#include <bits/stdc++.h>
using namespace std;
int main() {
  string s[8];
  for (int i = 0; i < 8; ++i) cin >> s[i];
  int maksa = 2000, maksb = 2000;
  for (int i = 0; i < 8; ++i) {
    int it = 0;
    for (; it < 8; ++it) {
      if (s[it][i] == 'W') {
        maksa = min(maksa, it);
        break;
      }
      if (s[it][i] == 'B') break;
    }
    it = 7;
    for (; it >= 0; --it) {
      if (s[it][i] == 'B') {
        maksb = min(maksb, 7 - it);
        break;
      }
      if (s[it][i] == 'W') break;
    }
  }
  cout << (maksb < maksa ? "B\n" : "A\n");
}
