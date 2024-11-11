#include <bits/stdc++.h>
int main() {
  int a, b, c, d;
  scanf("%d%d%d", &a, &b, &c);
  c = c - (abs(a) + abs(b));
  if (c < 0) c = 1;
  if (c % 2 == 0)
    printf("YES");
  else
    printf("NO");
}
