#include <bits/stdc++.h>
using namespace std;
int main(void) {
  printf("401\n");
  printf("0 500000\n");
  for (int i = 2; i <= 400; i++)
    printf("%d %d\n", 500000 + 400 * 400 - (400 - i) * (400 - i), 1000);
  printf("%d %d\n", 1000000, 1000000);
  return 0;
}
