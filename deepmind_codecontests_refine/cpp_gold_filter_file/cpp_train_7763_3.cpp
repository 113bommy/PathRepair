#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a[66];
  memset(a, 0, sizeof(a));
  for (long long i = 1; i <= 60; i++) {
    long long x = i;
    long long cur = 1;
    while (x >= cur) {
      a[i]++;
      x -= cur;
      cur++;
    }
  }
  long long n;
  long long Xor = 0;
  scanf("%lld", &n);
  long long aa;
  while (n--) {
    scanf("%lld", &aa);
    Xor ^= a[aa];
  }
  if (!Xor)
    printf("YES");
  else
    printf("NO");
  printf("\n");
  return 0;
}
