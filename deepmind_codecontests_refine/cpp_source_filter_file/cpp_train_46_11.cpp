#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c, j, err_1 = 0, err_2 = 0;
  scanf("%i", &n);
  for (j = 0; j < n; j++) {
    scanf("%i", &c);
    err_1 += c;
  }
  for (j = 0; j < n - 1; j++) {
    scanf("%i", &c);
    err_2 += c;
    err_1 -= err_2;
  }
  for (j = 0; j < n - 2; j++) {
    scanf("%i", &c);
    err_2 -= c;
  }
  printf("%i\n%i", err_1, err_2);
  return 0;
}
