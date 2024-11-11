#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
template <typename T>
void read(T &x) {
  char c = getchar();
  int f = 0;
  while (c < '0' || c > '9') f |= (c == '0'), c = getchar();
  for (x = 0; c >= '0' && c <= '9'; c = getchar())
    x = (x << 3) + (x << 1) + (c ^ '0');
  if (f) x = -x;
}
int n, m;
int a[N], b[N], bl[N], br[N];
int mx[N], tag[N];
set<int> Set;
void pushdown(int x) {
  mx[x << 1] += tag[x];
  tag[x << 1] += tag[x];
  mx[x << 1 | 1] += tag[x];
  tag[x << 1 | 1] += tag[x];
  tag[x] = 0;
}
void update(int x, int l, int r, int ql, int qr, int v) {
  if (ql > qr) return;
  if (ql <= l && r <= qr) {
    mx[x] += v;
    tag[x] += v;
    return;
  }
  pushdown(x);
  int mid = (l + r) >> 1;
  if (mid >= ql) {
    update(x << 1, l, mid, ql, qr, v);
  }
  if (mid < qr) {
    update(x << 1 | 1, mid + 1, r, ql, qr, v);
  }
  mx[x] = max(mx[x << 1], mx[x << 1 | 1]);
}
int query(int x, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) {
    return mx[x];
  }
  pushdown(x);
  int mid = (l + r) >> 1, ans = 0;
  if (mid >= ql) {
    ans = max(ans, query(x << 1, l, mid, ql, qr));
  }
  if (mid < qr) {
    ans = max(ans, query(x << 1 | 1, mid + 1, r, ql, qr));
  }
  return ans;
}
bool cmp(int x, int y) { return a[x] > a[y]; }
int main() {
  read(n);
  for (int i = 1; i <= n; ++i) {
    read(a[i]);
    a[i] = n - i + 1;
  }
  for (int i = 1; i <= n; ++i) a[i + n] = a[i];
  for (int i = 1; i <= n; ++i) b[i] = i;
  sort(b + 1, b + n + 1, cmp);
  Set.insert(0);
  Set.insert(2 * n + 1);
  set<int>::iterator it;
  for (int i = 1; i <= n; ++i) {
    it = Set.lower_bound(b[i]);
    br[b[i]] = *it;
    bl[b[i]] = *(--it);
    it = Set.lower_bound(b[i] + n);
    br[b[i] + n] = *it;
    bl[b[i] + n] = *(--it);
    Set.insert(b[i]);
    Set.insert(b[i] + n);
  }
  for (int i = 1; i <= n; ++i) {
    update(1, 1, n * 2, bl[i] + 1, i - 1, 1);
    update(1, 1, n * 2, i + 1, br[i] - 1, 1);
  }
  int ans = query(1, 1, n * 2, 1, n), del = 0;
  for (int i = n + 1; i <= n * 2; ++i) {
    update(1, 1, n * 2, bl[i - n] + 1, i - n - 1, -1);
    update(1, 1, n * 2, i - n + 1, br[i - n] - 1, -1);
    update(1, 1, n * 2, bl[i] + 1, i - 1, 1);
    update(1, 1, n * 2, i + 1, br[i] - 1, 1);
    int t = query(1, 1, n * 2, i - n, i);
    if (t < ans) {
      ans = t;
      del = i - n;
    }
  }
  cout << ans + 1 << ' ' << del << endl;
  return 0;
}
