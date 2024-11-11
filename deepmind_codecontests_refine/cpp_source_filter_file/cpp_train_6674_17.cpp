#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, a[N << 1], pre[N << 1], suf[N << 1], nxt[N << 1], vis[N << 1], tot = 1,
                                                                      m;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return x * f;
}
void fail() {
  printf("no");
  exit(0);
}
inline void del(int l, int r) {
  suf[pre[l]] = suf[r];
  pre[suf[r]] = pre[l];
}
inline int chose() {
  while (vis[tot]) tot++;
  vis[tot] = -1;
  return tot;
}
void solve(int l, int r) {
  if ((r - l) & 1) fail();
  for (register int i = l; i <= r; i = suf[i]) {
    while (nxt[i]) {
      if (nxt[i] > r) fail();
      solve(suf[i], pre[nxt[i]]);
      del(suf[i], nxt[i]);
      nxt[i] = nxt[nxt[i]];
    }
  }
  int s = 0, cnt = 0, rt = a[pre[l]];
  for (register int i = l; i <= r; i = suf[i]) {
    if (a[i]) cnt++;
    s++;
  }
  s = (s + 1) >> 1;
  if (cnt > s) fail();
  for (register int i = suf[l]; i < r; i = suf[i])
    if (!a[i] && cnt < s) a[i] = chose(), cnt++;
  if (s == 1 && cnt == 0) a[l] = chose();
  for (register int i = l; suf[i] <= r; i = suf[i]) {
    while (i > l && suf[i] <= r && !a[pre[i]] && a[i] && a[suf[i]])
      a[pre[i]] = a[suf[i]], del(i, suf[i]), i = pre[pre[i]];
    while (i >= l && suf[suf[i]] <= r && a[i] && a[suf[i]] && !a[suf[suf[i]]])
      a[suf[suf[i]]] = a[i], del(suf[i], suf[suf[i]]), i = pre[i];
  }
  for (register int i = l; i <= r; i = suf[i])
    if (!a[i]) a[i] = rt;
}
int main() {
  n = read();
  m = n * 2 - 1;
  for (register int i = 1; i <= m; ++i) a[i] = read();
  for (register int i = 0; i <= m; ++i) pre[i] = i - 1, suf[i] = i + 1;
  if (a[1] && a[m] && a[1] != a[m]) fail();
  a[1] = a[m] = a[1] | a[m];
  for (register int i = m; i; --i)
    if (a[i]) nxt[i] = vis[a[i]], vis[a[i]] = i;
  solve(1, m);
  printf("yes\n");
  for (register int i = 1; i <= m; ++i) printf("%d ", a[i]);
  return 0;
}
