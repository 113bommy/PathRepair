#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INFLL = 1e18;
const int MOD = 1e9 + 7;
const int MAXN = 500 + 5;
int A[MAXN][MAXN];
int B[MAXN][MAXN];
int n, m;
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%d", &A[i][j]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%d", &B[i][j]);
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < m - 1; j++) {
      if (A[i][j]) {
        A[i][j] ^= 1;
        A[i + 1][j + 1] ^= 1;
        A[i][j + 1] ^= 1;
        A[i + 1][j] ^= 1;
      }
      if (B[i][j]) {
        B[i][j] ^= 1;
        B[i + 1][j + 1] ^= 1;
        B[i][j + 1] ^= 1;
        B[i + 1][j] ^= 1;
      }
    }
  for (int i = 0; i < n; i++) {
    if (A[i][m - 1] != B[i][m - 1]) {
      printf("No\n");
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    if (A[n - 1][i] != B[n - 1][i]) {
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
  return 0;
}
