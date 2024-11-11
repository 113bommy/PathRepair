#include <bits/stdc++.h>
using namespace std;
int d[4000 + 10][4000 + 10], a[4000 + 10];
inline int mmax(int a, int b) { return a > b ? a : b; }
int main() {
  int n, nmax = 1;
  int mfront;
  memset(d, 0, sizeof(d));
  scanf("%d", &n);
  a[0] = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    mfront = 0;
    for (int j = 0; j < i; ++j) {
      d[i][j] = d[j][mfront] + 1;
      if (a[j] == a[i]) mfront = j;
      nmax = mmax(nmax, d[i][j]);
    }
  }
  printf("%d\n", nmax);
  return 0;
}
