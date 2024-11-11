#include <bits/stdc++.h>
using namespace std;
long long read() {
  char ch = getchar();
  long long x = 0, ff = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') ff = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * ff;
}
void write(long long aa) {
  if (aa < 0) putchar('-'), aa = -aa;
  if (aa > 9) write(aa / 10);
  putchar('0' + aa % 10);
  return;
}
const long long inf = 0x3f3f3f3f3f3f3f3f;
long long n, K, cnt, na;
long long sum[100005], id[100005];
long long rk[100005], val[100005];
long long ban[100005], lg[100005], mn[100005][21], mx[100005][21];
long long R[100005], vis[100005];
struct node {
  long long sum, sz;
} ans, now, F[100005];
struct qujian {
  long long l, r;
} a[100005];
struct zhu {
  long long sum, sz, R;
  long long son[2];
} tt[4000005];
zhu operator+(zhu aa, zhu bb) {
  return (zhu){aa.sum + bb.sum, aa.sz + bb.sz, max(aa.R, bb.R), 0, 0};
}
node operator+(node aa, node bb) {
  return (node){aa.sum + bb.sum, aa.sz + bb.sz};
}
bool cmp(long long aa, long long bb) { return sum[aa] < sum[bb]; }
void update(long long &rt, long long qq, long long ll, long long rr,
            long long kk) {
  rt = ++cnt;
  tt[rt] = tt[qq];
  tt[rt].R = max(tt[rt].R, id[kk]);
  tt[rt].sum += val[kk];
  tt[rt].sz++;
  if (ll == rr) return;
  long long mid = (ll + rr) >> 1;
  if (kk <= mid)
    update(tt[rt].son[0], tt[qq].son[0], ll, mid, kk);
  else
    update(tt[rt].son[1], tt[qq].son[1], mid + 1, rr, kk);
  return;
}
zhu query(long long rt, long long ll, long long rr, long long zhi) {
  if (!rt || val[rr] <= zhi) return (zhu){0, 0, 0, 0, 0};
  if (val[ll] > zhi) return tt[rt];
  if (ll == rr) return (zhu){0, 0, 0, 0, 0};
  long long mid = (ll + rr) >> 1;
  if (val[mid] <= zhi) return query(tt[rt].son[1], mid + 1, rr, zhi);
  return tt[tt[rt].son[1]] + query(tt[rt].son[0], ll, mid, zhi);
}
long long getmx(long long l, long long r) {
  long long nw = -inf;
  if (l < 1) nw = 0, l++;
  if (l > r) return nw;
  long long oo = lg[r - l + 1];
  return max(nw, max(mx[l][oo], mx[r - (1 << oo) + 1][oo]));
}
long long getmn(long long l, long long r) {
  long long nw = inf;
  if (l < 1) nw = 0, l++;
  if (l > r) return nw;
  long long oo = lg[r - l + 1];
  return min(nw, min(mn[l][oo], mn[r - (1 << oo) + 1][oo]));
}
long long ok(long long aa) {
  for (long long i = 1; i <= n; ++i) {
    vis[i] = 0;
    zhu qwq = query(ban[i], 1, n, sum[i - 1] - aa);
    R[i] = qwq.R;
    now.sum += qwq.sum - (sum[i - 1] - aa) * qwq.sz;
    now.sz += qwq.sz;
  }
  long long wz = 1;
  na = 0;
  for (long long i = 1; i <= n; ++i)
    if (R[i] >= wz) {
      wz = max(wz, i);
      while (wz <= R[i]) vis[wz] = 1, wz++;
    }
  if (!vis[1]) a[++na] = (qujian){0, 0};
  for (long long i = 1; i <= n; ++i)
    if (vis[i]) {
      if (i == 1 || !vis[i - 1]) a[++na] = (qujian){i - 1, 0};
      if (i == n || !vis[i + 1]) a[na].r = i;
    } else if (i > 1 && !vis[i - 1])
      a[++na] = (qujian){i, i};
  if (!vis[n]) a[++na] = (qujian){n, n};
  if (na == 1) return now.sz <= K;
  node qq = (node){-inf, 0};
  for (long long i = 1; i <= na; ++i) {
    if (i == 1)
      F[i] = (node){0, 0};
    else
      F[i] = qq + (node){getmx(a[i].l, a[i].r) + aa, 1};
    node pp = F[i] + (node){-getmn(a[i].l, a[i].r), 0};
    if ((pp.sum > qq.sum) || (pp.sum == qq.sum && pp.sz < qq.sz)) qq = pp;
  }
  now = now + F[na];
  return now.sz <= K;
}
int main() {
  n = read(), K = read();
  long long er = 0;
  for (long long i = 1; i <= n; ++i) {
    if ((1 << (er + 1)) <= i) er++;
    lg[i] = er;
  }
  for (long long i = 1; i <= n; ++i) sum[i] = read() + sum[i - 1], id[i] = i;
  sort(id + 1, id + n + 1, cmp);
  for (long long i = 1; i <= n; ++i) rk[id[i]] = i, val[i] = sum[id[i]];
  for (long long i = n; i >= 1; --i) update(ban[i], ban[i + 1], 1, n, rk[i]);
  for (long long i = 1; i <= n; ++i) mx[i][0] = sum[i], mn[i][0] = sum[i];
  for (long long i = 1; i <= lg[n]; ++i)
    for (long long j = 1; j + (1 << i) - 1 <= n; ++j)
      mx[j][i] = max(mx[j][i - 1], mx[j + (1 << (i - 1))][i - 1]),
      mn[j][i] = min(mn[j][i - 1], mn[j + (1 << (i - 1))][i - 1]);
  long long l = -1e15, r = 1e15;
  while (l + 1 < r) {
    long long mid = (l + r) >> 1;
    now = (node){0, 0};
    if (ok(mid))
      l = mid, ans = now;
    else
      r = mid;
  }
  write(ans.sum - K * l);
  return 0;
}
