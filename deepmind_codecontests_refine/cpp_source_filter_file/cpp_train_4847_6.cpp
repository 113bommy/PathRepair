#include <bits/stdc++.h>
int n, res = 1;
int main() {
  scanf("%d", &n);
  for (; n > 1; n--, res = (res * 3) % 1000006)
    ;
  printf("%d", res);
}
