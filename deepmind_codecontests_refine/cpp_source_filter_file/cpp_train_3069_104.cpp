#include <bits/stdc++.h>
using namespace std;
int main() {
  char ar[8][8];
  long long W[5] = {9, 5, 3, 3, 1};
  long long s1 = 0;
  long long s2 = 0;
  for (long long i = 0; i < 8; i++) {
    for (long long j = 0; j < 8; j++) {
      cin >> ar[i][j];
    }
  }
  for (long long i = 0; i < 8; i++) {
    for (long long j = 0; j < 8; j++) {
      if (ar[i][j] >= 65 && ar[i][j] <= 90) {
        if (ar[i][j] == 'Q')
          s1 += 9;
        else if (ar[i][j] == 'R')
          s1 + 5;
        else if (ar[i][j] == 'B')
          s1 += 3;
        else if (ar[i][j] == 'N')
          s1 += 3;
        else if (ar[i][j] == 'P')
          s1 += 1;
      } else {
        if (ar[i][j] == 'q')
          s2 += 9;
        else if (ar[i][j] == 'r')
          s2 += 5;
        else if (ar[i][j] == 'b')
          s2 += 3;
        else if (ar[i][j] == 'n')
          s2 += 3;
        else if (ar[i][j] == 'p')
          s2 += 1;
      }
    }
  }
  if (s1 > s2) {
    cout << "White";
  } else if (s1 < s2) {
    cout << "Black";
  } else {
    cout << "Draw";
  }
}
