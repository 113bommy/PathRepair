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
  if (m != c)
    if (m > c)
      printf("Mishka");
    else
      printf("Chris");
  else
    printf("Friendship is magic!^^");
  return 0;
}
