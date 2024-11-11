#include <bits/stdc++.h>
using namespace std;
char tab[55][55];
bool mark[222][222];
bool touse[222][222];
int rr[55 * 55];
int cc[55 * 55];
int n, t = 0;
bool InRange(int p) { return p >= 1 && p <= n; }
void COMPUTE() {
  for (int p = (1); p <= (n); p += (1))
    for (int q = (1); q <= (n); q += (1))
      if ('o' == tab[p][q]) {
        t++;
        rr[t] = p;
        cc[t] = q;
      }
  for (int p = (1); p <= (n); p += (1))
    for (int q = (1); q <= (n); q += (1))
      if ('.' == tab[p][q]) {
        for (int r = (1); r <= (t); r += (1)) {
          mark[55 + p - rr[r]][55 + q - cc[r]] = 1;
        }
      }
  for (int p = (1); p <= (n); p += (1))
    for (int q = (1); q <= (n); q += (1))
      if ('x' == tab[p][q]) {
        int flag = 0;
        for (int r = (1); r <= (t); r += (1)) {
          if (!mark[55 + p - rr[r]][55 + q - cc[r]]) {
            touse[n + p - rr[r]][n + q - cc[r]] = flag = 1;
            r = t;
          }
        }
        if (0 == flag) {
          printf("NO\n");
          return;
        }
      }
  printf("YES\n");
  for (int p = (1); p <= (2 * n - 1); p += (1)) {
    for (int q = (1); q <= (2 * n - 1); q += (1)) {
      if (p == q && p == n)
        printf("o");
      else if (touse[p][q])
        printf("x");
      else
        printf(".");
    }
    printf("\n");
  }
}
int main() {
  scanf("%d", &n);
  for (int p = (1); p <= (n); p += (1)) {
    scanf("%s", &tab[p]);
    for (int q = (n); q >= (1); q -= (1)) tab[p][q] = tab[p][q - 1];
  }
  COMPUTE();
}
