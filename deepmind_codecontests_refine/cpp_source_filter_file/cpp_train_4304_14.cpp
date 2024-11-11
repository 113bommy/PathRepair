#include <bits/stdc++.h>
FILE *in, *out;
int main() {
  int i, a, b, c = 1, say = 0, q;
  long long n = 1;
  char dixi[100000];
  scanf("%d", &a);
  if (a == 1) {
    printf("1");
    return 0;
  }
  for (i = 1; i < a; i++) n += 12;
  printf("%I64d", n);
  return 0;
}
