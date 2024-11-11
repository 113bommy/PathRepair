#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int INF = (1 << 30) - 1;
int n, q;
char ts[110], s[110];
int vis[110];
int l, r, cnt[20];
int main() {
  scanf("%d%d", &n, &q);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; ++i) ts[i] = s[i];
  for (int o = 1; o <= q; ++o) {
    scanf("%d%d", &l, &r);
    int p = l, d = 1, pre = -1;
    memset(cnt, 0, sizeof(cnt));
    memset(vis, 0, sizeof(vis));
    memcpy(s, ts, sizeof(ts));
    while (p >= l && p <= r) {
      if (vis[p]) {
        p += d;
        continue;
      }
      if (s[p] >= '0' && s[p] <= '9') {
        cnt[s[p] - '0']++;
        s[p]--;
        if (s[p] < '0') vis[p] = 1;
        p += d;
        pre = -1;
      } else {
        if (pre != -1) vis[pre] = 1;
        if (s[p] == '>')
          d = 1;
        else
          d = -1;
        pre = p;
        p += d;
      }
    }
    for (int i = 0; i <= 9; ++i) printf("%d ", cnt[i]);
    puts("");
  }
  return 0;
}
