#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
using ll = long long;
int n, m, r, h[N], d[N];
ll mxl[N][N], cntl[N][N], mxr[N][N], cntr[N][N], a[N][N], p[N][N];
ll ans = 0, cnt = 0;
inline void update(ll vv, ll cc) {
  if (ans < vv)
    ans = vv, cnt = cc;
  else if (ans == vv)
    cnt += cc;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> r;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j], a[i][j] += a[i][j - 1];
  h[0] = r;
  for (int i = 1; i <= r; i++) h[i] = sqrt(r * r - i * i);
  for (int i = 0; i <= r * 2; i++)
    for (int j = 0; j <= r; j++)
      if (j >= i - r) d[i] = max(d[i], h[j] + h[abs(i - j)] + 1);
  for (int i = r + 1; i <= n - r; i++)
    for (int j = r + 1; j <= m - r; j++)
      for (int k = -r; k <= r; k++)
        p[i][j] += a[i + k][j + h[abs(k)]] - a[i + k][j - h[abs(k)] - 1];
  for (int i = r + 1; i <= n - r; i++)
    for (int j = r + 1; j <= m - r; j++) {
      mxl[i][j] = mxl[i][j - 1];
      cntl[i][j] = cntl[i][j - 1];
      if (p[i][j] > mxl[i][j])
        mxl[i][j] = p[i][j], cntl[i][j] = 1;
      else if (p[i][j] == mxl[i][j])
        ++cntl[i][j];
    }
  for (int i = r + 1; i <= n - r; i++)
    for (int j = m - r; j > r; --j) {
      mxr[i][j] = mxr[i][j + 1];
      cntr[i][j] = cntr[i][j - 1];
      if (p[i][j] > mxr[i][j])
        mxr[i][j] = p[i][j], cntr[i][j] = 1;
      else if (p[i][j] == mxr[i][j])
        ++cntr[i][j];
    }
  for (int i = r + 1; i <= n - r; i++)
    for (int j = r + 1; j <= m - r; j++) {
      ll sum = p[i][j];
      for (int k = r + 1; k <= n - r; k++) {
        if (abs(k - i) >= 2 * r + 1) {
          update(sum + mxl[k][m - r], cntl[k][m - r]);
          continue;
        }
        if (j - d[abs(k - i)] > r)
          update(sum + mxl[k][j - d[abs(k - i)]], cntl[k][j - d[abs(k - i)]]);
        if (j + d[abs(k - i)] <= m - r)
          update(sum + mxr[k][j + d[abs(k - i)]], cntr[k][j + d[abs(k - i)]]);
      }
    }
  cout << ans << ' ' << cnt / 2 << endl;
  return 0;
}
