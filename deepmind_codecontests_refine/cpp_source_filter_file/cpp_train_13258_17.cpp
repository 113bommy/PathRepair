#include <bits/stdc++.h>
using namespace std;
int main() {
  int strKirito, numDragon;
  cin >> strKirito >> numDragon;
  int strDragon[numDragon];
  int bonus[numDragon];
  for (int i = 0; i < numDragon; i++) {
    cin >> strDragon[i] >> bonus[i];
  }
  int temp;
  int sorted = 0;
  while (sorted == 0) {
    sorted = 1;
    for (int i = 1; i <= numDragon - 2; i = i + 2) {
      if (strDragon[i] > strDragon[i + 1]) {
        temp = strDragon[i];
        strDragon[i] = strDragon[i + 1];
        strDragon[i + 1] = temp;
        temp = bonus[i];
        bonus[i] = bonus[i + 1];
        bonus[i + 1] = temp;
        sorted = 0;
      }
    }
    for (int i = 0; i <= numDragon - 2; i = i + 2) {
      if (strDragon[i] > strDragon[i + 1]) {
        temp = strDragon[i];
        strDragon[i] = strDragon[i + 1];
        strDragon[i + 1] = temp;
        temp = bonus[i];
        bonus[i] = bonus[i + 1];
        bonus[i + 1] = temp;
        sorted = 0;
      }
    }
  }
  for (int i = 0; i < numDragon; i++) {
    if (strDragon[i] < strKirito) {
      strKirito = strKirito + bonus[i];
      if (i == numDragon - 1) {
        cout << "YES" << endl;
      }
    }
    if (strDragon[i] > strKirito) {
      cout << "NO" << endl;
      break;
    }
  }
  return 0;
}
