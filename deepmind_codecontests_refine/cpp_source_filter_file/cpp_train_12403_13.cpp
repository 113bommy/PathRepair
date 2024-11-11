#include <bits/stdc++.h>
using namespace std;
int n, m;
int M[41][1 << 6][1 << 6];
int solve(int i, int j, int k) {
  int p, q, r, &res = M[i][j][k];
  if (res == -1)
    if (i == n)
      if (k)
        res = n * m;
      else
        res = 0;
    else {
      res = n * m;
      for (p = 0; p < 1 << m; p++)
        if ((p & k) == k) {
          for (q = r = 0; q < m; q++)
            if (!(j & 1 << q || k & 1 << q || (q > 0 && k & 1 << (q - 1)) ||
                  (q + 1 < m && k & 1 << (q + 1))))
              r |= 1 << q;
          if (q == m)
            res = min(res, __builtin_popcount(p) + solve(i + 1, p, r));
        }
    }
  return res;
}
int main() {
  scanf("%d%d", &n, &m);
  if (m > n) swap(n, m);
  memset(M, -1, sizeof M);
  printf("%d\n", n * m - solve(0, 0, 0));
  return 0;
}
