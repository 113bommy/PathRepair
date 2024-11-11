#include <bits/stdc++.h>
using namespace std;
int n, s, a[2010], f[2010], g[2010], p[2010], pre[2010], tot;
bool cw[2010];
pair<int, int> sec[2010];
bool cmp(int x, int y) { return (a[x] > a[y]) || (a[x] == a[y] && x < y); }
int dis(int x, int y) { return min(abs(x - y), n - abs(x - y)); }
int cwdis(int x, int y) { return (y - x + n) % n; }
int ccwdis(int x, int y) { return (x - y + n) % n; }
void moveto(int x, int y) {
  int d1 = cwdis(x, y), d2 = ccwdis(x, y);
  if (d1 <= d2)
    printf("+%d\n", d1);
  else
    printf("-%d\n", d2);
}
int main() {
  scanf("%d%d", &n, &s);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    p[i] = i;
  }
  sort(p + 1, p + n + 1, cmp);
  int l = 1, r = 0;
  for (; l <= n; l = r + 1, r = l) {
    while (a[p[r + 1]] == a[p[l]] && r < n) r++;
    for (int i = l; i <= r; i++) {
      if (l == 1)
        g[p[i]] = 0;
      else {
        g[p[i]] = 1 << 30;
        for (int j = sec[tot].first; j <= sec[tot].second; j++)
          if (f[p[j]] + dis(p[i], p[j]) < g[p[i]])
            g[p[i]] = f[p[j]] + dis(p[i], p[j]), pre[i] = j;
      }
    }
    if (l == r)
      f[p[l]] = g[p[l]];
    else
      for (int i = l; i <= r; i++) {
        int u = i == l ? p[r] : p[i - 1];
        int v = i == r ? p[l] : p[i + 1];
        if (g[u] + cwdis(p[i], u) < g[v] + cwdis(v, p[i]))
          f[p[i]] = g[u] + cwdis(p[i], u), cw[i] = 1;
        else
          f[p[i]] = g[v] + cwdis(v, p[i]), cw[i] = 0;
      }
    sec[++tot] = make_pair(l, r);
  }
  int ans = 1 << 30, k;
  for (int i = sec[tot].first; i <= sec[tot].second; i++)
    if (f[p[i]] + dis(s, p[i]) < ans) ans = f[p[i]] + dis(s, p[i]), k = i;
  printf("%d\n", ans);
  moveto(s, p[k]);
  for (int i = tot; i; i--) {
    int len = sec[i].second - sec[i].first + 1, l = sec[i].first;
    if (cw[k]) {
      for (int j = 1; j < len; j++)
        printf("+%d\n",
               cwdis(p[(k + j - 1 - l) % len + l], p[(k + j - l) % len + l]));
      k = (k - 1 + len - l) % len + l;
    } else {
      for (int j = 1; j < len; j++)
        printf("-%d\n", ccwdis(p[(k - j + 1 + len - l) % len + l],
                               p[(k - j + len - l) % len + l]));
      k = (k + 1 + len - l) % len + l;
    }
    if (i > 1) {
      moveto(p[k], p[pre[k]]);
      k = pre[k];
    }
  }
}
