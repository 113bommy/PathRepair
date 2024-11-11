#include <bits/stdc++.h>
int main() {
  int n, s[100000], i, a, b, c, d, count;
  scanf("%d", &n);
  a = 0;
  b = 0;
  c = 0;
  d = 0;
  for (i = 0; i < n; i++) {
    scanf("%d", &s[i]);
    if (s[i] == 1) {
      a++;
    } else if (s[i] == 2) {
      b++;
    } else if (s[i] == 3) {
      c++;
    } else if (s[i] == 4) {
      d++;
    }
  }
  count = d;
  if (a <= c) {
    if (b % 2 == 0) {
      count = count + c + b / 2;
    } else {
      count = count + c + b / 2 + 1;
    }
  } else {
    if (b % 2 == 0) {
      if ((a - c) % 4 == 0) {
        count = count + c + b / 2 + (a - c) / 4;
      } else {
        count = count + c + b / 2 + (a - c) / 4 + 1;
      }
    } else {
      if ((a - c + 2) % 4 == 0) {
        count = count + c + b / 2 + (a - c + 2) / 4;
      } else {
        count = count + c + b / 2 + (a - c + 2) / 4 + 1;
      }
    }
  }
  printf("%d\n", count);
  return 0;
}
