#include <bits/stdc++.h>
using namespace std;
int main() {
  string home, enemy, temp;
  vector<string> hasil;
  int xH, yH, xE, yE;
  cin >> home >> enemy;
  for (int i = 1; i <= 8; i++) {
    char az = 'a';
    for (int j = 1; j <= 8; j++) {
      temp = "";
      temp.push_back(az);
      temp.push_back((8 - i + 1) + '0');
      if (home == temp) {
        xH = i;
        yH = j;
      }
      if (enemy == temp) {
        xE = i;
        yE = j;
      }
      az++;
    }
  }
  while ((xE - xH != 0) || (yE - yH != 0)) {
    if (xE - xH > 0 && yE - yH > 0) {
      hasil.push_back("RD");
      xH++;
      yH++;
    }
    if (xE - xH < 0 && yE - yH > 0) {
      hasil.push_back("RU");
      xH--;
      yH++;
    }
    if (xE - xH > 0 && yE - yH < 0) {
      hasil.push_back("LD");
      xH++;
      yH--;
    }
    if (xE - xH < 0 && yE - yH < 0) {
      hasil.push_back("LU");
      xH--;
      yH--;
    }
    if (xE - xH == 0 && yE - yH > 0) {
      hasil.push_back("R");
      yH++;
    }
    if (xE - xH == 0 && yE - yH < 0) {
      hasil.push_back("L");
      yH--;
    }
    if (xE - xH > 0 && yE - yH == 0) {
      hasil.push_back("D");
      xH++;
    }
    if (xE - xH < 0 && yE - yH == 0) {
      hasil.push_back("U");
      xH--;
    }
  }
  cout << hasil.size() << endl;
  for (int i = 0; i < hasil.size(); i++) {
    if (i != 0) cout << endl;
    cout << hasil[i];
  }
  return 0;
}
