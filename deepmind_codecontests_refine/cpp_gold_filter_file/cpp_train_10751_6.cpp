#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
using namespace std;
namespace ywy {
inline int get() {
  int n = 0;
  char c;
  while ((c = getchar()) || 23333)
    if (c >= '0' && c <= '9') break;
  n = c - '0';
  while ((c = getchar()) || 23333) {
    if (c >= '0' && c <= '9')
      n = n * 10 + c - '0';
    else
      return (n);
  }
}
int lef[50010 * 2], rgh[50010 * 2], minn[50010 * 2], sec[50010 * 2],
    cmin[50010 * 2], sig[50010 * 2], cnt[50010 * 2], gn = 1, fan[50010],
                                                     a[50010];
vector<int> chs[50010];
vector<int> qry[50010];
int anscnt[50010], anssig[50010], deep[50010], gdfn = 1;
int pid, now, dx, maxn[50010 * 2], sigall[50010 * 2], call[50010 * 2];
typedef struct _seg {
  int rt;
  vector<int> vec;
  inline void up(int tree) {
    minn[tree] = min(minn[lef[tree]], minn[rgh[tree]]);
    sec[tree] = 0x7fffffff;
    cnt[tree] = sig[tree] = 0;
    if (minn[lef[tree]] != minn[tree])
      sec[tree] = min(sec[tree], minn[lef[tree]]);
    else
      cnt[tree] += cnt[lef[tree]], sig[tree] += sig[lef[tree]];
    if (minn[rgh[tree]] != minn[tree])
      sec[tree] = min(sec[tree], minn[rgh[tree]]);
    else
      cnt[tree] += cnt[rgh[tree]], sig[tree] += sig[rgh[tree]];
    sec[tree] = min(sec[tree], sec[lef[tree]]);
    sec[tree] = min(sec[tree], sec[rgh[tree]]);
    maxn[tree] = max(maxn[lef[tree]], maxn[rgh[tree]]);
    sigall[tree] = sigall[lef[tree]] + sigall[rgh[tree]];
  }
  int build(int l, int r) {
    int me = gn;
    gn++;
    if (l == r) {
      int pt = fan[vec[l - 1]];
      minn[me] = maxn[me] = 1;
      sec[me] = 0x7fffffff;
      sig[me] = sigall[me] = deep[pt];
      cnt[me] = 1;
      return (me);
    }
    int mid = (l + r) >> 1;
    lef[me] = build(l, mid);
    rgh[me] = build(mid + 1, r);
    up(me);
    return (me);
  }
  inline void down(int tree, int l, int r) {
    if (call[tree]) {
      int mid = (l + r) >> 1;
      cnt[lef[tree]] = mid - l + 1;
      cnt[rgh[tree]] = r - mid;
      sig[lef[tree]] = sigall[lef[tree]];
      sig[rgh[tree]] = sigall[rgh[tree]];
      int x = call[tree];
      call[tree] = 0;
      sec[lef[tree]] = sec[rgh[tree]] = 0x7fffffff;
      maxn[lef[tree]] = maxn[rgh[tree]] = minn[lef[tree]] = minn[rgh[tree]] = x;
      call[lef[tree]] = call[rgh[tree]] = x;
      cmin[lef[tree]] = cmin[rgh[tree]] = 0;
    }
    if (cmin[tree]) {
      int x = cmin[tree];
      cmin[tree] = 0;
      int g = min(minn[lef[tree]], minn[rgh[tree]]);
      if (minn[lef[tree]] == g) {
        minn[lef[tree]] = x;
        if (sec[lef[tree]] == 0x7fffffff) maxn[lef[tree]] = x;
        cmin[lef[tree]] = x;
        call[lef[tree]] = 0;
      }
      if (minn[rgh[tree]] == g) {
        minn[rgh[tree]] = x;
        if (sec[rgh[tree]] == 0x7fffffff) maxn[rgh[tree]] = x;
        cmin[rgh[tree]] = x;
        call[rgh[tree]] = 0;
      }
    }
  }
  void stb(int rl, int rr, int l, int r, int tree) {
    if (minn[tree] > now) return;
    int mid = (l + r) >> 1;
    if (l != r) down(tree, l, r);
    if (rl == l && rr == r) {
      if (maxn[tree] <= now) {
        cmin[tree] = 0;
        call[tree] = maxn[tree] = minn[tree] = now + dx;
        sec[tree] = 0x7fffffff;
        cnt[tree] = r - l + 1;
        sig[tree] = sigall[tree];
        anscnt[pid] += (r - l + 1);
        anssig[pid] += sigall[tree];
        return;
      }
      if (minn[tree] <= now && sec[tree] > now + dx) {
        cmin[tree] = minn[tree] = now + dx;
        anscnt[pid] += cnt[tree];
        anssig[pid] += sig[tree];
        return;
      }
      stb(l, mid, l, mid, lef[tree]);
      stb(mid + 1, r, mid + 1, r, rgh[tree]);
      up(tree);
      return;
    }
    if (rl > mid)
      stb(rl, rr, mid + 1, r, rgh[tree]);
    else {
      if (rr <= mid)
        stb(rl, rr, l, mid, lef[tree]);
      else {
        stb(rl, mid, l, mid, lef[tree]);
        stb(mid + 1, rr, mid + 1, r, rgh[tree]);
      }
    }
    up(tree);
  }
} Segtree;
int sz[50010][200 + 2];
Segtree ts[200 + 2];
int size[50010], dfn[50010];
void dfs(int pt) {
  dfn[pt] = gdfn;
  fan[gdfn] = pt;
  gdfn++;
  size[pt] = 1;
  if (a[pt] <= 200) sz[pt][a[pt]]++;
  for (register int i = 0; i < chs[pt].size(); i++) {
    deep[chs[pt][i]] = deep[pt] + 1;
    dfs(chs[pt][i]);
    size[pt] += size[chs[pt][i]];
    for (register int j = 1; j <= 200; j++) sz[pt][j] += sz[chs[pt][i]][j];
  }
}
namespace sgt {
int data[50010 * 4];
void addpt(int l, int r, int tree, int pt, int x) {
  data[tree] += x;
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (pt <= mid)
    addpt(l, mid, (tree << 1), pt, x);
  else
    addpt(mid + 1, r, ((tree << 1) | 1), pt, x);
}
int query(int rl, int rr, int l, int r, int tree) {
  if (!data[tree] || rl > rr) return (0);
  if (l == r) return (l);
  int mid = (l + r) >> 1;
  if (rl == l && rr == r) {
    if (data[(tree << 1)]) return (query(l, mid, l, mid, (tree << 1)));
    return (query(mid + 1, r, mid + 1, r, ((tree << 1) | 1)));
  }
  if (rl > mid) return (query(rl, rr, mid + 1, r, ((tree << 1) | 1)));
  if (rr <= mid) return (query(rl, rr, l, mid, (tree << 1)));
  int t = query(rl, mid, l, mid, (tree << 1));
  if (t) return (t);
  return (query(mid + 1, rr, mid + 1, r, ((tree << 1) | 1)));
}
}  // namespace sgt
int n, q;
void solve(int pt) {
  for (register int i = 0; i < qry[pt].size(); i++)
    sgt::addpt(1, q, 1, qry[pt][i], 1);
  if (a[pt] > 200) {
    int lst = 1;
    while (1) {
      int dst = sgt::query(lst, q, 1, q, 1);
      if (!dst) break;
      lst = dst + a[pt];
      anscnt[dst]++;
      anssig[dst] += deep[pt];
    }
  }
  for (register int i = 0; i < chs[pt].size(); i++) solve(chs[pt][i]);
  for (register int i = 0; i < qry[pt].size(); i++)
    sgt::addpt(1, q, 1, qry[pt][i], -1);
}
int pts[50010];
void ywymain() {
  n = get(), q = get();
  for (register int i = 1; i <= n; i++) a[i] = get();
  for (register int i = 2; i <= n; i++) chs[get()].push_back(i);
  dfs(1);
  for (register int i = 1; i <= n; i++) {
    if (a[i] <= 200) ts[a[i]].vec.push_back(dfn[i]);
  }
  for (register int i = 1; i <= 200; i++) {
    if (!sz[1][i]) continue;
    sort(ts[i].vec.begin(), ts[i].vec.end());
    ts[i].rt = ts[i].build(1, ts[i].vec.size());
  }
  for (register int i = 1; i <= q; i++) {
    int me = get();
    pts[i] = me;
    pid = i;
    now = i;
    int dl = dfn[me], dr = dfn[me] + size[me] - 1;
    for (register int j = 1; j <= 200; j++) {
      if (!sz[me][j]) continue;
      int ans = -1, l = 0, r = ts[j].vec.size() - 1;
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (ts[j].vec[mid] >= dl)
          ans = mid, r = mid - 1;
        else
          l = mid + 1;
      }
      int rl = ans;
      ans = -1;
      l = 0, r = ts[j].vec.size() - 1;
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (ts[j].vec[mid] <= dr)
          ans = mid, l = mid + 1;
        else
          r = mid - 1;
      }
      int rr = ans;
      dx = j;
      ts[j].stb(rl + 1, rr + 1, 1, ts[j].vec.size(), ts[j].rt);
    }
    qry[me].push_back(i);
  }
  solve(1);
  for (register int i = 1; i <= q; i++) {
    printf("%d %d\n", anssig[i] - deep[pts[i]] * anscnt[i], anscnt[i]);
  }
}
}  // namespace ywy
int main() {
  ywy::ywymain();
  return (0);
}
