#include <bits/stdc++.h>
using namespace std;
long long n, k, p;
int main() {
  scanf("%I64d%I64d%I64d", &n, &k, &p);
  long long a = n - k, b = k;
  while (p--) {
    long long x;
    scanf("%I64d", &x);
    if (a <= b) {
      long long s = b - a;
      x = n - x + 1;
      if (x <= s)
        printf("X");
      else if ((x - s) % 2 == 1)
        printf("X");
      else
        printf(".");
    } else {
      long long s = (a - b);
      if (b >= 1 && (s & 1)) {
        s++;
        if (x <= s)
          printf(".");
        else if (x == n)
          printf("X");
        else if ((x - s) & 1)
          printf(".");
        else
          printf("X");
      } else {
        if (x <= s)
          printf(".");
        else if ((x - s) & 1)
          printf(".");
        else
          printf("X");
      }
    }
  }
  return 0;
}
