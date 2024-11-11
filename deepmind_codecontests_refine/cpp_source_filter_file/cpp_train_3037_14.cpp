#include <bits/stdc++.h>
int inp() {
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  int sum = 0;
  while (c >= '0' && c <= '9') {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  return sum;
}
int a[100010];
long long sum[100010];
int main() {
  int n = inp();
  for (int i = 1; i <= n; i++) {
    a[i] = inp();
    sum[i] = sum[i - 1] + a[i];
  }
  int m = inp();
  while (m--) {
    int l = inp();
    int r = inp();
    printf("%lld\n", (sum[r] - sum[l]) / 10);
  }
}
