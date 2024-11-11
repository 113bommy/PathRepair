#include <bits/stdc++.h>
using namespace std;
int n, m;
long long ans;
int main() {
  scanf("%d %d", &n, &m);
  if (m < n) {
    int tmp = m;
    m = n;
    n = tmp;
  }
  if (n >= 3) {
    if (m & n & 1 == 1) {
      printf("%lld\n", (long long)m * n - 1);
    } else {
      printf("%lld\n", (long long)m * n);
    }
    return 0;
  }
  if (n == 2) {
    if (m <= 2) {
      printf("0\n");
    } else if (m == 3) {
      printf("2\n");
    } else if (m == 7) {
      printf("12\n");
    } else {
      printf("%lld\n", (long long)m * n);
    }
    return 0;
  }
  if (n == 1) {
    int tmp = m % 6;
    if (tmp <= 3) {
      printf("%lld\n", (long long)m * n - tmp);
    } else {
      printf("%lld\n", (long long)m * n + tmp - 6);
    }
  }
  return 0;
}
