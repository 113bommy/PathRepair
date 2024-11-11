#include <bits/stdc++.h>
using namespace std;
const int maxn = 510000;
int n, p, q, r;
int card[maxn][3];
struct node {
  int al, ar, br;
};
vector<node> V[maxn];
struct segment {
  int mx[maxn << 2], mn[maxn << 2];
  long long sum[maxn << 2];
  int flag[maxn << 2];
  int lx, rx, c;
  void pushdown(const int x, const int l, const int r) {
    if (!flag[x]) return;
    int fl = flag[x];
    flag[x] = 0;
    int lc = x << 1, rc = lc | 1;
    mx[lc] = mx[rc] = fl;
    mn[lc] = mn[rc] = fl;
    flag[lc] = flag[rc] = fl;
    int mid = l + r >> 1;
    sum[lc] = (long long)(mid - l + 1) * fl;
    sum[rc] = (long long)(r - mid) * fl;
  }
  void upd(const int x, const int l, const int r) {
    if (rx < l || r < lx) return;
    if (mn[x] >= c) return;
    if (lx <= l && r <= rx) {
      if (mx[x] <= c) {
        flag[x] = mx[x] = mn[x] = c;
        sum[x] = (long long)(r - l + 1) * c;
        return;
      }
    }
    pushdown(x, l, r);
    int mid = l + r >> 1, lc = x << 1, rc = lc | 1;
    upd(lc, l, mid);
    upd(rc, mid + 1, r);
    sum[x] = sum[lc] + sum[rc];
    mx[x] = max(mx[lc], mx[rc]);
    mn[x] = min(mn[lc], mn[rc]);
  }
} seg;
int main() {
  scanf("%d%d%d%d", &n, &p, &q, &r);
  for (int i = 1; i <= n; i++)
    scanf("%d%d%d", &card[i][0], &card[i][1], &card[i][2]);
  for (int i = 1; i <= n; i++) {
    int a = card[i][0], b = card[i][1], c = card[i][2];
    V[r].push_back((node){1, a, b});
    V[c].push_back((node){1, a, q});
    if (a < p) V[c].push_back((node){a + 1, p, b});
  }
  long long ans = 0;
  for (int i = r; i >= 1; i--) {
    for (int j = 0; j < V[i].size(); j++) {
      node now = V[i][j];
      seg.lx = now.al, seg.rx = now.ar, seg.c = now.br;
      seg.upd(1, 1, p);
    }
    ans += seg.sum[1];
  }
  ans = (long long)p * q * r - ans;
  printf("%lld\n", ans);
  return 0;
}
