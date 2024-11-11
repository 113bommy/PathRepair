#include <bits/stdc++.h>
int main(int argc, char **argv) {
  long long int s, a, b, c, t, i;
  scanf("%I64d", &t);
  for (i = 0; i < t; i++) {
    scanf("%I64d%I64d%I64d%I64d", &s, &a, &b, &c);
    long long int to = 0, f = 0;
    f = ((s / c) / a) * b;
    to = (s / c) + f;
    printf("%I64d\n", to);
  }
  return 0;
}
