#include <bits/stdc++.h>
long long b;
int main() {
  int count = 1, i = 2;
  scanf("%lli", &b);
  if (b == 1) {
    printf("1");
    return 0;
  }
  float root = sqrt(b);
  while (i <= root) {
    if (b % i == 0) count++;
    i++;
  }
  count *= 2;
  i = (int)root;
  if (root == i)
    printf("%d", count - 1);
  else
    printf("%d", count);
  return 0;
}
