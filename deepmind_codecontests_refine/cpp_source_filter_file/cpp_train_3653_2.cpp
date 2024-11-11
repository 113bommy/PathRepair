#include <bits/stdc++.h>
using namespace std;
int a, b;
int x;
int main() {
  scanf("%d%d%d", &a, &b, &x);
  if (a >= x)
    for (int i = 0; i <= x - 2; i++) {
      printf("%d", i & 1);
      a -= !(i & 1);
      b -= (i & 1);
    }
  else {
    for (int i = 1; i <= x - 1; i++) {
      printf("%d", i & 1);
      a -= !(i & 1);
      b -= (i & 1);
    }
    x++;
  }
  if (x & 1) {
    for (int i = 0; i < a; i++) printf("0");
    for (int i = 0; i < b; i++) printf("1");
  } else {
    for (int i = 0; i < b; i++) printf("1");
    for (int i = 0; i < a; i++) printf("0");
  }
  printf("\n");
  return 0;
}
