#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;
const int e = 36e6 + 100;
bool sai[e];
int id = 0;
int n, pr[e], p = 0;
void ous(int x) {
  for (int i = 3; i <= n; i++) {
    if (sai[i] == 0 and sai[x - i] == 0) {
      for (int ii = (x == (n * (n + 1) / 2) ? 1 : 3); ii <= n; ii++) {
        if (ii == i) {
          printf("%d ", id + 2);
        } else
          printf("%d ", id + 1);
      }
      return;
    }
  }
}
int main() {
  scanf("%d", &n);
  if (n == 3) {
    printf("1 1 2 ");
    return 0;
  }
  sai[0] = 0;
  sai[1] = 1;
  int sum = n * (n + 1) / 2;
  for (int i = 2; i <= n * n; i++) {
    if (!sai[i]) {
      pr[++p] = i;
    }
    for (int j = 1; j <= p; j++) {
      if (pr[j] * i > n * n) break;
      sai[pr[j] * i] = 1;
      if (!i % pr[j]) break;
    }
  }
  if (sai[sum]) {
    if (sum % 2) {
      if (!sai[sum - 2]) {
        for (int i = 1; i <= n; i++) {
          if (i == 2) {
            printf("2 ");
          } else {
            printf("1 ");
          }
        }
      } else {
        printf("1 1 ");
        id = 1;
        ous(sum - 3);
      }
    } else {
      id = 0;
      ous(sum);
    }
  } else {
    for (int i = 1; i <= n; i++) printf("1 ");
  }
  return 0;
}
