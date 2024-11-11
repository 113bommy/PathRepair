#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
const double pi = acos(-1);
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
long long a[maxn], b[maxn], dp[maxn];
struct Tree {
  long long l, r, maxval;
} tree[maxn * 4];
void push_up(long long p) {
  tree[p].maxval = max(tree[p * 2].maxval, tree[p * 2 + 1].maxval);
}
void build(long long p, long long l, long long r) {
  tree[p].maxval = 0;
  tree[p].l = l;
  tree[p].r = r;
  if (l == r) {
    return;
  }
  long long mid = (l + r) >> 1;
  build(p * 2, l, mid);
  build(p * 2 + 1, mid + 1, r);
  push_up(p);
}
void modify(long long p, long long l, long long r, long long d) {
  if (l <= tree[p].l && r >= tree[p].r) {
    tree[p].maxval = d;
    return;
  }
  long long mid = (tree[p].l + tree[p].r) >> 1;
  if (l <= mid) modify(p * 2, l, r, d);
  if (r > mid) modify(p * 2 + 1, l, r, d);
  push_up(p);
}
long long query(long long p, long long l, long long r) {
  if (l <= tree[p].l && r >= tree[p].r) {
    return tree[p].maxval;
  }
  long long mid = (tree[p].l + tree[p].r) >> 1;
  long long ans = 0;
  if (l <= mid) ans = max(ans, query(p * 2, l, r));
  if (r > mid) ans = max(ans, query(p * 2 + 1, l, r));
  return ans;
}
int main(void) {
  cin.tie(0);
  std::ios::sync_with_stdio(false);
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    long long r, h;
    cin >> r >> h;
    a[i] = r * r * h;
    b[i] = a[i];
  }
  sort(b + 1, b + 1 + n);
  build(1, 1, n);
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    long long tmp = lower_bound(b + 1, b + 1 + n, a[i]) - b;
    dp[i] = max(dp[i], query(1, 1, tmp) + a[i]);
    modify(1, 1, tmp, dp[i]);
    ans = max(ans, dp[i]);
  }
  cout << fixed << setprecision(10) << (1.0 * ans * pi) << "\n";
  return 0;
}
