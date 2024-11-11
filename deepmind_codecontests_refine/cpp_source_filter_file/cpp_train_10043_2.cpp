#include <bits/stdc++.h>
using namespace std;
const int maxn = (1 << 16) + 10;
int d[maxn], q[maxn], n, s[maxn], ww[maxn][2], cnt;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d%d", &d[i], &s[i]);
  int hh, tt;
  hh = tt = 0;
  for (int i = 0; i < n; ++i)
    if (d[i] == 1) q[tt++] = i;
  while (hh < tt) {
    int x = q[hh++];
    if (!d[x]) continue;
    ww[cnt][0] = x;
    ww[cnt++][1] = s[x];
    --d[s[x]];
    --d[x];
    s[s[x]] ^= x;
    if (!d[s[x]]) q[tt++] = s[x];
  }
  printf("%d\n", cnt);
  for (int i = 0; i < cnt; ++i) printf("%d %d\n", ww[i][0], ww[i][1]);
  return 0;
}
