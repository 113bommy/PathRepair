#include <bits/stdc++.h>
char a[10][11];
char s[10][11];
int main() {
  int n;
  int i, j, k;
  int k1, k2, k3, k4, k5, k6, k7;
  int q1, q2, q3, q4, q5, q6, q7;
  int w1, w2, w3, w4, w5, w6, w7;
  while (scanf("%d", &n) != EOF) {
    for (i = 0; i < n; i++) scanf("%s", s[i]);
    for (i = 0; i < n; i++) scanf("%s", a[i]);
    q1 = 0;
    q2 = n - 1;
    q3 = n - 1;
    q4 = 0;
    q5 = 0;
    q6 = n - 1;
    q7 = n - 1;
    w1 = 0;
    w2 = 0;
    w3 = 0;
    w4 = n - 1;
    w5 = n - 1;
    w6 = n - 1;
    w7 = n - 1;
    k1 = 1;
    k2 = 1;
    k3 = 1;
    k4 = 1;
    k5 = 1;
    k6 = 1;
    k7 = 1;
    k = 1;
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (k == 1)
          if (a[i][j] != s[i][j]) k = 0;
        if (k1 == 1) {
          if (a[q1][w1] != s[i][j])
            k1 = 0;
          else {
            q1++;
            if (q1 == n) {
              q1 = 0;
              w1++;
            }
          }
        }
        if (k2 == 1) {
          if (a[q2][w2] != s[i][j])
            k2 = 0;
          else {
            q2--;
            if (q2 < 0) {
              q2 = n - 1;
              w2++;
            }
          }
        }
        if (k3 == 1) {
          if (a[q3][w3] != s[i][j])
            k3 = 0;
          else {
            w3++;
            if (w3 == n) {
              q3--;
              w3 = 0;
            }
          }
        }
        if (k4 == 1) {
          if (a[q4][w4] != s[i][j])
            k4 = 0;
          else {
            q4++;
            if (q4 == n) {
              q4 = 0;
              w4--;
            }
          }
        }
        if (k5 == 1) {
          if (a[q5][w5] != s[i][j])
            k5 = 0;
          else {
            w5--;
            if (w5 < 0) {
              w5 = n - 1;
              q5++;
            }
          }
        }
        if (k6 == 1) {
          if (a[q6][w6] != s[i][j])
            k6 = 0;
          else {
            q6--;
            if (q6 < 0) {
              w6--;
              q6 = n - 1;
            }
          }
        }
        if (k7 == 1) {
          if (a[q7][w7] != s[i][j])
            k7 = 0;
          else {
            w7--;
            if (w7 < 0) {
              w7 = n - 1;
              q7--;
            }
          }
        }
      }
    }
    if (k || k1 || k2 || k3 || k4 || k5 || k6 || k7)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
