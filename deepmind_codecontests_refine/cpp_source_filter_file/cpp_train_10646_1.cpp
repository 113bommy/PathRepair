#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
const int N = (1 << 18) + 100;
using namespace std;
int tree[N * 4];
int a[N];
int deep[20];
int n;
int cnt = 0;
void build(int l, int r, int now) {
  if (l == r) {
    tree[now] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, now << 1);
  build(mid + 1, r, now << 1 | 1);
  tree[now] = tree[now << 1] + tree[now << 1 | 1];
}
void change(int l, int r, int now, int x, int m, int dep) {
  if (l == r) {
    tree[now] = m;
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid) {
    change(l, mid, (now << 1) + (deep[dep] == 1), x, m, dep - 1);
  } else
    change(mid + 1, r, (now << 1 | 1) - (deep[dep] == 1), x, m, dep - 1);
  tree[now] = tree[now << 1] + tree[now << 1 | 1];
}
long long query(int l, int r, int L, int R, int now, int dep) {
  if (l >= L && r <= R) {
    return tree[now];
  }
  long long ans = 0;
  int mid = (l + r) >> 1;
  if (mid >= L)
    ans += query(l, mid, L, R, (now << 1) + (deep[dep] == 1), dep - 1);
  if (mid < R)
    ans += query(mid + 1, r, L, R, (now << 1 | 1) - (deep[dep] == 1), dep - 1);
  return ans;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int q, x, m, l, r, b;
  cin >> n >> q;
  for (int i = 1; i <= (1 << n); i++) {
    cin >> a[i];
  }
  build(1, (1 << n), 1);
  for (int i = 1; i <= q; i++) {
    cin >> b;
    if (b == 1) {
      cin >> x >> m;
      change(1, (1 << n), 1, x, m, 0);
    } else if (b == 2) {
      cin >> m;
      for (int i = 0; i <= m; i++) {
        deep[i] ^= 1;
      }
    } else if (b == 3) {
      cin >> m;
      deep[m + 1] ^= 1;
    } else {
      cin >> l >> r;
      cout << query(1, (1 << n), l, r, 1, n) << endl;
    }
  }
  return 0;
}
