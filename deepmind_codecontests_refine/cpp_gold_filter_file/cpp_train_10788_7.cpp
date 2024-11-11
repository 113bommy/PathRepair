#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i, j;
  scanf("%d", &t);
  int c1 = 0, c2 = 0;
  while (t--) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a < 0)
      c1++;
    else if (a > 0)
      c2++;
  }
  if ((c1 <= 1) || (c2 <= 1))
    printf("Yes");
  else
    printf("No");
}
