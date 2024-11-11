#include <bits/stdc++.h>
using namespace std;
int type;
long long n, k, p;
int main() {
  scanf("%lld%lld%lld", &n, &k, &p);
  if (k == 0)
    type = 1;
  else if (k == n)
    type = 2;
  else if (n <= 2 * k) {
    type = 3;
  } else {
    if (((k % 2) ^ ((n - k) % 2)) == 0)
      type = 5;
    else
      type = 6;
  }
  if (type == 6 && k - 1 == 0) type = 5;
  while (p--) {
    long long x;
    scanf("%lld", &x);
    if (type == 1)
      printf(".");
    else if (type == 2)
      printf("X");
    else if (type == 3) {
      if (x > 2 * n - 2 * k - 1)
        printf("X");
      else {
        if (x % 2 == 1)
          printf(".");
        else
          printf("X");
      }
    } else if (type == 5) {
      if (x <= n - 2 * k + 1)
        printf(".");
      else {
        long long tmp = x - (n - 2 * k + 1);
        if (tmp % 2 == 1)
          printf("X");
        else
          printf(".");
      }
    } else if (type == 6) {
      if (x <= n - 2 * k + 2)
        printf(".");
      else {
        long long tmp = x - (n - 2 * k + 2);
        if (x >= n - 1)
          printf("X");
        else {
          if (tmp % 2 == 1)
            printf("X");
          else
            printf(".");
        }
      }
    }
  }
  return 0;
}
