#include <bits/stdc++.h>
long long arr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 8, 7};
long long stroke(long long a) {
  long long total = 0;
  while (a > 0) {
    total += arr[a % 10];
    a /= 10;
  }
  return total;
}
int main() {
  long long a, b;
  long long jawaban = 0;
  scanf("%I64d %I64d", &a, &b);
  for (int i = a; i <= b; i++) {
    jawaban += stroke(i);
  }
  printf("%I64d", jawaban);
  return 0;
}
