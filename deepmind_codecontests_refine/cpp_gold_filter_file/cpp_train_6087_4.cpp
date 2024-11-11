#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000")
using namespace std;
const long double pi = acos(-1.0);
const int K = 7;
const int N = 1 << K;
const int M = (int)1e9 + 7;
const long long M2 = M * (long long)M;
int go[N][N], cur[N][N], tmp[N][N], ways[N], nways[N], x;
void mult(int (&a)[N][N], int (&b)[N][N], int (&c)[N][N], int n) {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      long long cur = 0;
      for (int k = 0; k < n; ++k)
        if ((cur += a[i][k] * (long long)b[k][j]) >= M2) cur -= M2;
      tmp[i][j] = cur % M;
    }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) c[i][j] = tmp[i][j];
}
int main() {
  ways[0] = 1;
  for (int i = 1; i <= K; ++i) {
    for (int m1 = 0; m1 < (1 << i); ++m1)
      for (int m2 = 0; m2 < (1 << i); ++m2) {
        go[m1][m2] = 0, cur[m1][m2] = (m1 == m2) ? 1 : 0;
        for (int m = 0; m < (1 << (i - 1)); ++m) {
          int m3 = ((m << 1) | 1 | (1 << i)), cnt = 1;
          for (int j = 0; j < i; ++j)
            if (((m1 >> j) & 1) && ((m2 >> j) & 1) && ((m3 >> j) & 1) &&
                ((m3 >> (j + 1)) & 1)) {
              cnt = 0;
              break;
            }
          go[m1][m2] += cnt;
        }
      }
    for (int m = 0; m < (1 << (i - 1)); ++m) {
      ways[m + (1 << (i - 1))] = ways[m];
      ways[m] = 0;
    }
    scanf("%d", &x);
    for (int j = 30; j >= 0; --j) {
      mult(cur, cur, cur, 1 << i);
      if ((x >> j) & 1) mult(cur, go, cur, 1 << i);
    }
    for (int m1 = 0; m1 < (1 << i); ++m1) {
      nways[m1] = 0;
      for (int m = 0; m < (1 << i); ++m)
        nways[m1] = (nways[m1] + ways[m] * (long long)cur[m][m1]) % M;
    }
    for (int m = 0; m < (1 << i); ++m) ways[m] = nways[m];
  }
  printf("%d\n", ways[(1 << K) - 1]);
  return 0;
}
