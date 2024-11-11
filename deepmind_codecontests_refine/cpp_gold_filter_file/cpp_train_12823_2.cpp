#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
int a[4][2010], b[4][10010];
int ans = -1;
int mx[110];
int n, m;
int cmp(int x, int y) { return mx[x] > mx[y]; }
int bias[5];
void dfs(int col) {
  if (col == m + 1) {
    int can = 0;
    for (int r = 0; r < n; r++) {
      int rowmax = 0;
      for (int c = 0; c < m; c++) {
        rowmax = max(rowmax, b[(r + bias[c]) % n][c]);
      }
      can += rowmax;
    }
    ans = max(can, ans);
  } else {
    for (int i = 0; i < n; i++) {
      bias[col] = i;
      dfs(col + 1);
    }
  }
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    scanf("%d%d", &n, &m);
    memset(mx, 0, sizeof(mx));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int temp;
        scanf("%d", &temp);
        a[i][j] = temp;
        mx[j] = max(mx[j], temp);
      }
    }
    int p[110];
    for (int i = 0; i < m; i++) {
      p[i] = i;
    }
    sort(p, p + m, cmp);
    m = min(m, n);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        b[j][i] = a[j][p[i]];
      }
    }
    ans = -1;
    dfs(0);
    printf("%d\n", ans);
  }
}
