#include <bits/stdc++.h>
using namespace std;
const int N = 45;
const long long M = 1000000007ll;
long long c[N][N];
int n, m, len;
struct aa {
  long long a[N * 2][N * 2];
} ori, one, dat;
void work(aa &x, aa &y, aa &z) {
  int i, j, k;
  memset(dat.a, 0, sizeof(dat.a));
  for (i = 1; i <= len; i++)
    for (j = 1; j <= len; j++)
      for (k = 1; k <= len; k++)
        dat.a[i][j] = (dat.a[i][j] + x.a[i][k] * y.a[k][j] % M) % M;
  for (i = 1; i <= len; i++)
    for (j = 1; j <= len; j++) z.a[i][j] = dat.a[i][j];
  return;
}
int main(void) {
  int i, j;
  cin >> n >> m;
  len = 2 * m + 3;
  c[0][0] = c[1][0] = c[1][1] = 1;
  for (i = 2; i <= m; i++) {
    c[i][0] = c[i][i] = 1;
    for (j = 1; j < i; j++) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % M;
  }
  memset(ori.a, 0, sizeof(ori.a));
  memset(one.a, 0, sizeof(one.a));
  for (i = 1; i <= len; i++) one.a[i][i] = 1;
  ori.a[1][1] = 1;
  for (j = 0; j <= m; j++) ori.a[1][2 + j] = ori.a[1][2 + j + m + 1] = c[m][j];
  for (i = 0; i <= m; i++)
    for (j = 0; j <= i; j++)
      ori.a[2 + i][2 + j] = ori.a[2 + i][2 + j + m + 1] = c[i][j];
  for (i = 0; i <= m; i++)
    for (j = 0; j <= i; j++) ori.a[m + 3 + i][2 + j] = c[i][j];
  n--;
  while (n) {
    if (n & 1) work(one, ori, one);
    work(ori, ori, ori);
    n >>= 1;
  }
  long long k = 0;
  for (i = 1; i <= len; i++) k = (k + one.a[1][i]) % M;
  cout << k;
  return 0;
}
