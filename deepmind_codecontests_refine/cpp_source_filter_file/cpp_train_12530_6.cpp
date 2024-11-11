#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 310, acc = 500000;
  printf("%d\n0 1000000\n", n);
  for (int i = 1; i < n; i++) {
    acc += 2 * (n - i + 100) + 2;
    printf("%d %d\n", acc, n - i + 100);
  }
  printf("1000000 1000000\n");
  return 0;
}
