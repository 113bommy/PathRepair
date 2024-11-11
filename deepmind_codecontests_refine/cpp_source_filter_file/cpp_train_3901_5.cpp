#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int dp[maxn];
struct Segtree {
  int l, r, mx;
} tr[maxn * 4];
inline void push_up(int id) {
  tr[id].mx = min(tr[id << 1].mx, tr[id << 1 | 1].mx);
}
void build(int id, int l, int r) {
  tr[id].l = l;
  tr[id].r = r;
  if (l == r) {
    tr[id].mx = dp[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(id << 1, l, mid);
  build(id << 1 | 1, mid + 1, r);
  push_up(id);
}
int ask(int id, int l, int r) {
  if (tr[id].l == l && tr[id].r == r) return tr[id].mx;
  int mid = (tr[id].l + tr[id].r) >> 1;
  if (r <= mid) return ask(id << 1, l, r);
  if (l > mid) return ask(id << 1 | 1, l, r);
  return min(ask(id << 1, l, mid), ask(id << 1 | 1, mid + 1, r));
}
void updata(int id, int x, int v) {
  if (tr[id].l == tr[id].r) {
    tr[id].mx = v;
    return;
  }
  int mid = (tr[id].l + tr[id].r) >> 1;
  if (x <= mid)
    updata(id << 1, x, v);
  else
    updata(id << 1 | 1, x, v);
  push_up(id);
}
int Lg[maxn], minx[maxn][20], maxx[maxn][20];
void initRMQ(int num) {
  Lg[1] = 0;
  for (int i = 2; i <= num; ++i) Lg[i] = Lg[i / 2] + 1;
  for (int j = 1; j < 20; ++j)
    for (int i = 1; i <= num; ++i)
      if (i + (1 << j) - 1 <= num) {
        maxx[i][j] = max(maxx[i][j - 1], maxx[i + (1 << (j - 1))][j - 1]);
        minx[i][j] = min(minx[i][j - 1], minx[i + (1 << (j - 1))][j - 1]);
      }
}
inline int query(int l, int r) {
  int t = Lg[r - l + 1];
  return max(maxx[l][t], maxx[r - (1 << t) + 1][t]) -
         min(minx[l][t], minx[r - (1 << t) + 1][t]);
}
int n, s, l;
inline int get_pos(int p) {
  int l = 1, r = p - 1, mid, res = p;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (query(mid, p) <= s) {
      res = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  return res;
}
int main() {
  scanf("%d%d%d", &n, &s, &l);
  if (l > n) return puts("-1");
  for (int i = 1; i <= n; ++i) {
    scanf("%d", minx[i]);
    maxx[i][0] = minx[i][0];
  }
  initRMQ(n);
  if (query(1, l) > s) return puts("-1");
  memset(dp, 0x3f, sizeof(dp));
  dp[l] = 1;
  dp[0] = 0;
  build(1, 0, n);
  for (int i = l + 1; i <= n; ++i) {
    int p = get_pos(i);
    if (i - p + 1 < l) continue;
    dp[i] = ask(1, p - 1, i - l) + 1;
    updata(1, i, dp[i]);
  }
  if (dp[n] == 0x3f3f3f3f)
    puts("-1");
  else
    printf("%d\n", dp[n]);
  return 0;
}
