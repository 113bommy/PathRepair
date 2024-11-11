#include <bits/stdc++.h>
using namespace std;
int aa[4][2];
string str;
int main() {
  int flag = 0;
  for (int i = 1; i <= 3; i++) {
    cin >> str;
    if (str.compare("rock") == 0) {
      aa[0][0]++;
      if (aa[0][0] == 1) aa[0][1] = i;
    } else if (str.compare("scissors") == 0) {
      aa[1][0]++;
      if (aa[1][0] == 1) aa[1][1] = i;
    } else {
      aa[2][0]++;
      if (aa[2][0] == 1) aa[2][1] = i;
    }
  }
  for (int i = 0; i < 3; i++) {
    if (aa[i][0] == 1 && aa[(i + 1) % 3][0] == 2) {
      flag = 1;
      if (aa[i][1] == 1)
        cout << 'F';
      else if (aa[i][1] == 1)
        cout << 'M';
      else
        cout << 'S';
      break;
    }
  }
  if (!flag) cout << '?';
  return 0;
}
