#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
const int K = 30;
int n, k;
int a[N], b[N];
int step[K][N];
int main() {
  scanf("%d%d", &n, &k);
  a[n] = 0;
  for (int i = n - 1; i >= 1; --i) {
    a[i] = 1;
  }
  for (int i = 0; i < k; ++i) {
    int pp = 1;
    step[i][n] = n;
    for (int j = 1; j < n; ++j) {
      pp = max(pp, j + 1);
      for (; pp <= n; ++pp) {
        if (a[pp] + a[j] <= n - j) {
          a[j] += a[pp];
          step[i][j] = pp;
          break;
        }
      }
    }
  }
  for (int i = 0; i < k; ++i) {
    for (int j = 1; j <= n; ++j) {
      printf("%d%c", step[i][j], " \n"[j == n]);
    }
  }
  return 0;
}
