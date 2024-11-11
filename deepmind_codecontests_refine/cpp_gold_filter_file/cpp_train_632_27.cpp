#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, f, fk, p;
  int i, t;
  scanf("%I64d%I64d%d", &n, &k, &t);
  f = n - k;
  int fl = k;
  k = min(f, k);
  if (((f + k) % 2ll) == 1ll) k--;
  fk = f + k - (2ll * (k - 1ll));
  for (i = 0; i < t; i++) {
    if (!fl) {
      printf(".");
      continue;
    }
    scanf("%I64d", &p);
    if (p < fk && fk <= f + k) {
      printf(".");
      continue;
    }
    if (p <= f + k) {
      if (((fk % (2ll)) == (p % (2ll))) && fk <= f + k)
        printf("X");
      else
        printf(".");
    } else
      printf("X");
  }
  printf("\n");
  return 0;
}
