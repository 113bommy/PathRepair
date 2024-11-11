#include <bits/stdc++.h>
using namespace std;
const int N = 3005;
const int K = 12;
int n, m, k, bl[N][K], br[N][K], cl[K], cr[K], tl[K], tr[K];
long long ans;
char a[2][N][N];
int s[2][N][N];
inline void work(int u, int d, int l, int r, int id) {
  if (d - u > r - l) {
    swap(u, l);
    swap(d, r);
    id ^= 1;
  }
  int m(l + r >> 1);
  for (int i = (u); i <= (d); ++i) {
    int t(0);
    bl[i][0] = m;
    char* T = a[id][i];
    for (int j = (m); j >= (l); --j) {
      if (T[j] == '1') bl[i][++t] = j;
      if (t == k + 1) break;
    }
    while (t < k + 1) bl[i][++t] = l - 1;
    t = 0;
    br[i][0] = m;
    for (int j = (m + 1); j <= (r); ++j) {
      if (T[j] == '1') br[i][++t] = j;
      if (t == k + 1) break;
    }
    while (t < k + 1) br[i][++t] = r + 1;
  }
  for (int i = (u); i <= (d); ++i) {
    cl[0] = cr[0] = m;
    for (int t = 1; t <= (k + 1); ++t) cl[t] = l - 1, cr[t] = r + 1;
    for (int j = (i); j <= (d); ++j) {
      memcpy(tl, cl, (k + 1) * sizeof(int));
      memcpy(tr, cr, (k + 1) * sizeof(int));
      int p(1), q(1);
      for (int t = 1; t <= (k + 1); ++t)
        if (tl[p] > bl[j][q])
          cl[t] = tl[p++];
        else
          cl[t] = bl[j][q++];
      p = 1, q = 1;
      for (int t = 1; t <= (k + 1); ++t)
        if (tr[p] < br[j][q])
          cr[t] = tr[p++];
        else
          cr[t] = br[j][q++];
      for (int t = (0); t <= (k); ++t)
        ans += (cl[t] - cl[t + 1]) * (cr[k - t + 1] - cr[0]);
    }
  }
  if (l < m) work(u, d, l, m - 1, id);
  if (m < r) work(u, d, m + 1, r, id);
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= (n); ++i) scanf("%s", a[0][i] + 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      a[1][j][i] = a[0][i][j];
    }
  }
  work(1, n, 1, m, 0);
  long long ans2 = ans;
  ans = 0;
  k -= 1;
  work(1, n, 1, m, 0);
  cout << ans2 - ans << "\n";
  return 0;
}
