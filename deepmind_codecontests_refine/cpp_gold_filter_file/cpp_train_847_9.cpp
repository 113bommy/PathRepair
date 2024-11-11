#include <bits/stdc++.h>
using namespace std;
char s1[110], s2[110];
int main() {
  int a, b, mod, i, other;
  scanf("%d%d%d", &a, &b, &mod);
  for (i = 0; i <= a && i <= mod; ++i) {
    other = (long long)i * 1000000000 % mod;
    if (other != 0) other = mod - other;
    if (other <= b)
      continue;
    else {
      printf("1 %.9d\n", i);
      return 0;
    }
  }
  printf("2\n");
  return 0;
}
