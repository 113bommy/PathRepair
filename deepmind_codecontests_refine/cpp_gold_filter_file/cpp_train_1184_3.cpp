#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  scanf("%I64d%I64d", &n, &k);
  if ((k * (k - 1) / 2) + 1 < n) {
    printf("-1\n");
    exit(0);
  }
  if (n == 1) {
    printf("0\n");
    exit(0);
  }
  int left = 0;
  int right = k - 1;
  while (left < right) {
    long long mid = (left + right) / 2;
    long long num;
    if (mid == 0)
      num = 0;
    else if (mid == 1)
      num = k;
    else
      num = ((long long)(k - 1 + (k - mid)) * mid) / 2 + 1;
    if (n > num) {
      left = mid + 1;
    } else
      right = mid;
  }
  printf("%d\n", left);
}
