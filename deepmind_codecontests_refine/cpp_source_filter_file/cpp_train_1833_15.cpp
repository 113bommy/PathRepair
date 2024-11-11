#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
struct Sofa {
  int x[2], y[2];
  int l, r, t, b;
} a[N];
int cntX[N], cntY[N];
int d, n, m;
int cntL, cntR, cntT, cntB;
int main() {
  ios::sync_with_stdio(false);
  cin >> d;
  cin >> n >> m;
  for (int i = 1; i <= d; ++i) {
    cin >> a[i].y[0] >> a[i].x[0] >> a[i].y[1] >> a[i].x[1];
    if (a[i].x[0] > a[i].x[1]) swap(a[i].x[0], a[i].x[1]);
    if (a[i].y[0] > a[i].y[1]) swap(a[i].y[0], a[i].y[1]);
    cntX[a[i].x[0]]++;
    cntY[a[i].y[0]]++;
  }
  cin >> cntL >> cntR >> cntT >> cntB;
  for (int i = 1; i <= n; ++i) cntX[i] += cntX[i - 1];
  for (int i = 1; i <= m; ++i) cntY[i] += cntY[i - 1];
  for (int i = 1; i <= d; ++i) {
    a[i].t = cntX[a[i].x[1] - 1];
    if (a[i].x[0] == a[i].x[1] - 1) a[i].t--;
    a[i].l = cntY[a[i].y[1] - 1];
    if (a[i].y[0] == a[i].y[1] - 1) a[i].l--;
  }
  memset(cntX, 0, sizeof(cntX));
  memset(cntY, 0, sizeof(cntY));
  for (int i = 1; i <= d; ++i) {
    cntX[a[i].x[1]]++;
    cntY[a[i].y[1]]++;
  }
  for (int i = n; i >= 1; --i) cntX[i] += cntX[i + 1];
  for (int i = m; i >= 1; --i) cntY[i] += cntY[i + 1];
  for (int i = 1; i <= d; ++i) {
    a[i].b = cntX[a[i].x[0] + 1];
    if (a[i].x[1] == a[i].x[0] + 1) a[i].b--;
    a[i].r = cntY[a[i].y[0] + 1];
    if (a[i].y[1] == a[i].y[0] + 1) a[i].r--;
  }
  int ans = -1;
  for (int i = 1; i <= d; ++i) {
    if (a[i].l == cntL && a[i].r == cntR && a[i].t == cntT && a[i].b == cntB) {
      ans = i;
      break;
    }
  }
  cout << ans << '\n';
  return 0;
}
