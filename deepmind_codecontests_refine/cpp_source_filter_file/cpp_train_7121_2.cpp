#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  scanf("%d", &n);
  int a = 0, b = 0, x;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    if (x == 5)
      a++;
    else
      b++;
  }
  a = a / 3 * 3;
  if (b == 0)
    printf("-1\n");
  else {
    for (int i = 0; i < a; i++) printf("5");
    if (a == 0)
      printf("0");
    else
      for (int i = 0; i < b; i++) printf("0");
    printf("\n");
  }
  return 0;
}
