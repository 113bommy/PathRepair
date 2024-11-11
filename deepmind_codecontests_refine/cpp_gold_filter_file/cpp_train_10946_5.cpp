#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, c, d, e, f, i, j, h = 0;
  scanf("%lld %lld %lld", &a, &b, &c);
  long long day;
  day = 7 * min(a / 3, min(b / 2, c / 2));
  int g = min(a / 3, min(b / 2, c / 2));
  a -= g * 3, b -= g * 2, c -= g * 2;
  for (i = 0; i < 7; i++) {
    d = a;
    e = b;
    f = c;
    j = i;
    while (1) {
      if (j % 7 == 0)
        d--, j++;
      else if (j % 7 == 1)
        d--, j++;
      else if (j % 7 == 2)
        e--, j++;
      else if (j % 7 == 3)
        f--, j++;
      else if (j % 7 == 4)
        d--, j++;
      else if (j % 7 == 5)
        f--, j++;
      else if (j % 7 == 6)
        e--, j++;
      if (d == -1 || e == -1 || f == -1) {
        j--;
        break;
      }
    }
    h = max(j - i, h);
  }
  printf("%lld\n", day + h);
  return 0;
}
