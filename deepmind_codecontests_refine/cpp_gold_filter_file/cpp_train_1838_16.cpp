#include <bits/stdc++.h>
using namespace std;
long long p, k;
long long B[101];
long long A[101];
void work() {
  if (k > p) {
    printf("1\n%I64d", p);
    return;
  }
  long long now = -1, base = k;
  int d;
  bool flag = true;
  B[0] = -p / k;
  for (d = 1;; d++) {
    if (now == -1) {
      B[d] = ((-B[d - 1] + k - 1) / k);
    } else {
      B[d] = -(B[d - 1] / k);
    }
    if (B[d] == 0) {
      break;
    }
    now *= -1;
  }
  if (B[0] * k + p > k) {
    printf("-1");
    return;
  }
  for (int i = 2; i <= d; i++) {
    if (B[i] * k + B[i - 1] >= k) {
      printf("-1");
      return;
    }
  }
  printf("%d\n", d + 1);
  printf("%I64d", B[0] * k + p);
  for (int i = 1; i <= d; i++) {
    printf(" %I64d", B[i] * k + B[i - 1]);
  }
}
int main() {
  scanf("%I64d%I64d", &p, &k);
  work();
  return 0;
}
