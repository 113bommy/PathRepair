#include <bits/stdc++.h>
using namespace std;
int A[1 << 10][1 << 10];
char H[1 << 10][1 << 10];
char V[1 << 10][1 << 10];
int R[1 << 10];
int f(int x, int y, int m) {
  int a = R[x];
  int b = R[y];
  int i;
  int res = 0;
  for (i = (0); i < (m); ++i) {
    if ((a ^ b) != (V[x][i] == 'N' ? 1 : 0)) ++res;
    if (i != m - 1) {
      if (H[x][i] == 'N') a ^= 1;
      if (H[y][i] == 'N') b ^= 1;
    }
  }
  return res;
}
int g(int x, int y, int n) {
  int a = R[x];
  int b = R[y];
  int i;
  int res = 0;
  for (i = (0); i < (n); ++i) {
    if ((a ^ b) != (H[i][x] == 'N' ? 1 : 0)) ++res;
    if (i != n - 1) {
      if (V[i][x] == 'N') a ^= 1;
      if (V[i][y] == 'N') b ^= 1;
    }
  }
  return res;
}
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  int i, j;
  for (i = (0); i < (n); ++i) {
    scanf("%s", H[i]);
    if (i != n - 1) scanf("%s", V[i]);
  }
  int cnt[] = {0, 0};
  for (i = (0); i < (n); ++i)
    for (j = (0); j < (m); ++j) {
      if (i != n - 1) ++cnt[V[i][j] == 'N' ? 1 : 0];
      if (j != m - 1) ++cnt[H[i][j] == 'N' ? 1 : 0];
    }
  if (k == 1) {
    if (cnt[0] * 4 >= 3 * (cnt[0] + cnt[1])) {
      printf("YES\n");
      for (i = (0); i < (n); ++i)
        for (j = (0); j < (m); ++j) printf("1%c", j == m - 1 ? '\n' : ' ');
    } else
      printf("NO\n");
    return 0;
  }
  if (n < m) {
    memset(R, 0, sizeof(R));
    for (i = (0); i < (n - 1); ++i)
      if (2 * f(i, i + 1, m) > m - 1) R[i + 1] ^= 1;
    for (i = (0); i < (n); ++i) {
      int a = R[i];
      for (j = (0); j < (m); ++j) {
        A[i][j] = a;
        if (j != m - 1 && H[i][j] == 'N') a ^= 1;
      }
    }
  } else {
    memset(R, 0, sizeof(R));
    for (i = (0); i < (m - 1); ++i)
      if (2 * g(i, i + 1, n) > n - 1) R[i + 1] ^= 1;
    for (i = (0); i < (m); ++i) {
      int a = R[i];
      for (j = (0); j < (n); ++j) {
        A[j][i] = a;
        if (j != n - 1 && V[j][i] == 'N') a ^= 1;
      }
    }
  }
  printf("YES\n");
  for (i = (0); i < (n); ++i)
    for (j = (0); j < (m); ++j)
      printf("%d%c", A[i][j] + 1, j == m - 1 ? '\n' : ' ');
  return 0;
};
