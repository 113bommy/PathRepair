#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s[6] = {"pP", "gT", "bA", "oS", "rR", "yM"};
  string c;
  for (int i = 0; i < n; i++) {
    cin >> c;
    int ctr = 0;
    while (ctr < 6) {
      if (c[0] == s[ctr][0]) {
        s[ctr][0] = ' ';
      }
      ctr++;
    }
  }
  cout << 6 - n << endl;
  for (int i = 0; i < n; i++) {
    if (s[i][0] != ' ') {
      switch (s[i][1]) {
        case 'P':
          cout << "Power" << endl;
          break;
        case 'T':
          cout << "Time" << endl;
          break;
        case 'A':
          cout << "Space" << endl;
          break;
        case 'S':
          cout << "Soul" << endl;
          break;
        case 'R':
          cout << "Reality" << endl;
          break;
        case 'M':
          cout << "Mind" << endl;
          break;
        default:
          break;
      }
    }
  }
  return 0;
}
