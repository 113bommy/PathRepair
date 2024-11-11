#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, k, d[5], s[100], countt[100] = {0}, countp[100] = {0},
                                countg[100] = {0}, maxt = 0, maxp = 0, maxg = 0,
                                m, flag;
  cin >> n;
  char name[100][21], number[100][100][9];
  for (i = 0; i < n; i++) {
    cin >> s[i] >> name[i];
    for (j = 0; j < s[i]; j++) cin >> number[i][j];
  }
  for (i = 0; i < n; i++) {
    for (k = 0; k < s[i]; k++) {
      m = 0;
      for (j = 0; j < 7; j++) {
        if (number[i][k][j + 1] == '-') {
          d[m++] = number[i][k][j + 2] - number[i][k][j];
          j++;
        } else
          d[m++] = number[i][k][j + 1] - number[i][k][j];
      }
      for (j = 0; d[j] == 0 && j < 5; j++)
        ;
      if (j == 5) {
        countt[i]++;
        continue;
      }
      for (j = 0; d[j] < 0 && j < 5; j++)
        ;
      if (j == 5) {
        countp[i]++;
        continue;
      }
      countg[i]++;
    }
    if (maxt < countt[i]) maxt = countt[i];
    if (maxp < countp[i]) maxp = countp[i];
    if (maxg < countg[i]) maxg = countg[i];
  }
  flag = 0;
  cout << "If you want to call a taxi, you should call: ";
  for (i = 0; i < n; i++)
    if (countt[i] == maxt)
      if (flag == 1)
        cout << ", " << name[i];
      else {
        cout << name[i];
        flag = 1;
      }
  cout << ".\n";
  flag = 0;
  cout << "If you want to order a pizza, you should call: ";
  for (i = 0; i < n; i++)
    if (countp[i] == maxp)
      if (flag == 1)
        cout << ", " << name[i];
      else {
        cout << name[i];
        flag = 1;
      }
  cout << ".\n";
  flag = 0;
  cout
      << "If you want to go to a cafe with a wonderful girl, you should call: ";
  for (i = 0; i < n; i++)
    if (countg[i] == maxg)
      if (flag == 1)
        cout << ", " << name[i];
      else {
        cout << name[i];
        flag = 1;
      }
  cout << ".\n";
  return 0;
}
