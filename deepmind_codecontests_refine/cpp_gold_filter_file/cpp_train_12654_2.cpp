#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, test, posi, posj;
  long long a[501][501], sum, temp, temp1, temp2, sumi, sumj;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cin >> a[i][j];
      if (a[i][j] == 0) {
        posi = i;
        posj = j;
      }
    }
  }
  if (n == 1)
    printf("1\n");
  else {
    sum = 0;
    temp = 0;
    while (temp == posi) temp++;
    for (i = 0; i < n; i++) sum += a[temp][i];
    sumi = 0;
    test = 0;
    for (i = 0; i < n; i++) {
      temp = 0;
      for (j = 0; j < n; j++) {
        if (i != posi) {
          temp += a[i][j];
        } else {
          sumi += a[i][j];
        }
      }
      if (i != posi && temp != sum) {
        test = 1;
        break;
      }
    }
    if (test == 1)
      printf("-1");
    else {
      test = 0;
      for (j = 0; j < n; j++) {
        temp = 0;
        for (i = 0; i < n; i++) {
          if (j != posj) {
            temp += a[i][j];
          } else {
            sumj += a[i][j];
          }
        }
        if (j != posj && temp != sum) {
          test = 1;
          break;
        }
      }
      if (test == 1)
        printf("-1");
      else {
        if (sumi != sumj)
          printf("-1");
        else {
          temp = sum - sumi;
          if (temp <= 0)
            printf("-1");
          else {
            a[posi][posj] = temp;
            temp1 = 0;
            temp2 = 0;
            for (i = 0; i < n; i++) {
              temp1 += a[i][i];
              temp2 += a[i][n - 1 - i];
            }
            if (temp1 == sum && temp2 == sum)
              cout << temp;
            else
              printf("-1");
          }
        }
      }
    }
  }
  return 0;
}
