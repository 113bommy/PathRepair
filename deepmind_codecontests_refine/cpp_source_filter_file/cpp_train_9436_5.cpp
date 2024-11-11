#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e9;
string s[6], h[6] = {"33-44-33", "33-44-33", "22-33-22",
                     "22-33-22", "11-22-11", "11-22-11"};
void pr(int a, int b) {
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 8; j++) {
      if (i == a && j == b)
        cout << 'p';
      else
        cout << s[i][j];
    }
    cout << endl;
  }
}
int main() {
  for (int i = 0; i < 6; i++) {
    cin >> s[i];
  }
  for (int i = 6; i >= 1; i--) {
    for (int j = 0; j < 6; j++) {
      for (int k = 0; k < 8; k++) {
        if (s[j][k] == '.' && h[j][k] - 48 == i) {
          for (int f = 0; f < 6; f++) {
            for (int g = 0; g < 8; g++) {
              if (f == j && g == k)
                cout << 'p';
              else
                cout << s[f][g];
            }
            cout << endl;
          }
          return 0;
        }
      }
    }
  }
  return 0;
}
