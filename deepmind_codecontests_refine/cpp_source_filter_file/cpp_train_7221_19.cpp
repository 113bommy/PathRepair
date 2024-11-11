#include <bits/stdc++.h>
using namespace std;
int main() {
  int ar[5][5];
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> ar[i][j];
    }
  }
  int i = 0;
  int j = 0;
  int flag = 0;
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      if (ar[i][j] == 1) {
        flag = 1;
        break;
      }
    }
    if (flag == 1) break;
  }
  cout << abs(3 - j) + abs(3 - i);
}
