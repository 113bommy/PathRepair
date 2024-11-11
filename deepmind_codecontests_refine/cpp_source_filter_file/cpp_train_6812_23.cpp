#include <bits/stdc++.h>
using namespace std;
int a[200][200];
int dp[200][200][20];
int n, m, k;
const int oo = -1e6;
int f(int i, int j, int t) {
  int &ret = dp[i][j][t];
  if (ret != -1) return ret;
  if (i == 0) return ret = ((a[i][j] + t) % k) == 0 ? a[i][j] : oo;
  int c1 = oo;
  int c2 = oo;
  if (j + 1 < m) c1 = f(i - 1, j + 1, (t + a[i][j]) % k) + a[i][j];
  if (j - 1 >= 0) c2 = f(i - 1, j - 1, (t + a[i][j]) % k) + a[i][j];
  return ret = max(c1, c2);
}
void print(int i, int j, int t) {
  if (i == 0) return;
  int c1 = oo;
  int c2 = oo;
  if (j + 1 < m) c1 = f(i - 1, j + 1, (t + a[i][j]) % k) + a[i][j];
  if (j - 1 >= 0) c2 = f(i - 1, j - 1, (t + a[i][j]) % k) + a[i][j];
  if (c1 >= c2) {
    putchar('R');
    print(i - 1, j + 1, (t + a[i][j]) % k);
  } else {
    putchar('L');
    print(i - 1, j - 1, (t + a[i][j]) % k);
  }
}
int main() {
  memset(dp, -1, sizeof(dp));
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%1d", &a[i][j]);
  k++;
  int res = oo;
  int j = -1;
  for (int i = 0; i < m; i++) {
    int t = f(n - 1, i, 0);
    if (t > res) {
      res = t;
      j = i;
    }
  }
  if (j == -1) return puts("-1"), 0;
  cout << res << endl;
  cout << j + 1 << endl;
  print(n - 1, j, 0);
  return 0;
}
