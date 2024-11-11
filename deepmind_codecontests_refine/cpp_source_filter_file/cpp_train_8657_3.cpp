#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, M, h, sum = 0, cev = 0, j, a = 1, b = 1, tut, c = 1, tut2, r = 0,
                  ham;
  scanf("%d ", &n);
  int A[n], B[n], C[n - 1];
  if (n == 2) {
    printf("1");
    return 0;
  }
  for (i = 0; i < n; i++) {
    scanf("%d", &A[i]);
    B[i] = A[i];
  }
  sort(B, B + n);
  tut = B[1] - B[0];
  for (i = 1; i < n - 2; i++) {
    if (B[i + 1] - B[i] != tut) {
      a = 0;
      break;
    }
  }
  tut = B[n - 1] - B[n - 2];
  for (i = 1; i < n - 2; i++) {
    if (B[i + 1] - B[i] != tut) {
      b = 0;
      break;
    }
  }
  tut = B[n - 1] - B[0];
  if (tut % (n - 2) != 0) {
    c = 0;
  }
  tut2 = tut / (n - 2);
  C[0] = B[0];
  for (i = 1; i <= n - 1; i++) {
    if (B[i] - C[r] == tut2) {
      C[r + 1] = B[i];
      r++;
    } else {
      ham = B[i];
    }
  }
  if (r != n - 2) {
    c = 0;
  }
  if (a == 1) {
    ham = B[0];
    for (i = 0; i < n; i++) {
      if (A[i] == ham) {
        printf("%d", i + 1);
        return 0;
      }
    }
  } else if (b == 1) {
    ham = B[n - 1];
    for (i = 0; i < n; i++) {
      if (A[i] == ham) {
        printf("%d", i + 1);
        return 0;
      }
    }
  } else if (c == 1) {
    for (i = 0; i < n; i++) {
      if (A[i] == ham) {
        printf("%d", i + 1);
        return 0;
      }
    }
  } else {
    printf("-1");
    return 0;
  }
  return 0;
}
