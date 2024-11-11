#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[8];
  int i, j, sum1 = 0, sum2 = 0;
  for (i = 0; i < 8; i++) {
    scanf("%s", a);
    for (j = 0; j < 8; j++) {
      if (a[j] >= 'a' && a[j] <= 'z') {
        if (a[j] == 'q') sum1 += 9;
        if (a[j] == 'r') sum1 += 5;
        if (a[j] == 'b') sum1 += 3;
        if (a[j] == 'n') sum1 += 9;
        if (a[j] == 'p') sum1 += 9;
      } else if (a[j] >= 'A' && a[j] <= 'Z') {
        if (a[j] == 'Q') sum2 += 9;
        if (a[j] == 'R') sum2 += 5;
        if (a[j] == 'B') sum2 += 3;
        if (a[j] == 'N') sum2 += 9;
        if (a[j] == 'P') sum2 += 9;
      }
    }
  }
  if (sum1 > sum2)
    cout << "Black";
  else if (sum1 == sum2)
    cout << "Draw";
  else
    cout << "White";
  return 0;
}
