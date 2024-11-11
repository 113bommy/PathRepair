#include <bits/stdc++.h>
long long rnb[40 + 1];
int main() {
  long long n;
  int nrb;
  scanf("%I64d", &n);
  nrb = 0;
  while ((1LL << nrb) <= (n - 1)) nrb++;
  nrb--;
  int i;
  rnb[1] = 1;
  for (i = 2; i <= 40; i++) rnb[i] = 2 * rnb[i - 1] + (1LL << (i - 1));
  long long rez = 0;
  while (nrb >= 0) {
    while (nrb >= 0 && (1LL << nrb) > (n - 1)) nrb--;
    if (nrb >= 0) {
      rez += (1LL << nrb);
      rez += rnb[nrb];
      n -= (1LL << nrb);
    }
  }
  printf("%I64d", rez);
  return 0;
}
