#include <bits/stdc++.h>
using namespace std;
const int N = 15, M = 1e5 + 5;
int n, m, p[N];
bool mt[N][N], fg[N], pd[M];
bool mp[N][N], f[1 << 6][N];
int a[N], b[N];
bool dp() {
  memset(f, 0, sizeof(f));
  for (int i = 1; i <= n; i++)
    if (mt[a[i]][b[i]]) f[1 << (i - 1)][i] = 1;
  for (int i = 0; i < (1 << n); i++)
    for (int j = 1; j <= n; j++)
      if (f[i][j]) {
        for (int k = 1; k <= n; k++)
          if (!(i & (1 << (k - 1))) && mp[j][k]) f[i + (1 << (k - 1))][k] = 1;
      }
  for (int i = 1; i <= n; i++)
    if (f[(1 << n) - 1][i]) return 1;
  return 0;
}
void d1(int d, int s) {
  if (d > n) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        mp[i][j] = ((mt[a[i]][a[j]] && mt[b[i]][b[j]]) ||
                    (mt[a[i]][b[j]] && mt[b[i]][a[j]]));
      }
    }
    pd[s] = dp();
    return;
  }
  int t = -1, tp[N];
  for (int i = 1; i <= n + n; i++)
    if (!fg[i]) tp[++t] = i;
  fg[tp[0]] = 1;
  a[d] = tp[0];
  for (int i = 1; i <= t; i++)
    fg[tp[i]] = 1, b[d] = tp[i], d1(d + 1, s * p[d] + i - 1), fg[tp[i]] = 0;
  fg[tp[0]] = 0;
}
int c[N];
bool d3(int d, int s) {
  if (d > 1) {
  }
  if (d > n) {
    return pd[s];
  }
  int t = -1, tp[N];
  for (int i = 1; i <= n + n; i++)
    if (!fg[i]) tp[++t] = i;
  fg[tp[0]] = 1;
  a[d] = tp[0];
  for (int i = 1; i <= t; i++)
    if (c[tp[i]] == c[tp[0]]) {
      fg[tp[i]] = 1, b[d] = tp[i];
      if (d3(d + 1, s * p[d] + i - 1)) {
        fg[tp[i]] = fg[tp[0]] = 0;
        return 1;
      }
      fg[tp[i]] = 0;
    }
  fg[tp[0]] = 0;
  return 0;
}
long long A[N][N], ans;
void d2(int d, int mx) {
  if (d > n + n) {
    memset(fg, 0, sizeof(fg));
    if (d3(1, 0)) {
      ans += A[m][mx];
    }
    return;
  }
  for (int i = 1; i <= mx; i++) c[d] = i, d2(d + 1, mx);
  if (mx < m) c[d] = mx + 1, d2(d + 1, mx + 1);
}
int main() {
  int T;
  cin >> n >> T >> m;
  A[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    A[i][0] = 1;
    for (int j = 1; j <= i; j++) A[i][j] = A[i - 1][j - 1] * j + A[i - 1][j];
  }
  n >>= 1;
  for (int u, v, i = 1; i <= T; i++)
    scanf("%d%d", &u, &v), mt[u][v] = mt[v][u] = 1;
  for (int i = 1; i <= n; i++) p[i] = (n - i) * 2 + 1;
  d1(1, 0);
  d2(1, 0);
  cout << ans << endl;
  return 0;
}
