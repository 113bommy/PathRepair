#include <bits/stdc++.h>
using namespace std;
int cif[100], sol[50][50];
int main() {
  int cnt = 4, u = 0, i, j;
  long long t;
  scanf("%lld", &t);
  while (t) {
    cif[u++] = t % 3;
    t = t / 3;
  }
  for (i = 0; i < u; i++) {
    if (i >= 1) {
      sol[i][i + 3] |= 1;
      sol[i + 3][i] |= 2;
      cnt += 2;
      if (i != u - 1) {
        sol[i][i + 4] |= 2;
        sol[i + 4][i] |= 1;
        cnt += 2;
      }
    }
    if (cif[i] == 0) sol[i + 1][i + 3] |= 2, cnt++;
    if (cif[i] != 2) sol[i + 3][i + 1] |= 1, cnt++;
  }
  sol[u + 2][u + 1] |= 1;
  sol[u + 1][u + 2] |= 2;
  sol[u + 2][u + 2] |= 1;
  sol[u + 2][u + 2] |= 2;
  printf("%d %d\n%d\n", u + 3, u + 3, cnt);
  for (i = 1; i <= u + 2; i++)
    for (j = 1; j <= u + 2; j++) {
      if (sol[i][j] & 1) printf("%d %d %d %d\n", i, j, i + 1, j);
      if (sol[i][j] & 2) printf("%d %d %d %d\n", i, j, i, j + 1);
    }
  return 0;
}
