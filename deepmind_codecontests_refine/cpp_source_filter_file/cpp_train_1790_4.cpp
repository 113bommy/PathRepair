#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p, q, t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    if (n == 1) {
      printf("3\n");
    } else if (n == 2) {
      printf("2\n");
    } else if (n % 2 == 0) {
      printf("0\n");
    } else {
      p = n / 2;
      q = p * 2;
      printf("%d", n - q);
    }
  }
  return 0;
}
