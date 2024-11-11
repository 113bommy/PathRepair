#include <bits/stdc++.h>
using namespace std;
const int maxn = 2001;
int n, m, mo, res, ans, num;
int A[maxn], B[maxn], PA[maxn], PB[maxn];
int main() {
  int i, j, k, l;
  bool ok;
  scanf("%d%d", &n, &m);
  if ((n + m) & 1)
    printf("0");
  else {
    scanf("%d", &num);
    res = (n - 1) * (m - 1) - num;
    ok = true;
    for (i = 1; i <= n; ++i) PA[i] = 1;
    for (i = 1; i <= m; ++i) PB[i] = 1;
    for (i = 1; i <= num; ++i) {
      scanf("%d%d%d", &j, &k, &l);
      ++A[j], ++B[k];
      PA[j] *= l, PB[j] *= l;
    }
    scanf("%d", &mo);
    for (i = 1; i <= n; ++i)
      if (A[i] == m) {
        ++res;
        if (PA[i] == 1) ok = false;
      }
    for (i = 1; i <= m; ++i)
      if (B[i] == n) {
        ++res;
        if (PB[i] == 1) ok = false;
      }
    if (ok) {
      ans = 1;
      for (i = 1; i <= res; ++i) ans = ans * 2 % mo;
      printf("%d", ans);
    } else
      printf("0");
  }
  return 0;
}
