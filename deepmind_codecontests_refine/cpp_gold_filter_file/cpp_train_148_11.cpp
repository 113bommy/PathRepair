#include <bits/stdc++.h>
int A[5];
int main() {
  int sum = 0;
  for (int i = 0; i < 5; ++i) {
    int t;
    scanf("%d", &t);
    sum += t;
  }
  if (sum % 5 || !sum) {
    printf("-1\n");
  } else {
    printf("%d", sum / 5);
  }
  return 0;
}
