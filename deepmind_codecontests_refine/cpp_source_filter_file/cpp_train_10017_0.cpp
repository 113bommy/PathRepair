#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k;
  int m, n;
  scanf("%d", &n);
  i = j = 0;
  while (n--) {
    scanf("%d", &k);
    if (k & 1)
      ++i;
    else
      ++j;
  }
  if (i & 1)
    printf("%d\n", i);
  else
    printf("%d\n", i + j);
  return 0;
}
