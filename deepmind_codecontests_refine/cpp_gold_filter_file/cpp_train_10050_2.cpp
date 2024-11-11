#include <bits/stdc++.h>
using namespace std;
template <typename tn>
void read(tn &a) {
  tn x = 0, f = 1;
  char c = ' ';
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  a = x * f;
}
const int N = 101000;
int st[N], top, n, w[N], g[N], nxt[N];
long long pre[N], suf[N], K, ans;
vector<int> e[N];
struct segment_tree {
  long long ms[N * 4], mp[N * 4], h[N * 4], tag[N * 4];
  void add(int x, long long k) {
    ms[x] += k;
    tag[x] += k;
    h[x] += k;
  }
  void pushdown(int x) {
    if (!tag[x]) return;
    add(x << 1, tag[x]);
    add(x << 1 | 1, tag[x]);
    tag[x] = 0;
  }
  long long calc(int x, int l, int r, long long k) {
    if (l == r) return k + mp[x];
    pushdown(x);
    int mid = l + r >> 1;
    if (k <= ms[x << 1])
      return min(h[x], calc(x << 1, l, mid, k));
    else
      return min(k + mp[x], calc(x << 1 | 1, mid + 1, r, k));
  }
  void pushup(int x, int l, int r) {
    ms[x] = max(ms[x << 1], ms[x << 1 | 1]);
    int mid = l + r >> 1;
    h[x] = calc(x << 1 | 1, mid + 1, r, ms[x << 1]);
  }
  void build(int x = 1, int l = 1, int r = n) {
    if (l == r) {
      mp[x] = -suf[l];
      ms[x] = suf[l];
      return;
    }
    int mid = l + r >> 1;
    build(x << 1, l, mid);
    build(x << 1 | 1, mid + 1, r);
    mp[x] = min(mp[x << 1], mp[x << 1 | 1]);
    pushup(x, l, r);
  }
  void modify(int ql, int qr, long long k, int x = 1, int l = 1, int r = n) {
    if (ql <= l && qr >= r) {
      add(x, k);
      return;
    }
    int mid = l + r >> 1;
    pushdown(x);
    if (ql <= mid) modify(ql, qr, k, x << 1, l, mid);
    if (qr > mid) modify(ql, qr, k, x << 1 | 1, mid + 1, r);
    pushup(x, l, r);
  }
  long long query(long long k = -1e17, int x = 1, int l = 1, int r = n) {
    if (l == r) return k + mp[x] <= K ? l : 0;
    int mid = l + r >> 1;
    pushdown(x);
    long long tmp = k <= ms[x << 1] ? h[x] : calc(x << 1 | 1, mid + 1, r, k);
    if (tmp <= K) return query(max(ms[x << 1], k), x << 1 | 1, mid + 1, r);
    return query(k, x << 1, l, mid);
  }
} t;
void dfs(int x, int dad) {
  st[++top] = x;
  if (dad) {
    t.modify(dad - 1, n, -pre[dad - 1] + pre[x - 1]);
    int l = 1, r = top + 1;
    while (l + 1 < r) {
      int mid = l + r >> 1;
      if (pre[x - 1] - pre[st[mid] - 1] <= K)
        r = mid;
      else
        l = mid;
    }
    if (x > 1) t.modify(1, x - 1, -1e17);
    if (st[l] <= n) t.modify(st[l], n, 1e17);
    ans = max(ans, t.query() - x + 1);
    if (x > 1) t.modify(1, x - 1, 1e17);
    if (st[l] <= n) t.modify(st[l], n, -1e17);
  }
  for (int v : e[x])
    if (v != dad) dfs(v, x);
  if (dad) t.modify(dad - 1, n, -pre[x - 1] + pre[dad - 1]);
  top--;
}
int main() {
  read(n);
  read(K);
  for (int i = 1; i < n; i++) read(w[i]);
  for (int i = 1; i <= n; i++) read(g[i]);
  for (int i = 1; i <= n; i++)
    pre[i] = pre[i - 1] - w[i] + g[i], suf[i] = suf[i - 1] - w[i - 1] + g[i];
  t.build();
  for (int i = n; i; i--) {
    nxt[i] = i;
    while (nxt[i] < n && pre[nxt[i]] - pre[i - 1] >= 0)
      nxt[i] = nxt[nxt[i] + 1];
    e[nxt[i] + 1].push_back(i);
  }
  dfs(n + 1, 0);
  cout << ans << '\n';
  return 0;
}
