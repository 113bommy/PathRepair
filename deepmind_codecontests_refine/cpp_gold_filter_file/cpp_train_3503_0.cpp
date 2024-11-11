#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, A, B;
  scanf("%I64d %I64d %I64d %I64d", &n, &k, &A, &B);
  long long px = n, x = n;
  long long nx;
  long long cost = 0;
  if (n == 1) {
    printf("0\n");
    return 0;
  }
  if (k == 1) {
    cost = A * (n - 1);
    printf("%I64d", cost);
    return 0;
  }
  while (x > 1) {
    if (x < k) {
      cost = cost + (x - 1) * A;
      break;
    }
    if (x % k != 0) cost = cost + (x % k) * A;
    x = x - x % k;
    nx = x / k;
    cost = cost + min((x - nx) * A, B);
    x = nx;
  }
  printf("%I64d\n", cost);
  return 0;
}
