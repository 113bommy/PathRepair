#include <bits/stdc++.h>
using namespace std;
int n, m, k, v, t;
char mas[5][12];
string s[5];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= 11; i++) {
    for (int j = 1; j <= 4; j++) {
      if (n == 0) break;
      if (i != 1 && j == 3) {
        j++;
      }
      mas[j][i] = 'O';
      n--;
    }
    if (n == 0) break;
  }
  cout << "+------------------------+\n";
  for (int i = 1; i <= 4; i++) {
    s[i] = "|";
    for (int j = 1; j <= 11; j++) {
      s[i] += ((mas[i][j] == 'O') ? "O"
               : (i == 3)         ? ((j == 1) ? "#" : ".")
                                  : "#");
      s[i] += ".";
    }
  }
  s[1] += "|D|)\n";
  s[2] += "|.|)\n";
  s[3] += "..|\n";
  s[4] += "|.|)\n";
  cout << s[1] << s[2] << s[3] << s[4];
  cout << "+------------------------+";
  return 0;
}
