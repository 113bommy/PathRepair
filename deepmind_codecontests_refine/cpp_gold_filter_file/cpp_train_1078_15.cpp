#include <bits/stdc++.h>
using namespace std;
const long limit = 100000 + 5;
long n;
int main() {
  long i, j, k, t;
  scanf("%ld", &n);
  t = 1;
  for (i = (1); i <= (n - 1); ++i) t = (t * 10) % 7;
  k = 20;
  while ((k + t) % 7) k += 30;
  i = 1;
  j = k;
  while (k > 10) {
    k = k / 10;
    i++;
  }
  if (n < 4) {
    if (n == 1 || n == 2) printf("-1");
    if (n == 3) printf("210");
  } else {
    printf("1");
    for (t = (2); t <= (n - i); ++t) printf("0");
    printf("%ld", j);
  }
  scanf("%ld");
}
