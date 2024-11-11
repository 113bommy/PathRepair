#include <bits/stdc++.h>
using namespace std;
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
int a[35][35];
int c[3];
void work() {
  int n, m;
  scanf("%d%d", &n, &m);
  memset(a, 0, sizeof a);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &a[i][j]);
      ++a[i][j];
    }
  }
  int n2 = (n + m - 1) / 2;
  long long ans = 0;
  for (int i = 0; i < n2; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (m - 1 - (i - j) < 0) {
        continue;
      }
      if (n - j - 1 < 0) {
        continue;
      }
      ++c[a[j][i - j]];
      ++c[a[n - j - 1][m - 1 - (i - j)]];
    }
    ans += min(c[1], c[2]);
    c[1] = 0;
    c[2] = 0;
  }
  printf("%lld\n", ans);
}
int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    work();
  }
}
