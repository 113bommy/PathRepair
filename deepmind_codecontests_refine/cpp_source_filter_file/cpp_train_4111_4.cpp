#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int nega = 1;
  while (!isdigit(ch)) {
    if (ch == '-') nega = -1;
    ch = getchar();
  }
  int ans = 0;
  while (isdigit(ch)) {
    ans = ans * 10 + ch - 48;
    ch = getchar();
  }
  if (nega == -1) return -ans;
  return ans;
}
inline int min(int x, int y, int z) { return min(x, min(y, z)); }
inline int max(int x, int y, int z) { return max(x, max(y, z)); }
inline int add(int x, int y) {
  return x + y >= 998244353 ? x + y - 998244353 : x + y;
}
inline int add(int x, int y, int z) { return add(add(x, y), z); }
inline int sub(int x, int y) { return x - y < 0 ? x - y + 998244353 : x - y; }
inline int mul(int x, int y) { return 1LL * x * y % 998244353; }
inline int mul(int x, int y, int z) { return mul(mul(x, y), z); }
struct Node {
  int v, tag, sum;
};
Node t[300005 * 4];
void pushdown(int u) {
  if (t[u].tag) {
    t[(u << 1)].tag += t[u].tag;
    t[(u << 1)].v += t[u].tag;
    t[(u << 1 | 1)].tag += t[u].tag;
    t[(u << 1 | 1)].v += t[u].tag;
    t[u].tag = 0;
  }
}
void pushup(int u) {
  t[u].v = min(t[(u << 1)].v, t[(u << 1 | 1)].v);
  t[u].sum = (t[u].v == t[(u << 1)].v ? t[(u << 1)].sum : 0) +
             (t[u].v == t[(u << 1 | 1)].v ? t[(u << 1 | 1)].sum : 0);
}
void build(int u, int l, int r) {
  if (l == r) {
    t[u].sum = 1;
    return;
  }
  int mid = (l + r) / 2;
  build((u << 1), l, mid), build((u << 1 | 1), mid + 1, r);
  pushup(u);
}
void update(int u, int l, int r, int L, int R, int d) {
  if (L > R) return;
  if (L <= l && r <= R) {
    t[u].tag += d;
    t[u].v += d;
    return;
  }
  pushdown(u);
  int mid = (l + r) / 2;
  if (L <= mid) update((u << 1), l, mid, L, R, d);
  if (R > mid) update((u << 1 | 1), mid + 1, r, L, R, d);
  pushup(u);
}
int a[300005];
int s1[300005], tp1, s2[300005], tp2;
signed main() {
  int n = read();
  for (int i = 1; i <= n; i++) {
    int u = read(), v = read();
    a[u] = v;
  }
  build(1, 1, n);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    while (tp1 && a[i] > a[s1[tp1]]) {
      update(1, 1, n, s1[tp1 - 1] + 1, s1[tp1], -a[s1[tp1]]);
      tp1--;
    }
    while (tp2 && a[i] < a[s2[tp2]]) {
      update(1, 1, n, s2[tp2 - 1] + 1, s2[tp2], a[s2[tp2]]);
      tp2--;
    }
    update(1, 1, n, s1[tp1] + 1, i, a[i]);
    update(1, 1, n, s2[tp2] + 1, i, -a[i]);
    update(1, 1, n, 1, i - 1, -1);
    s1[++tp1] = i;
    s2[++tp2] = i;
    ans += t[1].sum - (n - i);
  }
  cout << ans << endl;
  return 0;
}
