#include <bits/stdc++.h>
int main() {
  long long int b, d, s, sum, max;
  char t;
  scanf("%lld%lld%lld", &b, &d, &s);
  if (b == d && b == s)
    printf("0");
  else {
    max = b;
    t = 'b';
    if (max <= d) {
      max = d;
      t = 'd';
    }
    if (max <= s) {
      max = s;
      t = 's';
    }
    if (t == 'b') {
      if (b == d)
        sum = b - 1 - s;
      else if (s == b)
        sum = b - 1 - d;
      else
        sum = b - 1 - d + b - 1 - s;
    }
    if (t == 'd') {
      if (d == s)
        sum = d - 1 - b;
      else if (b == d)
        sum = d - 1 - s;
      else
        sum = d - 1 - s + b - 1 - b;
    }
    if (t == 's') {
      if (s == b)
        sum = s - 1 - d;
      else if (d == s)
        sum = d - 1 - b;
      else
        sum = s - 1 - b + s - 1 - d;
    }
    printf("%lld", sum);
  }
  return 0;
}
