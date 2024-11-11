#include <bits/stdc++.h>
int gcd(int b, int a);
int main() {
  int i, j, a, b, n, r, d, k, fault = 0, index = -1;
  scanf("%d%d", &n, &r);
  char *s = (char *)calloc(n + 2, sizeof(char));
  int min = 999999;
  if (r == 1) {
    if (n == 1) {
      printf("0\n");
      printf("T\n");
    } else {
      printf("IMPOSSIBLE\n");
    }
    return (0);
  }
  for (i = r - 1; i >= 1; i--) {
    d = gcd(r, i);
    fault = 0;
    j = 1;
    int last = -1;
    if (d == 1) {
      b = i;
      a = r - i;
      while (b != a) {
        if (b > a) {
          if (a == 1) {
            j += b - 1;
            fault += b - 2;
            b = 1;
          } else {
            j += b / a;
            fault += b / a - 1;
            b = b % a;
          }
          last = 0;
          continue;
        }
        if (b < a) {
          if (b == 1) {
            j += a - 1;
            fault += a - 2;
            a = 1;
          } else {
            j += a / b;
            fault += a / b - 1;
            a = a % b;
          }
          last = 1;
          continue;
        }
      }
      if (j == n - 1) {
        if (last == 0) fault++;
        if (fault < min) {
          min = fault;
          index = i;
        }
      }
    }
  }
  if (index == -1) {
    printf("IMPOSSIBLE\n");
  } else {
    printf("%d\n", min);
    b = index;
    a = r - index;
    if (b > a)
      s[n - 1] = 'B';
    else
      s[n - 1] = 'T';
    i = n - 2;
    while (b != a) {
      if (b > a) {
        if (a == 1) {
          for (k = i; k > i - b; k--) {
            s[k] = 'T';
          }
          i = i - b;
          break;
        } else {
          for (k = i; k > i - b / a; k--) {
            s[k] = 'T';
          }
          i = i - b / a;
          b = b % a;
        }
        continue;
      }
      if (b < a) {
        if (b == 1) {
          for (k = i; k > i - a + 1; k--) {
            s[k] = 'B';
          }
          s[k] = 'T';
          i = i - a;
          break;
        } else {
          for (k = i; k > i - a / b; k--) s[k] = 'B';
          i = i - a / b;
          a = a % b;
        }
        continue;
      }
    }
    for (k = 0; k < n; k++) printf("%c", s[k]);
    printf("\n");
  }
  return (0);
}
int gcd(int b, int a) {
  int i;
  if (b % a == 0)
    return (a);
  else
    return (gcd(a, b % a));
}
