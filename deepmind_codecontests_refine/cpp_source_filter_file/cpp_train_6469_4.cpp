#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const long long INF = 1e18 + 7;
long long a[maxn], b[maxn], t[maxn], s[maxn], k[maxn];
struct Tree {
  long long sum, change;
};
Tree tree[maxn];
void push_up(int o, int l, int r) {
  tree[o].sum = tree[(o << 1)].sum + tree[(o << 1 | 1)].sum;
}
void push_down(int o, int l, int r) {
  int m = (l + r) >> 1;
  if (tree[o].change != INF) {
    tree[(o << 1)].change = tree[o].change;
    tree[(o << 1 | 1)].change = tree[o].change;
    tree[(o << 1)].sum = 1ll * (m - l + 1) * tree[o].change;
    tree[(o << 1 | 1)].sum = 1ll * (r - m) * tree[o].change;
    tree[o].change = INF;
  }
}
void build(int o, int l, int r) {
  tree[o].change = INF;
  if (l == r) {
    tree[o].sum = b[l];
    return;
  }
  int m = (l + r) >> 1;
  build((o << 1), l, m);
  build((o << 1 | 1), m + 1, r);
  push_up(o, l, r);
}
void Update(int o, int l, int r, int L, int R, long long x) {
  if (L <= l && R >= r) {
    tree[o].change = x;
    tree[o].sum = 1ll * (r - l + 1) * x;
    return;
  }
  push_down(o, l, r);
  int m = (l + r) >> 1;
  if (L <= m) Update((o << 1), l, m, L, R, x);
  if (R > m) Update((o << 1 | 1), m + 1, r, L, R, x);
  push_up(o, l, r);
}
long long Query(int o, int l, int r, int L, int R) {
  if (L <= l && R >= r) {
    return tree[o].sum;
  }
  push_down(o, l, r);
  long long ans = 0;
  int m = (l + r) >> 1;
  if (L <= m) ans += Query((o << 1), l, m, L, R);
  if (R > m) ans += Query((o << 1 | 1), m + 1, r, L, R);
  return ans;
}
int main(void) {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
  for (int i = 1; i < n; ++i) scanf("%lld", &k[i]);
  for (int i = 1; i <= n; ++i)
    t[i] = t[i - 1] + k[i - 1], s[i] = s[i - 1] + t[i], b[i] = a[i] - t[i];
  int N = n;
  build(1, 1, N);
  int Q;
  cin >> Q;
  while (Q--) {
    char ar[10];
    long long x, y;
    scanf("%s %lld %lld", ar, &x, &y);
    if (ar[0] == '+') {
      long long now = Query(1, 1, N, x, x);
      now += y;
      int l = x, r = N;
      while (r >= l) {
        int mid = (r + l) >> 1;
        if (Query(1, 1, N, mid, mid) < now)
          l = mid + 1;
        else
          r = mid - 1;
      }
      Update(1, 1, N, x, r, now);
    } else {
      printf("%lld\n", Query(1, 1, N, x, y) + s[y] - s[x - 1]);
    }
  }
  return 0;
}
