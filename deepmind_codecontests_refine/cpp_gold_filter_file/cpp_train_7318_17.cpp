#include <bits/stdc++.h>
#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize(4)
#pragma GCC optimize(5)
#pragma GCC optimize(6)
#pragma GCC optimize(7)
#pragma GCC optimize(8)
#pragma GCC optimize(9)
using namespace std;
const int INF = 1e9;
inline int pt(int a[], int l, int r) {
  int p, i, j;
  p = a[l];
  i = l;
  j = r + 1;
  for (;;) {
    while (a[++i] < p)
      if (i >= r) break;
    while (a[--j] > p)
      if (j <= l) break;
    if (i >= j)
      break;
    else
      swap(a[i], a[j]);
  }
  if (j == l) return j;
  swap(a[l], a[j]);
  return j;
}
inline void q_sort(int a[], int l, int r) {
  int q;
  if (r > l) {
    q = pt(a, l, r);
    q_sort(a, l, q - 1);
    q_sort(a, q + 1, r);
  }
}
inline int readint() {
  int x = 0;
  int f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  if (ch == '-') {
    f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int mx[101][10101];
int dp[101][10101];
int w[101];
int n, m;
int sum[101][10101];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  int i, j, k;
  for (i = 1; i <= n; i++) {
    cin >> w[i];
    for (j = 1; j <= w[i]; j++) {
      cin >> sum[i][j];
      sum[i][j] += sum[i][j - 1];
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= w[i]; j++) {
      for (k = 0; k <= j; k++) {
        mx[i][j] =
            max(mx[i][j], sum[i][k] + (sum[i][w[i]] - sum[i][w[i] - (j - k)]));
      }
    }
  }
  int t, mn;
  for (i = 1; i <= n; i++) {
    for (j = 0; j <= m; j++) {
      t = 0;
      mn = min(w[i], j);
      for (k = 0; k <= mn; k++) t = max(t, dp[i - 1][j - k] + mx[i][k]);
      dp[i][j] = t;
    }
  }
  cout << dp[n][m] << endl;
  return 0;
}
