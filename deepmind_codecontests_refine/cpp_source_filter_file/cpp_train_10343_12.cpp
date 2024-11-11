#include <bits/stdc++.h>
using namespace std;
int x;
int main() {
  int i, j, k;
  scanf("%d", &x);
  if (x == 3)
    printf("5\n");
  else {
    for (i = 1; i <= 14; i += 2) {
      if (i * i / 2 + 1 >= x) {
        printf("%d\n", i);
        break;
      }
    }
  }
}
