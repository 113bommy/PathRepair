#include <bits/stdc++.h>
int main(int argc, char **argv) {
  long long int li, i, r, l, j, re = 0;
  scanf("%I64d", &li);
  for (i = 1; i <= li; i++) {
    scanf("%I64d %I64d %I64d", &r, &l, &j);
    if (j % 2 == 0) {
      re = (r - l) * j / 2;
    } else {
      re = ((j / 2) + 1) * r - (j / 2) * l;
    }
    printf("%I64d\n", re);
  }
  return 0;
}
