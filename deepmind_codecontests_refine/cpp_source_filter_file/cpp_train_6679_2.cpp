#include <bits/stdc++.h>
using namespace std;
int main() {
  int c, n, j = 0;
  char A[200000], B[200000];
  scanf("%d", &n);
  scanf("%s", A);
  for (int i = 0; i < n; i++) {
    if ((i) % 2 == 0 && A[i] == A[i + 1]) {
      B[j] = A[i];
      j++;
      while (A[i] == A[i + 1]) {
        i++;
      }
    } else {
      B[j] = A[i];
      j++;
    }
  }
  if (j == 0) {
    printf("0\n");
    for (int i = 0; i < n; i++) printf("%c", A[i]);
  } else if (j % 2 == 0) {
    printf("%d\n", n - j);
    for (int i = 0; i < j; i++) printf("%c", B[i]);
  } else {
    printf("%d\n", n - j + 1);
    for (int i = 0; i < j - 1; i++) printf("%c", B[i]);
  }
  return 0;
}
