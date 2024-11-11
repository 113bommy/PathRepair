#include <bits/stdc++.h>
using namespace std;
char ch[4][4];
int main() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> ch[i][j];
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int s1 = 0, s2 = 0;
      for (int k = i; k <= i + 1; k++) {
        for (int l = j; l <= j + 1; l++) {
          if (ch[k][l] == '#')
            s1++;
          else
            s2++;
        }
      }
      if (s1 == 3 || s2 == 3) {
        cout << "YES\n";
        return 0;
      }
    }
  }
  cout << "NO\n";
  return 0;
}
