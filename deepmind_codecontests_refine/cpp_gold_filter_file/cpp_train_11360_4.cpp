#include <bits/stdc++.h>
using namespace std;
const int MAX = 3e5 + 5;
int n, m;
long long t, a[MAX], a1[MAX];
int f(long long ma) {
  long long t1 = 0, t2 = 0;
  int can = 0, sol = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] <= ma) {
      if (a[i] + t1 <= t) {
        t1 += a[i];
        t2 += a[i];
        can++;
        sol++;
        if (can == m) {
          t1 += t2;
          t2 = 0;
          can = 0;
          if (t1 > t) break;
        }
      } else
        break;
    }
  }
  return sol;
}
int main() {
  int cas;
  scanf("%d", &cas);
  while (cas--) {
    scanf("%d%d%lld", &n, &m, &t);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
      a1[i] = a[i];
    }
    sort(a1 + 1, a1 + n + 1);
    f(7);
    int ini = 1, fin = n, sol = 0;
    while (ini <= fin) {
      int piv = (ini + fin) >> 1;
      if (f(a1[piv]) >= piv)
        ini = piv + 1, sol = piv;
      else
        fin = piv - 1;
    }
    if (sol > 0)
      printf("%d %lld\n", f(a1[sol]), a1[sol]);
    else
      printf("0 1\n");
  }
  return 0;
}
