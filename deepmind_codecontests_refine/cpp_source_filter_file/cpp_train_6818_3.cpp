#include <bits/stdc++.h>
using namespace std;
int n, m, a[100007], b[100007], len[100007], pos[100007], mn[100007],
    pmn[100007], res[100007];
bool vis[100007];
int read() {
  int num = 0, f = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (c >= '0' && c <= '9') num = num * 10 + c - '0', c = getchar();
  return num * f;
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  a[++n] = 1e9 + 7;
  m = read();
  for (int i = 1; i <= m; i++) b[i] = read();
  sort(b + 1, b + m + 1);
  memset(mn, 0x3f, sizeof mn);
  mn[0] = 0;
  for (int i = 1; i <= n; i++)
    if (a[i] != -1) {
      int p = lower_bound(mn + 1, mn + n + 1, a[i]) - mn - 1;
      len[i] = p + 1, pos[i] = pmn[p], mn[p + 1] = a[i], pmn[p + 1] = i;
    } else
      for (int j = m, p = n; j >= 1; j--) {
        while (mn[p] >= b[j]) p--;
        mn[p + 1] = b[j], pmn[p + 1] = i;
      }
  for (int i = len[n] - 1, j = n, k = a[n]; i >= 0; i--)
    if (a[j] != -1) {
      if (a[pos[j]] == -1) {
        int p = lower_bound(b + 1, b + m + 1, a[j]) - b - 1;
        vis[p] = 1;
        k = res[pos[j]] = b[p];
      } else
        k = a[pos[j]];
      j = pos[j];
    } else {
      bool ck = 0;
      for (int p = j - 1; p >= 1; p--)
        if (a[p] != -1 && len[p] == i && a[p] < k) {
          j = p;
          k = a[p];
          ck = 1;
          break;
        }
      if (ck) continue;
      for (int p = j - 1; p >= 1; p--)
        if (a[p] == -1) {
          int l = lower_bound(b + 1, b + m + 1, k) - b - 1;
          vis[l] = 1;
          k = res[p] = b[l];
          j = l;
          break;
        }
    }
  for (int i = 1, j = 1; i <= n; i++)
    if (a[i] == -1 && !res[i]) {
      while (vis[j]) j++;
      vis[j] = 1;
      res[i] = b[j];
    } else if (!res[i])
      res[i] = a[i];
  for (int i = 1; i < n; i++) printf("%d ", res[i]);
  putchar('\n');
  return 0;
}
