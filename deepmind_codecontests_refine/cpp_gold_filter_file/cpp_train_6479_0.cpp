#include <bits/stdc++.h>
using namespace std;
char A[102];
int M[102][205][3][52];
int dp(int i, int x, int d, int n) {
  if (n < 0) return 0;
  if (!A[i] && n == 0) return abs(x - 102);
  if (!A[i]) return 0;
  int &r = M[i][x][d == 1][n];
  if (r == -1) {
    if (A[i] == 'F') {
      r = max(dp(i + 1, x + d, d, n),
              max(max(dp(i, x, d, n - 2), dp(i + 1, x + d, d, n - 2)),
                  dp(i + 1, x, d * -1, n - 1)));
    } else {
      r = max(dp(i + 1, x, d * -1, n),
              max(max(dp(i, x, d * -1, n - 2), dp(i + 1, x, d * -1, n - 2)),
                  dp(i + 1, x + d, d, n - 1)));
    }
  }
  return r;
}
int main() {
  int n;
  scanf("%s %d", A, &n);
  memset(M, -1, sizeof(M));
  printf("%d\n", dp(0, 102, 1, n));
}
