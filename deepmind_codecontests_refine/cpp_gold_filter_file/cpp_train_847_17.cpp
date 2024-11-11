#include <bits/stdc++.h>
char hash[10000001];
int main() {
  long long i, a, b, c;
  scanf("%I64d%I64d%I64d", &a, &b, &c);
  for (i = 0; i <= a && !hash[i * 1000000000 % c]; i++) {
    if (i * 1000000000 % c != 0 && c - i * 1000000000 % c > b) {
      printf("1 %.9I64d\n", i);
      goto end;
    }
    hash[i * 1000000000 % c] = 1;
  }
  puts("2");
end:
  return 0;
}
