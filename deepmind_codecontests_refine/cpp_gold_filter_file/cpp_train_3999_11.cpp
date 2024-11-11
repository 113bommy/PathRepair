#include <bits/stdc++.h>
int main() {
  int n, i, count = 0;
  scanf("%d", &n);
  int A[100000];
  for (i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }
  for (i = 0; i < n - 1; i++) {
    if (A[i] != A[i + 1]) {
      count++;
    }
  }
  if (count == 0) {
    printf("1");
  } else {
    printf("%d", count + 1);
  }
}
