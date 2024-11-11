#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 233;
int i, j, k, n, m;
int ra, fh;
char rx;
inline int read() {
  rx = getchar(), ra = 0, fh = 1;
  while ((rx < '0' || rx > '9') && rx != '-') rx = getchar();
  if (rx == '-') fh = -1, rx = getchar();
  while (rx >= '0' && rx <= '9') ra = ra * 10 + rx - 48, rx = getchar();
  return ra * fh;
}
int main() {
  n = read();
  int pret = -23, cnt = 0, ans = 1;
  for (i = 1; i <= n; i++) {
    j = read(), k = read();
    char ap = getchar();
    if (ap == 'p') j += 12;
    int nt = j * 60 + k;
    if (nt > pret)
      pret = nt, cnt = 1;
    else if (nt < pret)
      ans++, pret = nt, cnt = 1;
    else if ((++cnt) > 10)
      cnt = 1, ans++;
  }
  printf("%d\n", ans);
}
