#include <bits/stdc++.h>
int main() {
  int test;
  scanf("%d", &test);
  for (int i = 0; i < test; i = i + 1) {
    long long a, b;
    long long n;
    scanf("%lld%lld%lld", &n, &a, &b);
    long long tong;
    if (a * 2 < b) {
      tong = (long long)n * a;
    } else {
      tong = (long long)(n / 2) * b;
      if (n % 2 == 1) {
        tong = tong + a;
      }
    }
    printf("%lld", tong);
    printf("\n");
  }
}
