#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  ;
  ;
  k -= 2 * n;
  if (k <= 0) {
    printf("%d\n", n);
    ;
    return 0;
  }
  if (k >= n) {
    printf("%d\n", 0);
    ;
  } else {
    printf("%d\n", k % n);
    ;
  }
  return 0;
}
