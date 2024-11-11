#include <bits/stdc++.h>
using namespace std;
int bits[5] = {0, 8, 4, 2, 6};
int main(void) {
  int n;
  scanf("%d", &n);
  if (n == 0)
    printf("0\n");
  else {
    n -= 1;
    n = (n % 4) + 1;
    printf("%d\n", bits[n]);
  }
  return 0;
}
