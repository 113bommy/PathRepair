#include <bits/stdc++.h>
using namespace std;
int main() {
  int num, num1, num2, comb1, comb2;
  cin >> num;
  num1 = num / 10;
  num2 = num % 10;
  switch (num1) {
    case 0:
      comb1 = 2;
      break;
    case 1:
      comb1 = 6;
      break;
    case 2:
      comb1 = 2;
      break;
    case 3:
      comb1 = 3;
      break;
    case 4:
      comb1 = 3;
      break;
    case 5:
      comb1 = 4;
      break;
    case 6:
      comb1 = 2;
      break;
    case 7:
      comb1 = 5;
      break;
    case 8:
      comb1 = 1;
      break;
    case 9:
      comb1 = 2;
      break;
  }
  switch (num2) {
    case 0:
      comb2 = 2;
      break;
    case 1:
      comb2 = 6;
      break;
    case 2:
      comb2 = 2;
      break;
    case 3:
      comb2 = 3;
      break;
    case 4:
      comb2 = 3;
      break;
    case 5:
      comb2 = 4;
      break;
    case 6:
      comb2 = 2;
      break;
    case 7:
      comb2 = 5;
      break;
    case 8:
      comb2 = 1;
      break;
    case 9:
      comb2 = 2;
      break;
  }
  int ans = comb1 * comb2;
  cout << ans;
  return 0;
}
