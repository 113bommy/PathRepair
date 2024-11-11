#include <bits/stdc++.h>
long long ans = 0;
char arr[2507][2507];
int bl[2507][10], br[2507][10];
int cl[10], cr[10], tl[10], tr[10], k;
void solve(int u, int d, int l, int r) {
  if (d - u > r - l) {
    int m = (d + u) / 2;
    for (int i = l; i <= r; ++i) {
      bl[i][0] = br[i][0] = m;
      int t = 0;
      for (int j = m + 1; j <= d; ++j) {
        if (arr[j][i] == '1') br[i][++t] = j;
        if (t == k + 1) break;
      }
      while (t < k + 1) br[i][++t] = u - 1;
      t = 0;
      for (int j = m; j >= u; --j) {
        if (arr[j][i] == '1') bl[i][++t] = j;
        if (t == k + 1) break;
      }
      while (t < k + 1) bl[i][++t] = d + 1;
    }
    for (int i = l; i <= r; ++i) {
      cr[0] = cl[0] = m;
      for (int t = 1; t <= k + 1; ++t) cr[t] = u - 1, cl[t] = d + 1;
      for (int j = i; j <= r; ++j) {
        for (int t = 0; t <= k + 1; ++t) tl[t] = cl[t], tr[t] = cr[t];
        int p = 1, q = 1;
        for (int t = 1; t <= k + 1; ++t) {
          if (tr[p] < br[j][q])
            cr[t] = tr[p++];
          else
            cr[t] = br[j][q++];
        }
        p = q = 1;
        for (int t = 1; t <= k + 1; ++t) {
          if (tl[p] > bl[j][q])
            cl[t] = tl[p++];
          else
            cl[t] = bl[j][q++];
        }
        for (int t = 0; t <= k; ++t)
          ans += (cl[t] - cl[t + 1]) * (cr[k - t + 1] - cr[k - t]);
      }
    }
    if (m > u) solve(u, m - 1, l, r);
    if (m < d) solve(m + 1, d, l, r);
  } else {
    int m = (l + r) / 2;
    for (int i = u; i <= d; ++i) {
      bl[i][0] = br[i][0] = m;
      int t = 0;
      for (int j = m + 1; j <= r; ++j) {
        if (arr[i][j] == '1') br[i][++t] = j;
        if (t == k + 1) break;
      }
      while (t < k + 1) br[i][++t] = r + 1;
      t = 0;
      for (int j = m; j >= l; --j) {
        if (arr[i][j] == '1') bl[i][++t] = j;
        if (t == k + 1) break;
      }
      while (t < k + 1) bl[i][++t] = l - 1;
    }
    for (int i = u; i <= d; ++i) {
      cr[0] = cl[0] = m;
      for (int t = 1; t <= k + 1; ++t) cr[t] = r + 1, cl[t] = l - 1;
      for (int j = i; j <= d; ++j) {
        for (int t = 0; t <= k + 1; ++t) tl[t] = cl[t], tr[t] = cr[t];
        int p = 1, q = 1;
        for (int t = 1; t <= k + 1; ++t) {
          if (tr[p] < br[j][q])
            cr[t] = tr[p++];
          else
            cr[t] = br[j][q++];
        }
        p = q = 1;
        for (int t = 1; t <= k + 1; ++t) {
          if (tl[p] > bl[j][q])
            cl[t] = tl[p++];
          else
            cl[t] = bl[j][q++];
        }
        for (int t = 0; t <= k; ++t)
          ans += (cl[t] - cl[t + 1]) * (cr[k - t + 1] - cr[k - t]);
      }
    }
    if (m > l) solve(u, d, l, m - 1);
    if (m < r) solve(u, d, m + 1, r);
  }
}
int main() {
  int n, m;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; ++i) scanf("%s", arr[i] + 1);
  solve(1, n, 1, m);
  printf("%lld", ans);
  return 0;
}
