#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  if (n % 2 == 0)
    printf("-1\n");
  else {
    for (int i = 0; i < n; i++) {
      if (i) printf(" ");
      printf("%d", i);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
      if (i) printf(" ");
      printf("%d", i);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
      if (i) printf(" ");
      printf("%d", (i + i) % n);
    }
    printf("\n");
  }
  return 0;
}
