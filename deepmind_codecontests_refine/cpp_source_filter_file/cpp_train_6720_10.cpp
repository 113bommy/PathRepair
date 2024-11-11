#include <bits/stdc++.h>
using namespace std;
int n, m, c, a, b;
int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%d%d", &a, &b);
    if (a != b)
      if (a > b)
        m++;
      else
        c++;
  }
  if (a != b)
    if (a > b)
      printf("Mishka");
    else
      printf("Chris");
  else
    printf("Friendship is magic!^^");
  return 0;
}
