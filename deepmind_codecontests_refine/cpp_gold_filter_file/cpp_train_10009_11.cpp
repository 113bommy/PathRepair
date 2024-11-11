#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MXN = 1e3 + 7;
const int mod = 998244353;
int n, m;
int ar[MXN][MXN];
int br[MXN];
struct lp {
  int m, v;
} A[MXN][MXN], B[MXN][MXN];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) scanf("%d", &ar[i][j]);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      br[j] = ar[i][j];
    }
    sort(br + 1, br + 1 + m);
    int k = unique(br + 1, br + 1 + m) - br - 1;
    for (int j = 1; j <= m; ++j) {
      A[i][j].m = k;
      A[i][j].v = lower_bound(br + 1, br + 1 + k, ar[i][j]) - br;
    }
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      br[j] = ar[j][i];
    }
    sort(br + 1, br + 1 + n);
    int k = unique(br + 1, br + 1 + n) - br - 1;
    for (int j = 1; j <= n; ++j) {
      B[j][i].m = k;
      B[j][i].v = lower_bound(br + 1, br + 1 + k, ar[j][i]) - br;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int t = abs(A[i][j].v - B[i][j].v);
      if (A[i][j].v > B[i][j].v) {
        printf("%d ", max(A[i][j].m, B[i][j].m + t));
      } else if (A[i][j].v < B[i][j].v) {
        printf("%d ", max(A[i][j].m + t, B[i][j].m));
      } else {
        printf("%d ", max(A[i][j].m, B[i][j].m));
      }
    }
    printf("\n");
  }
  return 0;
}
