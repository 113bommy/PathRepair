#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m;
  scanf("%lld%lld", &n, &m);
  int i, j;
  if (n == 1) {
    printf("1\n");
    return 0;
  } else if (n == 2) {
    if (m == 1)
      printf("2\n");
    else
      printf("1\n");
    return 0;
  }
  long long int d = n / 2;
  if (n % 2 == 0) {
    if (m == d)
      printf("%lld\n", d + 1);
    else if (m > d)
      printf("%lld\n", m - 1);
    else
      printf("%lld\n", m + 1);
  } else {
    d = d + 1;
    if (m == d)
      printf("%lld\n", d - 1);
    else if (m > d)
      printf("%lld\n", m - 1);
    else
      printf("%lld\n", m + 1);
  }
  return 0;
}
