#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
using namespace std;
inline long long read() {
  long long x = 0, y = 0, c = getchar();
  while (!isdigit(c)) y = c, c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ '0'), c = getchar();
  return y == '-' ? -x : x;
}
inline void print(long long q) {
  if (q < 0) putchar('-'), q = -q;
  if (q >= 10) print(q / 10);
  putchar(q % 10 + '0');
}
int n, m, k;
struct edge {
  int fr, to, val, id;
  bool fg;
} e[1000010];
int f[1000010];
inline int getf(int q) { return f[q] == q ? q : f[q] = getf(f[q]); }
inline bool operator<(edge q, edge w) {
  return q.val == w.val ? q.fg < w.fg : q.val < w.val;
}
inline bool cmp(edge q, edge w) {
  return q.val == w.val ? q.fg > w.fg : q.val < w.val;
}
int as[1000010], ft;
bool usd[1000010];
inline int work() {
  int i, as = 0, as2 = 0;
  sort(e + 1, e + m + 1);
  for (i = 1; i <= n; ++i) f[i] = i;
  for (i = 1; i <= m; ++i)
    if (getf(e[i].fr) != getf(e[i].to)) {
      f[f[e[i].fr]] = f[e[i].to];
      as += e[i].fg;
      ++as2;
    }
  return as2 != n - 1 ? -1 : as;
}
int main() {
  int i, j, l, r, mid, ans;
  n = read();
  m = read();
  k = read();
  for (i = 1; i <= m; ++i) {
    e[i].fr = read();
    e[i].to = read();
    e[i].val = read();
    e[i].id = i;
    e[i].fg = (e[i].fr == 1 || e[i].to == 1);
  }
  l = -1e6;
  r = 1e6;
  ans = l - 1;
  while (l <= r) {
    mid = l + r >> 1;
    for (i = 1; i <= m; ++i)
      if (e[i].fg) e[i].val -= mid;
    int tmp = work();
    if (tmp == -1) {
      puts("-1");
      return 0;
    }
    if (tmp <= k)
      ans = mid, l = mid + 1;
    else
      r = mid - 1;
    for (i = 1; i <= m; ++i)
      if (e[i].fg) e[i].val += mid;
  }
  if (ans == -1e6 - 1) {
    puts("-1");
    return 0;
  }
  int tp = 0;
  for (i = 1; i <= m; ++i)
    if (e[i].fg) e[i].val -= ans;
  sort(e + 1, e + m + 1);
  for (i = 1; i <= n; ++i) f[i] = i;
  for (i = 1; i <= m; ++i)
    if (getf(e[i].fr) != getf(e[i].to)) {
      f[f[e[i].fr]] = f[e[i].to];
      if (e[i].fg) usd[e[i].id] = 1, as[++ft] = e[i].id, ++tp;
    }
  if (tp > k) {
    puts("-1");
    return 0;
  }
  for (i = 1; i <= n; ++i) f[i] = i;
  for (i = 1; i <= m; ++i)
    if (usd[e[i].id]) f[getf(e[i].fr)] = getf(e[i].to);
  sort(e + 1, e + m + 1, cmp);
  for (i = 1; i <= m; ++i)
    if (!usd[e[i].id] && getf(e[i].fr) != getf(e[i].to)) {
      if (e[i].fg && tp == k) continue;
      f[f[e[i].fr]] = f[e[i].to];
      as[++ft] = e[i].id;
      tp += e[i].fg;
    }
  if (tp < k) {
    puts("-1");
    return 0;
  }
  print(ft);
  putchar('\n');
  for (i = 1; i <= ft; ++i) print(as[i]), putchar(' ');
  return 0;
}
