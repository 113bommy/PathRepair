#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
void chkmin(T1 &x, T2 y) {
  if (x > y) x = y;
}
template <typename T1, typename T2>
void chkmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
namespace fastio {
char rbuf[1 << 23], *p1 = rbuf, *p2 = rbuf, wbuf[1 << 23], *p3 = wbuf;
inline char getc() {
  return p1 == p2 &&
                 (p2 = (p1 = rbuf) + fread(rbuf, 1, 1 << 23, stdin), p1 == p2)
             ? -1
             : *p1++;
}
inline void putc(char x) { (*p3++ = x); }
template <typename T>
void read(T &x) {
  x = 0;
  char c = getchar();
  T neg = 0;
  while (!isdigit(c)) neg |= !(c ^ '-'), c = getchar();
  while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  if (neg) x = (~x) + 1;
}
template <typename T>
void recursive_print(T x) {
  if (!x) return;
  recursive_print(x / 10);
  putc(x % 10 ^ 48);
}
template <typename T>
void print(T x) {
  if (!x) putc('0');
  if (x < 0) putc('-'), x = ~x + 1;
  recursive_print(x);
}
void print_final() { fwrite(wbuf, 1, p3 - wbuf, stdout); }
}  // namespace fastio
const int MAXN = 1e5;
const int SQRT = 316;
int n, m, hd[MAXN + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], ec = 0;
void adde(int u, int v) {
  to[++ec] = v;
  nxt[ec] = hd[u];
  hd[u] = ec;
}
vector<int> qv[MAXN + 5];
int bgt[MAXN + 5], edt[MAXN + 5], tim = 0;
int blk, blk_cnt, L[SQRT + 5], R[SQRT + 5], bel[MAXN + 5];
int val[MAXN + 5], cnt[SQRT + 5][MAXN + 5], tag[SQRT + 5];
void dfs0(int x = 1, int f = 0) {
  bgt[x] = ++tim;
  for (int e = hd[x]; e; e = nxt[e]) {
    int y = to[e];
    if (y == f) continue;
    dfs0(y, x);
  }
  edt[x] = tim;
}
void add(int l, int r, int v) {
  if (bel[l] == bel[r]) {
    for (int i = l; i <= r; i++) cnt[bel[l]][val[i]]--;
    for (int i = l; i <= r; i++) val[i] += v;
    for (int i = l; i <= r; i++) cnt[bel[l]][val[i]]++;
  } else {
    for (int i = l; i <= R[bel[l]]; i++) cnt[bel[l]][val[i]]--;
    for (int i = l; i <= R[bel[l]]; i++) val[i] += v;
    for (int i = l; i <= R[bel[l]]; i++) cnt[bel[l]][val[i]]++;
    for (int i = L[bel[r]]; i <= r; i++) cnt[bel[r]][val[i]]--;
    for (int i = L[bel[r]]; i <= r; i++) val[i] += v;
    for (int i = L[bel[r]]; i <= r; i++) cnt[bel[r]][val[i]]++;
    for (int i = bel[l] + 1; i <= bel[r] - 1; i++) tag[i] += v;
  }
}
int query() {
  int ret = 0;
  for (int i = 1; i <= blk_cnt; i++) ret += cnt[i][-tag[i]];
  return n - ret;
}
int ans[MAXN + 5];
void calc(int x = 1, int f = 0) {
  for (int i = 0; i < qv[x].size(); i++) {
    int y = qv[x][i];
    add(bgt[x], edt[x], 1);
    add(bgt[y], edt[y], 1);
  }
  ans[x] = query();
  if (ans[x]) ans[x]--;
  for (int e = hd[x]; e; e = nxt[e]) {
    int y = to[e];
    if (y == f) continue;
    calc(y, x);
  }
  for (int i = 0; i < qv[x].size(); i++) {
    int y = qv[x][i];
    add(bgt[x], edt[x], -1);
    add(bgt[y], edt[y], -1);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1, u, v; i < n; i++)
    scanf("%d%d", &u, &v), adde(u, v), adde(v, u);
  for (int i = 1, u, v; i <= m; i++)
    scanf("%d%d", &u, &v), qv[u].push_back(v), qv[v].push_back(u);
  blk = (int)pow(n, 0.5);
  blk_cnt = (n - 1) / blk + 1;
  for (int i = 1; i <= blk_cnt; i++) {
    L[i] = (i - 1) * blk + 1;
    R[i] = min(i * blk, n);
    for (int j = L[i]; j <= R[i]; j++) bel[j] = i;
    cnt[i][0] = R[i] - L[i] + 1;
  }
  dfs0();
  calc();
  for (int i = 1; i <= n; i++) printf("%d%c", ans[i], (i == n) ? '\n' : ' ');
  return 0;
}
