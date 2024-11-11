#include <bits/stdc++.h>
using namespace std;
int n, i, A[5000];
int main() {
  scanf("%d", &n);
  if (n == 1) {
    printf("1\n");
    printf("1\n");
  } else if (n == 2) {
    printf("1\n");
    printf("1\n");
  } else if (n == 3) {
    printf("2\n");
    printf("1 3\n");
  } else if (n == 4) {
    printf("4\n");
    printf("2 4 1 3\n");
  } else {
    printf("%d\n", n);
    for (i = 0; i < n; i++)
      if (i % 2)
        A[i] = i / 2 + (n + 3) / 2;
      else
        A[i] = i / 2 + 1;
    for (i = 0; i < n - 1; i++) printf("%d ", A[i]);
    printf("%d\n", A[n - 1]);
  }
  return 0;
}
