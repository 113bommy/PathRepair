#include <bits/stdc++.h>
long long int a[100], total, s, ok[2012], top;
int nn, n;
void fac() {
  int i, j, k;
  long long int tla, tlb, tlc, tld;
  do {
    for (i = 0; i < n; i++) {
      tla = tlb = 0;
      for (j = 0; j < n; j++) {
        tla += a[i * n + j];
        tlb += a[j * n + i];
      }
      if (tla != s || tlb != s) break;
    }
    tlc = tld = 0;
    for (k = 0; k < n; k++) {
      tlc += a[k * n + k];
      tld += a[k * n + n - 1 - k];
    }
    if (tla == s && tlb == s && tlc == s && tld == s) break;
  } while (std::next_permutation(a, a + nn));
}
int main() {
  scanf("%d", &n);
  nn = n * n;
  total = 0;
  for (int i = 0; i < nn; i++) {
    scanf("%I64d", a + i);
    total += a[i];
  }
  std::sort(a, a + nn);
  s = total / n;
  printf("%I64d\n", s);
  if (n < 4) {
    fac();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (j) putchar(32);
        printf("%d", a[i * n + j]);
      }
      putchar(10);
    }
  }
  return 0;
}
