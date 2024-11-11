#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int sum = 0, t = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') t = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    sum = sum * 10 + ch - '0';
    ch = getchar();
  }
  return sum * t;
}
int n, m, k;
int a[2][2505][2505];
int bl[2505][2505], br[2505][2505];
int cl[2505], cr[2505], tl[2505], tr[2505];
char s[2505];
long long ans;
void solve(int x1, int x2, int y1, int y2, int o) {
  if (x2 - x1 > y2 - y1) swap(x1, y1), swap(x2, y2), o ^= 1;
  int mid = (y1 + y2) >> 1;
  for (int i = x1; i <= x2; i++) {
    int t = 0;
    bl[i][0] = mid;
    for (int j = mid; j >= y1; j--) {
      if (a[o][i][j]) bl[i][++t] = j;
      if (t == k + 1) break;
    }
    while (t < k + 1) bl[i][++t] = y1 - 1;
    t = 0;
    br[i][0] = mid;
    for (int j = mid + 1; j <= y2; j++) {
      if (a[o][i][j]) br[i][++t] = j;
      if (t == k + 1) break;
    }
    while (t < k + 1) br[i][++t] = y2 + 1;
  }
  for (int i = x1; i <= x2; i++) {
    cl[0] = cr[0] = mid;
    for (int t = 1; t <= k + 1; t++) cl[t] = y1 - 1, cr[t] = y2 + 1;
    for (int j = i; j <= x2; j++) {
      for (int t = 1; t <= k + 1; t++) tl[t] = cl[t], tr[t] = cr[t];
      int p = 1, q = 1;
      for (int t = 1; t <= k + 1; t++)
        if (tl[p] > bl[j][q])
          cl[t] = tl[p++];
        else
          cl[t] = bl[j][q++];
      p = 1, q = 1;
      for (int t = 1; t <= k + 1; t++)
        if (tr[p] < br[j][q])
          cr[t] = tr[p++];
        else
          cr[t] = br[j][q++];
      for (int t = 0; t <= k; t++)
        ans += (cl[t] - cl[t + 1]) * (cr[k - t + 1] - cr[k - t]);
    }
  }
  if (y1 < mid) solve(x1, x2, y1, mid - 1, o);
  if (y2 > mid) solve(x1, x2, mid + 1, y2, o);
}
int main() {
  n = read(), m = read(), k = read();
  for (int i = 1; i <= n; i++) {
    scanf("%s", s + 1);
    for (int j = 1; j <= n; j++) a[0][i][j] = a[1][j][i] = s[j] - '0';
  }
  solve(1, n, 1, m, 0);
  printf("%lld\n", ans);
}
