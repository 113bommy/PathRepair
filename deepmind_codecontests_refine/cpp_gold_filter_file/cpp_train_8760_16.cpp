#include <bits/stdc++.h>
using namespace std;
long long read() {
  char ch = getchar();
  long long x = 0, ff = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') ff = -ff;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * ff;
}
void write(long long aa) {
  if (aa < 0) putchar('-'), aa = -aa;
  if (aa > 9) write(aa / 10);
  putchar(aa % 10 + '0');
  return;
}
const long long inf = 1e18;
long long n, m, p, sum[1000005], a[1000005];
struct node {
  long long x, y, val;
};
vector<node> tt[4000005];
vector<node> up(vector<node> aa, vector<node> bb, long long S) {
  vector<node> cc;
  long long la = aa.size(), lb = bb.size();
  long long l = 0, r = 0, len = 0;
  for (long long i = 0; i < la; ++i) {
    node qq = aa[i];
    while (qq.x + qq.val + S > bb[l].y) l++;
    if (l && qq.x + qq.val + S < bb[l].x) l--;
    while (r + 1 < lb && qq.y + qq.val + S > bb[r].y) r++;
    if (qq.y + qq.val + S < bb[r].x) r--;
    long long now = qq.x, md = qq.x + qq.val + S;
    for (long long j = l; j <= r; ++j) {
      node pp;
      pp.x = now;
      if (j != r)
        now += bb[j + 1].x - md, md = bb[j + 1].x;
      else
        now = qq.y + 1, md = qq.y + qq.val + 1 + S;
      pp.y = now - 1;
      pp.val = bb[j].val + qq.val;
      if (len && cc[len - 1].val == pp.val)
        cc[len - 1].y = pp.y;
      else
        cc.push_back(pp), len++;
    }
  }
  return cc;
}
void bt(long long rt, long long ll, long long rr) {
  if (ll == rr) {
    tt[rt].push_back((node){-inf, p - a[ll] - 1, 0});
    tt[rt].push_back((node){p - a[ll], inf, -p});
    return;
  }
  long long mid = (ll + rr) >> 1;
  bt(rt << 1, ll, mid);
  bt(rt << 1 | 1, mid + 1, rr);
  tt[rt] = up(tt[rt << 1], tt[rt << 1 | 1], sum[mid] - sum[ll - 1]);
  return;
}
long long query(long long rt, long long ll, long long rr, long long L,
                long long R, long long kk) {
  if (ll == L && rr == R) {
    long long l = 0, r = tt[rt].size();
    while (l + 1 < r) {
      long long mid = (l + r) >> 1;
      if (tt[rt][mid].x > kk)
        r = mid;
      else
        l = mid;
    }
    return kk + tt[rt][l].val + sum[rr] - sum[ll - 1];
  }
  long long mid = (ll + rr) >> 1;
  if (R <= mid)
    return query(rt << 1, ll, mid, L, R, kk);
  else if (L > mid)
    return query(rt << 1 | 1, mid + 1, rr, L, R, kk);
  return query(rt << 1 | 1, mid + 1, rr, mid + 1, R,
               query(rt << 1, ll, mid, L, mid, kk));
}
int main() {
  n = read(), m = read(), p = read();
  for (long long i = 1; i <= n; ++i) a[i] = read(), sum[i] = sum[i - 1] + a[i];
  bt(1, 1, n);
  for (long long i = 1; i <= m; ++i) {
    long long x = read(), y = read();
    write(query(1, 1, n, x, y, 0)), puts("");
  }
  return 0;
}
