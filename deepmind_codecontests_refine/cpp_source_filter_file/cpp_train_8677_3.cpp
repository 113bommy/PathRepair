#include <bits/stdc++.h>
int is_prime(long long x) {
  int flag = 1;
  long long f = sqrt(x);
  if (x == 2)
    return flag;
  else if (!(x % 2))
    flag = 0;
  else {
    for (long long i = 3; i < f; i += 2) {
      if (x % i == 0) {
        flag = 0;
        break;
      }
    }
  }
  return flag;
}
int main() {
  long long n;
  scanf("%lld", &n);
  for (long long i = 0; i < n; i++) {
    long long a;
    scanf("%lld", &a);
    long long temp = sqrt(a);
    if ((a % 2 == 0 && a != 4) || a == 1) {
      printf("NO\n");
    } else {
      if (temp * temp == a) {
        int flag = is_prime(temp);
        if (flag)
          printf("YES\n");
        else
          printf("NO\n");
      } else {
        printf("NO\n");
      }
    }
  }
  return 0;
}
