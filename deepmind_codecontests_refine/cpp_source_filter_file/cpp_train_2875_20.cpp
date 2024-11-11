#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  if (k == 0 || k == n) {
    printf("0 0");
  } else {
    printf("1 ");
    if (3 * k <= n) {
      printf("%d", 2 * k);
    } else {
      printf("%d", n - k);
    }
  }
  return 0;
}
