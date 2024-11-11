#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, a[maxn], b[maxn], r[maxn], num[6] = {0, 1, 2, 3, 4, 5};
int main() {
  scanf("%d", &n);
  int up = 1, down = 1, flag = 0;
  ;
  a[0] = a[n + 1] = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] > a[i - 1]) {
      up++;
      r[i] = 1;
    } else
      up = 1;
    if (a[i] < a[i - 1]) {
      down++;
      r[i] = -1;
    } else
      down = 1;
    if (a[i] == a[i - 1]) r[i] = 0;
    if (i == 1) up = down = 1;
    if (up > 5 || down > 5) flag = 1;
  }
  if (flag) {
    printf("-1\n");
    return 0;
  }
  up = 0, down = 6;
  for (int i = 2; i <= n + 1; i++) {
    if (i == n + 1) {
      if (r[i - 1] == 1)
        b[i - 1] = b[i - 2] + 1;
      else if (r[i - 1] == -1)
        b[i - 1] = b[i - 2] - 1;
      else {
        for (int c = 1; c <= 5; c++)
          if (c != b[i - 2]) {
            b[i - 1] = c;
            break;
          }
      }
      continue;
    }
    if (r[i] == 1) {
      if (down < 6) down = 6;
      up++;
      b[i - 1] = num[up];
    } else if (r[i] == -1) {
      if (up) up = 0;
      down--;
      b[i - 1] = num[down];
    } else {
      int k = i;
      if (r[i - 1] == 1) {
        up++;
        b[i - 1] = num[up];
      } else {
        down--;
        b[i - 1] = num[down];
      }
      up = 0, down = 6;
      while (r[k] == 0) k++;
      if (r[k] == 1) {
        if (r[k - 2] == 1)
          b[k - 1] = 2, up++;
        else
          b[k - 1] = 1;
        up++;
      } else {
        if (r[k - 2] == 5)
          b[k - 1] = 4, down--;
        else
          b[k - 1] = 5;
        down--;
      }
      for (int j = i; j < k - 1; j++) {
        for (int c = 1; c <= 5; c++) {
          if (j == k - 2) {
            if (c != b[j - 1] && c != b[j + 1]) {
              b[j] = c;
              break;
            }
          } else if (c != b[j - 1]) {
            b[j] = c;
            break;
          }
        }
      }
      i = k;
    }
  }
  for (int i = 1; i <= n; i++) printf("%d ", b[i]);
  return 0;
}
