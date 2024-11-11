#include <bits/stdc++.h>
using namespace std;
int main() {
  printf("302\n");
  printf("0 1000000\n");
  int i, d, s = 800;
  d = 1000000 - 32000 - 2000 * 300;
  for (i = 1; i <= 300; i++) {
    printf("%d %d\n", d, s);
    s = s--;
    d = d + 2000;
  }
  printf("1000000 1000000\n");
}
