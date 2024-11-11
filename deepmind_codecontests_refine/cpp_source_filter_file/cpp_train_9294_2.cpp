#include <bits/stdc++.h>
namespace FastIO {
bool IOerror = 0;
inline char nc() {
  static char buf[100000], *p1 = buf + 100000, *pend = buf + 100000;
  if (p1 == pend) {
    p1 = buf;
    pend = buf + fread(buf, 1, 100000, stdin);
    if (pend == p1) {
      IOerror = 1;
      return -1;
    }
  }
  return *p1++;
}
inline bool blank(char ch) {
  return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}
template <class T>
inline bool read(T& x) {
  bool sign = 0;
  char ch = nc();
  x = 0;
  for (; blank(ch); ch = nc())
    ;
  if (IOerror) return false;
  if (ch == '-') sign = 1, ch = nc();
  for (; ch >= '0' && ch <= '9'; ch = nc()) x = x * 10 + ch - '0';
  if (sign) x = -x;
  return true;
}
template <class T, class... U>
bool read(T& h, U&... t) {
  return read(h) && read(t...);
}
};  // namespace FastIO
using namespace std;
using namespace FastIO;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;
int a[N];
struct node {
  int l, r, mid, mi;
} tree[N << 2];
void pp(int x) { tree[x].mi = min(tree[x << 1].mi, tree[x << 1 | 1].mi); }
void build(int x, int l, int r) {
  tree[x] = {l, r, l + r >> 1, 0};
  if (l == r) return;
  int mid = tree[x].mid;
  build(x << 1, l, mid);
  build(x << 1 | 1, mid + 1, r);
  pp(x);
}
void modify(int x, int pos, int k) {
  if (tree[x].l == tree[x].r) {
    tree[x].mi = k;
    return;
  }
  int mid = tree[x].mid;
  if (pos <= mid)
    modify(x << 1, pos, k);
  else
    modify(x << 1 | 1, pos, k);
  pp(x);
}
int query(int x, int l, int r) {
  if (l <= tree[x].l && tree[x].r <= r) {
    return tree[x].mi;
  }
  int ans = INF;
  int mid = tree[x].mid;
  if (l <= mid) ans = min(ans, query(x << 1, l, r));
  if (r > mid) ans = min(ans, query(x << 1 | 1, l, r));
  return ans;
}
int last[N], vis[N];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  build(1, 1, n);
  for (int i = 1; i <= n; i++) {
    modify(1, a[i], i);
    if (a[i] == 1) continue;
    int pos = query(1, 1, a[i] - 1);
    if (pos > last[a[i]]) vis[a[i]] = 1;
    last[a[i]] = 1;
    vis[1] = 1;
  }
  for (int i = 2; i <= n + 1; i++) {
    int pos = query(1, 1, i - 1);
    if (pos > last[i]) vis[i] = 1;
  }
  int ans = 1;
  while (vis[ans]) ans++;
  cout << ans << endl;
  return 0;
}
