#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
void add(int &x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}
int sum(int x, int y) {
  add(x, y);
  return x;
}
int mul(long long x, long long y) { return (x * y) % MOD; }
const int MAXN = 3600 + 50;
const int MAXM = 3600 + 50;
bool a[MAXN][MAXM];
int usedx[MAXN], usedy[MAXM];
int dpx[MAXN][MAXN], dpy[MAXM][MAXM];
int cnk[MAXN][MAXN];
int fact[MAXN];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, kol;
  cin >> n >> m >> kol;
  memset(a, 0, sizeof(a));
  memset(usedx, 0, sizeof(usedx));
  memset(usedy, 0, sizeof(usedy));
  for (int i = 0; i < kol; ++i) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    a[x1 - 1][y1 - 1] = true;
    a[x2 - 1][y2 - 1] = true;
    usedx[x1 - 1] = true;
    usedx[x2 - 1] = true;
    usedy[y1 - 1] = true;
    usedy[y2 - 1] = true;
  }
  memset(cnk, 0, sizeof(cnk));
  fact[0] = 1;
  for (int i = 0; i <= max(n, m); ++i) {
    cnk[i][0] = 1;
    if (i) fact[i] = mul(i, fact[i - 1]);
    for (int j = 1; j <= i; ++j) {
      cnk[i][j] = sum(cnk[i - 1][j], cnk[i - 1][j - 1]);
    }
  }
  memset(dpx, 0, sizeof(dpx));
  dpx[0][0] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j <= i; ++j) {
      dpx[i][j] = dpx[i - 1][j];
      if (j && i >= 2 && !usedx[i - 1] && !usedx[i - 2])
        add(dpx[i][j], dpx[i - 2][j - 1]);
    }
  memset(dpy, 0, sizeof(dpy));
  dpy[0][0] = 1;
  for (int i = 1; i <= m; ++i)
    for (int j = 0; j <= m; ++j) {
      dpy[i][j] = dpy[i - 1][j];
      if (j && i >= 2 && !usedy[i - 1] && !usedy[i - 2])
        add(dpy[i][j], dpy[i - 2][j - 1]);
    }
  int ans = 0;
  int kolx = 0;
  for (int i = 0; i < n; ++i)
    if (!usedx[i]) ++kolx;
  int koly = 0;
  for (int i = 0; i < m; ++i)
    if (!usedy[i]) ++koly;
  long long gans = 0;
  for (int x = 0; x <= kolx; ++x)
    for (int y = 0; y <= koly; ++y) {
      long long ans = 1;
      ans = mul(ans, dpx[n][x]);
      if (y > kolx - 2 * x) continue;
      ans = mul(ans, cnk[kolx - 2 * x][y]);
      ans = mul(ans, fact[y]);
      ans = mul(ans, dpy[m][y]);
      if (x > koly - 2 * y) continue;
      ans = mul(ans, cnk[koly - 2 * y][x]);
      ans = mul(ans, fact[x]);
      gans = sum(gans, ans);
    }
  cout << gans << "\n";
  return 0;
}
