#include <bits/stdc++.h>
int main() {
  int a[3], b[3], c[3];
  scanf("%d %d %d", &a[0], &b[0], &c[0]);
  scanf("%d %d %d", &a[1], &b[1], &c[1]);
  a[2] = -a[1] + a[0];
  c[2] = -c[1] + c[0];
  b[2] = -b[1] + b[0];
  int pos = 0, neg = 0;
  if (a[2] > 0)
    pos = pos + a[2] / 2;
  else
    neg += a[2];
  if (b[2] > 0)
    pos += b[2] / 2;
  else
    neg += b[2];
  if (c[2] > 0)
    pos += c[2] / 2;
  else
    neg += c[2];
  if (pos >= (-1) * neg)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
