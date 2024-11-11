#include <bits/stdc++.h>
using namespace std;
long long n, k, s;
int main() {
  scanf("%lld%lld%lld", &n, &k, &s);
  if ((n - 1) * k < s) {
    printf("NO\n");
    return 0;
  } else if (k > s) {
    printf("NO\n");
    return 0;
  }
  printf("YES\n");
  long long sum = s;
  int flag = 0;
  long long now = 1;
  long long x = n - 1;
  while (k) {
    if (sum - x < k - 1) {
      break;
    } else {
      if (now == 1)
        now = n;
      else
        now = 1;
      sum -= x;
    }
    if (flag) {
      printf(" %lld", now);
    } else {
      flag = 1;
      printf("%lld", now);
    }
    k--;
  }
  if (sum != 0) {
    if (now == 1) {
      if ((sum - k + 1) != 0) {
        printf(" %lld", now + (sum - k + 1));
        now += sum - k + 1;
        k--;
      }
      int p = 0;
      while (k--) {
        if (p == 0) {
          printf(" %lld", ++now);
        } else {
          printf(" %lld", --now);
        }
        p = !p;
      }
    } else {
      if ((sum - k + 1) != 0) {
        printf(" %lld", now - (sum - k + 1));
        now -= (sum - k + 1);
        k--;
      }
      int p = 0;
      while (k--) {
        if (p == 0) {
          printf(" %lld", --now);
        } else {
          printf(" %lld", ++now);
        }
        p = !p;
      }
    }
  }
  return 0;
}
