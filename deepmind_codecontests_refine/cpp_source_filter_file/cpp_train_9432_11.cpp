#include <bits/stdc++.h>
using namespace std;
int n, num = 1, cnt = 0, root, h[200010], lop[200010], vis[200010], pth[200010],
       flag[200010 << 1], inl[200010];
long long sum[200010], f[200010], d[200010], pre[200010], gl1[200010],
    gl2[200010], hl1[200010], hl2[200010], gr1[200010], gr2[200010],
    hr1[200010], hr2[200010];
struct node {
  int to, z, next;
} mp[200010 << 1];
inline char gc() {
  static char buf[1 << 16], *S, *T;
  if (S == T) {
    T = (S = buf) + fread(buf, 1, 1 << 16, stdin);
    if (T == S) return EOF;
  }
  return *S++;
}
inline int read() {
  int x = 0, f = 1;
  char ch = gc();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = gc();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = gc();
  return x * f;
}
inline void ins(int x, int y, int z) {
  mp[++num].to = y;
  mp[num].z = z;
  mp[num].next = h[x];
  h[x] = num;
  mp[++num].to = x;
  mp[num].z = z;
  mp[num].next = h[y];
  h[y] = num;
}
inline int dfs(int x, int e) {
  if (vis[x]) {
    root = x;
    return 1;
  }
  vis[x] = 1;
  int tmp;
  for (int i = h[x]; i; i = mp[i].next) {
    int y = mp[i].to;
    if (i == (e ^ 1)) continue;
    tmp = dfs(y, i);
    if (tmp) {
      if (tmp == 1) {
        lop[++cnt] = x;
        pth[cnt] = i;
        pre[cnt] = mp[i].z;
        inl[x] = 1;
        if (x != root) return 1;
      }
      return 2;
    }
  }
  return 0;
}
inline void dfsdp(int x, int fa) {
  for (int i = h[x]; i; i = mp[i].next) {
    int y = mp[i].to;
    if (y == fa || inl[y]) continue;
    dfsdp(y, x);
    d[x] = max(d[x], max(d[y], f[x] + f[y] + mp[i].z));
    f[x] = max(f[x], f[y] + mp[i].z);
  }
}
inline long long gg(int x) {
  return x ? f[lop[x]] - sum[x] : -0x3f3f3f3f3f3f3f3f;
}
inline long long hh(int x) {
  return x ? f[lop[x]] + sum[x] : -0x3f3f3f3f3f3f3f3f;
}
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) {
    int x = read(), y = read(), z = read();
    ins(x, y, z);
  }
  dfs(1, 0);
  memset(d, 0, sizeof(d));
  long long mx = 0;
  for (int i = 1; i <= cnt; ++i) {
    dfsdp(lop[i], 0);
    mx = max(mx, d[lop[i]]);
  }
  lop[0] = lop[cnt];
  for (int i = 1; i <= cnt; ++i) sum[i] = sum[i - 1] + pre[i];
  for (int i = 1; i <= cnt; ++i) {
    gl1[i] = gl1[i - 1], gl2[i] = gl2[i - 1];
    if (gg(gl1[i]) < gg(i))
      gl2[i] = gl1[i], gl1[i] = i;
    else if (gg(gl2[i]) < gg(i))
      gl2[i] = i;
    hl1[i] = hl1[i - 1], hl2[i] = hl2[i - 1];
    if (hh(hl1[i]) < hh(i))
      hl2[i] = hl1[i], hl1[i] = i;
    else if (hh(hl2[i]) < hh(i))
      hl2[i] = i;
  }
  for (int i = cnt; i; --i) {
    gr1[i] = gr1[i + 1], gr2[i] = gr2[i + 1];
    if (gg(gr1[i]) < gg(i))
      gr2[i] = gr1[i], gr1[i] = i;
    else if (gg(gr2[i]) < gg(i))
      gr2[i] = i;
    hr1[i] = hr1[i + 1], hr2[i] = hr2[i + 1];
    if (hh(hr1[i]) < hh(i))
      hr2[i] = hr1[i], hr1[i] = i;
    else if (hh(hr2[i]) < hh(i))
      hr2[i] = i;
  }
  long long ans;
  if (hl1[cnt] != gl1[cnt])
    ans = gg(gl1[cnt]) + hh(hl1[cnt]);
  else
    ans = max(gg(gl1[cnt]) + hh(hl2[cnt]), gg(gl1[cnt]) + hh(hl2[cnt]));
  for (int i = 1; i < cnt; ++i) {
    long long now = mx;
    now = max(now, sum[cnt] + hh(hl1[i]) + gg(gr1[i + 1]));
    if (gl1[i] != hl1[i])
      now = max(now, gg(gl1[i]) + hh(hl1[i]));
    else
      now = max(now, max(gg(gl1[i]) + hh(hl2[i]), gg(gl2[i]) + hh(hl1[i])));
    if (gr1[i + 1] != hr1[i + 1])
      now = max(now, gg(gr1[i + 1]) + hh(hr1[i + 1]));
    else
      now = max(now, max(gg(gr1[i + 1]) + hh(hr2[i + 1]),
                         gg(gr2[i + 1]) + hh(hr1[i + 1])));
    ans = min(ans, now);
  }
  printf("%I64d\n", max(mx, ans));
  return 0;
}
