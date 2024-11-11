#include <bits/stdc++.h>
using namespace std;
int main() {
  char ar[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> ar[i][j];
    }
  }
  int a = 0;
  int b = 0;
  int c = 0;
  for (int i = 0; i < 3; i++) {
    if (ar[i][1] == '>') {
      if (ar[i][0] == 'A') {
        a++;
      } else if (ar[i][0] == 'B') {
        b++;
      } else {
        c++;
      }
    } else if (ar[i][1] == '<') {
      if (ar[i][2] == 'A') {
        a++;
      } else if (ar[i][2] == 'B') {
        b++;
      } else {
        c++;
      }
    }
  }
  if (a > b && a > c && b > c) {
    cout << "CBA";
  } else if (a > b && a > c && c > b) {
    cout << "BCA";
  } else if (b > a && b > c && c > a) {
    cout << "ACB";
  } else if (b > a && b > c && a > c) {
    cout << "CAB";
  } else if (c > a && c > b && c > a) {
    cout << "ABC";
  } else if (c > a && c > b && a > b) {
    cout << "BAC";
  } else {
    cout << "Impossible";
  }
  return 0;
}
