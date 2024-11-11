#include <bits/stdc++.h>
using namespace std;
int main() {
  int pos, n;
  scanf("%d %d", &pos, &n);
  int c = 0, f = 1000000;
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (c < min(a, b)) c = min(a, b);
    if (f > max(a, b)) f = max(a, b);
  }
  if (c > f)
    printf("-1\n");
  else if (pos >= c && f >= pos)
    printf("0\n");
  else {
    if (pos < c)
      printf("%d\n", c - pos);
    else
      printf("%d\n", pos - f);
  }
  return 0;
}
