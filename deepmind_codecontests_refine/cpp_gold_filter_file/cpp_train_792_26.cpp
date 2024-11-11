#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  string s[100];
  cin >> a >> b;
  char cek;
  for (int i = 0; i < a; i++) {
    cin >> s[i];
  }
  for (int j1 = 0; j1 < a; j1++) {
    for (int j2 = 0; j2 < b; j2++) {
      bool found = false;
      cek = s[j1][j2];
      for (int k1 = 0; k1 < b; k1++) {
        if (k1 == j2) continue;
        if (s[j1][k1] == cek) {
          found = true;
          break;
        }
      }
      for (int k2 = 0; k2 < a; k2++) {
        if (found == true) break;
        if (k2 == j1) continue;
        if (s[k2][j2] == cek) {
          found = true;
          break;
        }
      }
      if (found == false) cout << cek;
    }
  }
  cout << endl;
  return 0;
}
