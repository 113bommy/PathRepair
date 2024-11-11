#include <bits/stdc++.h>
int main() {
  int n, k, s = 0;
  scanf("%d", &n);
  scanf("%d", &k);
  if ((n * 8) % k != 0)
    s += (n * 8) / k + 1;
  else
    s += (n * 8) / k;
  if ((n * 2) % k != 0)
    s += (n * 2) / k + 1;
  else
    s += (n * 2) / k;
  if ((n * 5) % k != 0)
    s += (n * 5) / k + 1;
  else
    s += (n * 5) / k;
  printf("%d", s);
}
