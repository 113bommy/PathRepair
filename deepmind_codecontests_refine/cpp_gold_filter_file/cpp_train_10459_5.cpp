#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  int res = 0;
  if (a == b) {
    printf("infinity");
    return 0;
  } else {
    if (a > b) {
      for (int i = 1; i * i <= a - b; i++) {
        if ((a - b) % i == 0) {
          if (i > b) res++;
          if ((a - b) / i > b && (a - b) / i != i) res++;
        }
      }
    }
  }
  printf("%d", res);
}
