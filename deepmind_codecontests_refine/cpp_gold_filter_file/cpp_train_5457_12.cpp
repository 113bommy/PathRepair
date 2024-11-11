#include <bits/stdc++.h>
#pragma comment(linker, "/stack:16777216")
using namespace std;
const int INF = 1000000000;
const int MAX = 5007;
const int MAX2 = 1000000;
const int BASE = 1000000000;
const int CNT = 20;
int n, m;
char A[MAX][MAX];
int C[MAX][MAX];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = (0); i < (n); ++i) scanf("%s", A[i]);
  for (int i = (0); i < (n); ++i) {
    int j = 0;
    while (j < m) {
      if (A[i][j] == '0')
        ++j;
      else {
        int k = 1;
        while (j + k < m && A[i][j + k] == '1') ++k;
        C[j][j + k - 1]++;
        j += k;
      }
    }
  }
  int res = 0;
  for (int i = 0; i < m; ++i)
    for (int j = m - 1; j >= 0; --j) {
      if (i > 0) C[i][j] += C[i - 1][j];
      if (j + 1 < m) C[i][j] += C[i][j + 1];
      if (i > 0 && j + 1 < m) C[i][j] -= C[i - 1][j + 1];
      if (j >= i) res = max(res, (j - i + 1) * C[i][j]);
    }
  printf("%d\n", res);
  return 0;
}
