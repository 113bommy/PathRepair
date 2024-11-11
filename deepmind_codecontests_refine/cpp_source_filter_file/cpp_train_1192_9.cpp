#include <bits/stdc++.h>
using namespace std;
int main() {
  string neww;
  char a;
  string soso;
  cin >> a;
  string alfa = "qwertyuiopasdfghjkl;zxcvbnm,./";
  cin >> soso;
  if (a == 'R') {
    for (int i = 0; i < soso.length(); i++) {
      for (int j = 0; j < 30; j++) {
        if (soso[i] == alfa[j]) {
          int ao = (j - 1 + 30) % 30;
          neww[i] = +alfa[ao];
        }
      }
    }
  }
  if (a == 'L') {
    for (int i = 0; i < soso.length(); i++) {
      for (int j = 0; j < 30; j++) {
        if (soso[i] == alfa[j]) neww[i] = +alfa[(j + 1 + 30) % 30];
      }
    }
  }
  for (int k = 0; k <= soso.length(); k++) cout << neww[k];
}
