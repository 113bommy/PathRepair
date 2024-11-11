#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000 + 5;
struct D {
  int u, v;
} a1[MAXN], a2[MAXN];
int x[MAXN], y[MAXN];
int costx[MAXN], costy[MAXN];
int rex[MAXN], rey[MAXN];
int reflag[MAXN];
long long sum1[MAXN], sum2[MAXN];
int cnt1, cnt2;
int re1[MAXN], re2[MAXN];
int vis[MAXN];
long long check(int mark, int tx, int ty) {
  return sum1[re1[mark]] * tx + sum2[re2[mark]] * ty;
}
bool cmp(D a, D b) { return a.v < b.v; }
int main() {
  int n, m, k, s;
  while (scanf("%d%d%d%d", &n, &m, &k, &s) != EOF) {
    costx[0] = costy[0] = (1000000007);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &x[i]);
      if (x[i] > costx[i - 1])
        costx[i] = costx[i - 1], rex[i] = rex[i - 1];
      else
        costx[i] = x[i], rex[i] = i;
    }
    for (int i = 1; i <= n; i++) {
      scanf("%d", &y[i]);
      if (y[i] > costy[i - 1])
        costy[i] = costy[i - 1], rey[i] = rey[i - 1];
      else
        costy[i] = y[i], rey[i] = i;
    }
    int u, v;
    cnt1 = cnt2 = 0;
    for (int i = 1; i <= m; i++) {
      scanf("%d%d", &u, &v);
      reflag[i] = u;
      if (u == 1)
        a1[++cnt1].v = v, a1[cnt1].u = i;
      else
        a2[++cnt2].v = v, a2[cnt2].u = i;
    }
    sort(a1 + 1, a1 + cnt1 + 1, cmp);
    sort(a2 + 1, a2 + cnt2 + 1, cmp);
    sum1[0] = sum2[0] = 0;
    for (int i = 1; i <= cnt1; i++) sum1[i] = sum1[i - 1] + a1[i].v;
    for (int i = 1; i <= cnt2; i++) sum2[i] = sum2[i - 1] + a2[i].v;
    int t1, t2;
    t1 = min(k, cnt1), t2 = k - t1;
    int ans = n + 1;
    int cnt = 0;
    re1[0] = re2[0] = 0;
    while (t2 <= cnt2 && t2 <= k) {
      re1[++cnt] = max(0, t1), re2[cnt] = t2;
      t1--, t2++;
    }
    for (int i = 1; i <= n; i++) {
      int le = 1, re = cnt;
      while (le < re - 1) {
        int t1 = (le + re) >> 1;
        int t2 = (t1 + re) >> 1;
        if (check(t1, costx[i], costy[i]) >= check(t2, costx[i], costy[i]))
          le = t1;
        else
          re = t2;
      }
      int mark = -1;
      if (check(le, costx[i], costy[i]) <= s)
        mark = le;
      else if (check(re, costx[i], costy[i]) <= s)
        mark = re;
      else if (check(1, costx[i], costy[i]) <= s)
        mark = 1;
      else if (check(cnt, costx[i], costy[i]) <= s)
        mark = n;
      if (mark == -1) continue;
      ans = i;
      for (int j = 1; j <= m; j++) vis[j] = 0;
      for (int t1 = 1; t1 <= re1[mark]; t1++) vis[a1[t1].u] = 1;
      for (int t2 = 1; t2 <= re2[mark]; t2++) vis[a2[t2].u] = 1;
      break;
    }
    if (ans > n) {
      printf("-1\n");
    } else {
      printf("%d\n", ans);
      for (int i = 1; i <= m; i++) {
        if (vis[i]) {
          if (reflag[i] == 1)
            printf("%d %d\n", i, rex[ans]);
          else
            printf("%d %d\n", i, rey[ans]);
        }
      }
    }
  }
  return 0;
}
