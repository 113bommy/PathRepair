#include <bits/stdc++.h>
using namespace std;
int A1, A2, A3, A4;
int main() {
  int i;
  scanf("%d%d%d%d", &A1, &A2, &A3, &A4);
  if (abs(A3 - A4) > 1)
    printf("-1");
  else {
    if (A3 == A4) {
      if ((((A1) > (A2) ? (A1) : (A2)) - A3 - 1 < 0) ||
          (((A1) < (A2) ? (A1) : (A2)) < A3))
        printf("-1");
      else {
        if (A1 - A3 - 1 < 0) {
          for (i = 1; i <= A3; ++i) printf("74");
          for (i = A2 - A3 - 1; i >= 1; --i) printf("7");
        } else {
          for (i = A1 - A3 - 1; i >= 1; --i) printf("4");
          for (i = 1; i <= A3; ++i) printf("47");
          for (i = A2 - A3; i >= 1; --i) printf("7");
          printf("4");
        }
      }
    } else {
      if (A3 > A4) {
        if ((A1 - A3 < 0) || (A2 - A3 < 0))
          printf("-1");
        else {
          for (i = A1 - A3; i >= 1; --i) printf("4");
          for (i = 1; i <= A3; ++i) printf("47");
          for (i = A2 - A3; i >= 1; --i) printf("7");
        }
      } else {
        if ((A1 - A3 - 1 < 0) || (A4 - 2 < 0) || (A2 - A3 < 0))
          printf("-1");
        else {
          printf("74");
          for (i = A1 - A3 - 1; i >= 1; --i) printf("4");
          for (i = A4 - 2; i >= 1; --i) printf("74");
          for (i = A2 - A3; i >= 1; --i) printf("7");
          printf("4");
        }
      }
    }
  }
  printf("\n");
  return 0;
}
