#include <bits/stdc++.h>
using namespace std;
struct node {
  int b, c, pc;
  long long sum, ps;
} blk[100005];
struct range {
  int l, i, r;
} rg[100005];
int a[100005], g[100005][30], h[100005][30], cnt[100005];
int n, m;
long long lenb, lenc, L, R, MID;
long long sum(int l, int r) {
  if (l > r) return 0;
  return blk[r].ps - blk[l - 1].ps;
}
int num(int l, int r) {
  if (l > r) return 0;
  return blk[r].pc - blk[l - 1].pc;
}
range prev(int b, int i) {
  struct range ans;
  if (i > 1) {
    ans.l = b;
    ans.i = i - 1;
  } else {
    ans.l = b - 1;
    ans.i = blk[b - 1].c;
  }
  return ans;
}
int gcd(int x, int y) {
  if (x % y == 0) return y;
  return gcd(y, x % y);
}
bool cmpb(const node &x, const node &y) { return x.b < y.b; }
long long calc(long long A, long long B, long long C, long long D) {
  long long part1 = (A + 1) * (B / D);
  B = B % D;
  long long part2 = (C / D) * A * (A + 1) / 2;
  C = C % D;
  long long ymax = (B + C * A) / D;
  if (ymax == 0) return part1 + part2;
  return part1 + part2 + calc(ymax - 1, B + (A + 1) * C - ymax * D, D, C);
}
long long seg(int b, int c, long long has_sum, int has, int nextb) {
  long long res = MID - has_sum;
  long long part1 = (long long)has * c + (long long)c * (c + 1) / 2;
  if (nextb > m) return part1;
  return part1 + calc((long long)c - 1, MID - has_sum - (long long)blk[b].b * c,
                      (long long)blk[b].b, (long long)blk[nextb].b);
}
long long work(range p1, range p2, long long mid_ans) {
  long long ans = 0;
  if (p1.l > p2.l || (p1.l == p2.l && p1.i > p2.i)) return 0;
  for (int i = p1.l + 1; i < p2.l; i++)
    if (i <= p1.r)
      ans += seg(i, blk[i].c, sum(i + 1, p1.r), num(i + 1, p1.r), p1.r + 1);
    else
      ans += (long long)blk[i].c * (mid_ans / blk[i].b);
  if (p2.l == p1.l)
    ans +=
        seg(p1.l, p2.i - p1.i + 1,
            sum(p1.l + 1, p1.r) + (long long)blk[p1.l].b * (blk[p1.l].c - p2.i),
            num(p1.l + 1, p1.r) + blk[p1.l].c - p2.i, p1.r + 1);
  else {
    ans += seg(p1.l, blk[p1.l].c - p1.i + 1, sum(p1.l + 1, p1.r),
               num(p1.l + 1, p1.r), p1.r + 1);
    if (p1.r < p2.l)
      ans += (long long)p2.i * (mid_ans / blk[p2.l].b);
    else
      ans += seg(
          p2.l, p2.i,
          sum(p2.l + 1, p1.r) + (long long)blk[p2.l].b * (blk[p2.l].c - p2.i),
          num(p2.l + 1, p1.r) + blk[p2.l].c - p2.i, p1.r + 1);
  }
  return ans;
}
long long check(long long mid_ans) {
  int bL, bR, bMID;
  int iL, iR, iMID;
  int rtot = 0;
  long long has_sum;
  memset(rg, 0, sizeof(rg));
  for (int i = m; i; i--) {
    bL = 1;
    bR = i + 1;
    while (bL < bR) {
      bMID = (bL + bR) / 2;
      if (blk[i].ps - blk[bMID - 1].ps <= mid_ans)
        bR = bMID;
      else
        bL = bMID + 1;
    }
    if (bL == 1) {
      rg[++rtot].l = 1;
      rg[rtot].i = 1;
      rg[rtot].r = i;
    } else {
      iL = 1;
      iR = blk[bL - 1].c + 1;
      has_sum = sum(bL, i);
      while (iL < iR) {
        iMID = (int)(((long long)iL + iR) / 2);
        if (has_sum + (long long)blk[bL - 1].b * (blk[bL - 1].c + 1 - iMID) <=
            mid_ans)
          iR = iMID;
        else
          iL = iMID + 1;
      }
      if (iL > blk[bL - 1].c) {
        if (bL > i)
          continue;
        else {
          rg[++rtot].l = bL;
          rg[rtot].i = 1;
          rg[rtot].r = i;
        }
      } else {
        rg[++rtot].l = bL - 1;
        rg[rtot].i = iL;
        rg[rtot].r = i;
      }
    }
  }
  int lastb = m + 1;
  int lasti = 1;
  long long ans = 0;
  for (int i = 1; i <= rtot; i++) {
    ans += work(rg[i], prev(lastb, lasti), mid_ans);
    lastb = rg[i].l;
    lasti = rg[i].i;
  }
  struct range pre = prev(lastb, lasti);
  for (int i = 1; i < pre.l; i++)
    ans += (long long)blk[i].c * (mid_ans / blk[i].b);
  if (pre.l >= 1) ans += (long long)pre.i * (mid_ans / blk[pre.l].b);
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    g[i][1] = a[i];
    h[i][1] = 1;
    h[i][0] = 1;
    for (int j = 1; j <= h[i - 1][0]; j++)
      if (gcd(a[i], g[i - 1][j]) == g[i][h[i][0]])
        h[i][h[i][0]] += h[i - 1][j];
      else {
        h[i][0]++;
        h[i][h[i][0]] = h[i - 1][j];
        g[i][h[i][0]] = gcd(a[i], g[i - 1][j]);
      }
    for (int j = 1; j <= h[i][0]; j++) cnt[g[i][j]] += h[i][j];
  }
  m = 0;
  memset(blk, 0, sizeof(blk));
  for (int i = 1; i < 100005; i++)
    if (cnt[i] > 0)
      blk[++m].b = i, blk[m].c = cnt[i], blk[m].sum = (long long)i * cnt[i];
  sort(blk + 1, blk + 1 + m, cmpb);
  for (int i = 1; i <= m; i++) {
    blk[i].ps = blk[i - 1].ps + blk[i].sum;
    blk[i].pc = blk[i - 1].pc + blk[i].c;
  }
  L = 1;
  R = blk[m].ps;
  lenb = (long long)n * (n + 1) / 2;
  lenc = lenb * (lenb + 1) / 2;
  while (L < R) {
    MID = (L + R) / 2;
    if (check(MID) < lenc / 2)
      L = MID + 1;
    else
      R = MID;
  }
  printf("%I64d", L);
  return 0;
}
