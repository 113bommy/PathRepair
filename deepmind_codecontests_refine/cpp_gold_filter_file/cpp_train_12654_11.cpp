#include <bits/stdc++.h>
unsigned int a[500][500];
int main() {
  unsigned short n;
  unsigned short i;
  unsigned long long sr[500];
  unsigned long long sc[500];
  unsigned short ce;
  unsigned short j;
  unsigned short ie;
  unsigned short je;
  long long sol;
  unsigned long long s;
  unsigned long long d;
  unsigned long long sd1;
  unsigned long long sd2;
  if (scanf("%hu", &n) != 1) return -1;
  if (n < 1 || n > 500) return -1;
  for (i = 0; i < n; i++) {
    sr[i] = 0;
    sc[i] = 0;
  }
  ce = 0;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
      if (scanf("%u", &a[i][j]) != 1) return -1;
      if (!a[i][j] && ce) return -1;
      if (!a[i][j]) {
        ie = i;
        je = j;
        ce = 1;
      } else if (a[i][j] > 1000000000)
        return -1;
      sr[i] += a[i][j];
      sc[j] += a[i][j];
    }
  if (!ce) return -1;
  if (n == 1)
    sol = 1;
  else {
    sol = 0;
    s = (ie ? sr[0] : sr[n - 1]);
    for (i = 0; i < n; i++)
      if ((sr[i] != s && ie != i) || (sc[i] != s && je != i)) sol = -1;
    if (sr[ie] != sc[je] || sr[ie] >= s)
      sol = -1;
    else if (sol != -1) {
      d = s - sr[ie];
      if (d > 1000000000000000000ULL)
        sol = -1;
      else {
        sd1 = (ie == je ? d : 0);
        sd2 = (ie + je == n - 1 ? d : 0);
        for (i = 0; i < n; i++) {
          sd1 += a[i][i];
          sd2 += a[i][n - 1 - i];
        }
        sol = (sd1 == sd2 && sd1 == s ? d : -1);
      }
    }
  }
  printf("%I64d\n", sol);
  return 0;
}
