#include <bits/stdc++.h>
using namespace std;
int N, Max, M, len, k;
class rec {
 public:
  int x, y, r, dp, num;
} p[5000];
int ll[5000], f[5000], g[5000], h[5000], n[5000], st[5000];
int ans[30000000];
int find(int x) {
  int l = 1;
  int r = M;
  for (; l < r;) {
    int mid = (l + r + 1) / 2;
    if (ll[mid] > x)
      r = mid - 1;
    else
      l = mid;
  }
  return l;
}
bool cmp(int a, int b) { return p[a].x < p[b].x; }
bool cmpr(rec a, rec b) { return a.r < b.r; }
bool cmpall(rec a, rec b) { return a.r < b.r || (a.r == b.r && a.x < b.x); }
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) scanf("%d %d", &p[i].x, &p[i].r), p[i].num = i;
  p[++N].x = 0;
  p[N].r = 2000000000;
  p[N].num = N;
  for (int i = 1; i <= N; i++) {
    p[i].y = p[i].x + p[i].r;
    p[i].x = p[i].x - p[i].r;
    ll[++len] = p[i].x;
    ll[++len] = p[i].y;
  }
  sort(ll + 1, ll + len + 1);
  M = 1;
  for (int i = 2; i <= len; i++)
    if (ll[M] != ll[i]) ll[++M] = ll[i];
  for (int i = 1; i <= N; i++) {
    p[i].x = find(p[i].x);
    p[i].y = find(p[i].y);
  }
  sort(p + 1, p + N + 1, cmpr);
  for (int i = 1; i <= N; i++) n[i] = i;
  sort(n + 1, n + N + 1, cmp);
  len = 0;
  for (int t = 1; t <= N; t++) {
    memset(f, 0, sizeof(f));
    int j = 1;
    Max = 0;
    k = 0;
    for (int i = p[t].x; i <= p[t].y; i++) {
      if (f[i] > Max) {
        Max = f[i];
        k = i;
      }
      if (j <= N)
        for (; j <= N; j++) {
          if (p[n[j]].x < p[t].x || p[n[j]].y > p[t].y) continue;
          if (p[n[j]].x == p[t].x && p[n[j]].y == p[t].y) continue;
          if (p[n[j]].x != i) break;
          if (f[p[n[j]].y] < Max + p[n[j]].dp) {
            f[p[n[j]].y] = Max + p[n[j]].dp;
            g[p[n[j]].y] = k;
            h[p[n[j]].y] = n[j];
          }
        }
    }
    p[t].dp = Max + 1;
    st[t] = len;
    ans[++len] = p[t].num;
    for (; k;) {
      for (int j = st[h[k]] + 1; j <= st[h[k] + 1]; j++) ans[++len] = ans[j];
      k = g[k];
    }
  }
  if (p[N].dp != len - st[N]) printf("= =\n");
  printf("%d\n", len - st[N] - 1);
  for (int j = st[N] + 2; j <= len; j++) printf("%d ", ans[j]);
  return 0;
}
