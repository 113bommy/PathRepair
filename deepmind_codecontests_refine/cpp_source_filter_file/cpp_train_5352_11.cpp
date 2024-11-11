#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int maxn = 100005;
inline int read() {
  int res, ok = 1;
  char ch;
  for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') ok = -1;
  res = ch - '0';
  for (ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar())
    res = res * 10 + ch - '0';
  return res * ok;
}
struct node {
  int l, r, id;
  bool operator<(const node& b) const { return r < b.r; }
} ask[maxn];
int n, m, x[maxn], pre[maxn], pd[maxn], a[maxn], l[maxn], b[maxn], ans[maxn],
    num[maxn];
inline void solve(int k) {
  int len = 0, now = 1, r = 1;
  for (int i = k; i; i = pre[i]) {
    len++;
    a[len] = i;
    pd[i] = 1;
  }
  a[len + 1] = 0;
  while (now <= len) {
    if (now == len) {
      l[a[now]] = 1;
      return;
    }
    if (r <= now) {
      r++;
      int k1 = a[r] - a[now];
      while (r < len && a[r + 1] - a[r] == k1) r++;
    }
    l[a[now]] = a[r + 1] + 1;
    now++;
  }
}
inline void add(int x, int y) {
  while (x <= n) {
    b[x] += y;
    x += x & (-x);
  }
}
inline int find(int x) {
  int now = 0;
  while (x) {
    now += b[x];
    x -= x & (-x);
  }
  return now;
}
inline void updata(int k, int l, int r, int x, int y) {
  if (l == r) {
    num[k] = y;
    return;
  }
  int mid = (l + r) >> 1;
  if (mid >= x)
    updata(k << 1, l, mid, x, y);
  else
    updata(k << 1 | 1, mid + 1, r, x, y);
  num[k] = min(num[k << 1], num[k << 1 | 1]);
}
inline int work(int k, int l, int r, int x, int y) {
  if (l > y || r < x) return 1 << 30;
  if (l >= x && r <= y) return num[k];
  int mid = (l + r) >> 1;
  return min(work(k << 1, l, mid, x, y), work(k << 1 | 1, mid + 1, r, x, y));
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) x[i] = read();
  m = read();
  for (int i = 1; i <= m; i++) {
    ask[i].l = read();
    ask[i].r = read();
    ask[i].id = i;
  }
  sort(ask + 1, ask + 1 + m);
  for (int i = 1; i <= n; i++) {
    pre[i] = a[x[i]];
    a[x[i]] = i;
  }
  for (int i = n; i >= 1; i--)
    if (pd[i] == 0) solve(i);
  int now = 1;
  memset(a, 0, sizeof(a));
  memset(num, 63, sizeof(num));
  for (int i = 1; i <= n; i++) {
    if (a[x[i]]) {
      add(a[x[i]], -1);
      updata(1, 1, n, a[x[i]], n + 1);
    }
    add(i, 1);
    a[x[i]] = i;
    updata(1, 1, n, i, l[i]);
    while (now <= m && ask[now].r == i) {
      ans[ask[now].id] = find(i) - find(ask[now].l - 1) -
                         (work(1, 1, n, ask[now].l, i) <= ask[now].l) + 1;
      now++;
    }
  }
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
  return 0;
}
