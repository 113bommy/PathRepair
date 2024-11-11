#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  if (n == 3)
    printf("5\n");
  else {
    for (int i = 3;; i += 2) {
      if ((i * i + 1) / 2 >= n) {
        printf("%d\n", i);
        break;
      }
    }
  }
  return 0;
}
