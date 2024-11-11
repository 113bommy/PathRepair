#include <bits/stdc++.h>
using namespace std;
int main() {
  char c[8][8];
  int sum = 0;
  int summ = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> c[i][j];
      switch (c[i][j]) {
        case 'P': {
          sum = sum + 1;
          break;
        }
        case 'N': {
          sum = sum + 3;
          break;
        }
        case 'B': {
          sum = sum + 3;
          break;
        }
        case 'R': {
          sum = sum + 5;
          break;
        }
        case 'Q': {
          sum = sum + 9;
          break;
        }
        case 'K': {
          sum = sum + 1;
          break;
        }
        case 'p': {
          summ = summ + 1;
          break;
        }
        case 'n': {
          summ = summ + 3;
          break;
        }
        case 'b': {
          summ = summ + 3;
          break;
        }
        case 'r': {
          summ = summ + 5;
          break;
        }
        case 'q': {
          summ = summ + 9;
          break;
        }
        case 'k': {
          summ = summ + 1;
          break;
        }
      }
    }
  }
  if (sum > summ) {
    cout << "White";
  } else if (sum < summ) {
    cout << "Black";
  } else if (sum == summ) {
    cout << "Draw";
  }
}
