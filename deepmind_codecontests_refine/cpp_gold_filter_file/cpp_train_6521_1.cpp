#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
long long arr[N], d[N], tree[N << 2], mx[N << 2];
void build(int rt, int l, int r) {
  if (l == r) {
    tree[rt] = mx[rt] = arr[l];
    return;
  }
  int m = (l + r) / 2;
  build(rt << 1, l, m);
  build(rt << 1 | 1, m + 1, r);
  tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
  mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]);
}
void update(int L, int R, int rt, int l, int r) {
  if (mx[rt] <= 2) return;
  if (l == r) {
    tree[rt] = mx[rt] = d[tree[rt]];
    return;
  }
  int m = (l + r) >> 1;
  if (L <= m) update(L, R, rt << 1, l, m);
  if (R > m) update(L, R, rt << 1 | 1, m + 1, r);
  tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
  mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]);
}
long long query(int L, int R, int rt, int l, int r) {
  if (L <= l && r <= R) {
    return tree[rt];
  }
  int m = (l + r) >> 1;
  long long ans = 0;
  if (L <= m) ans += query(L, R, rt << 1, l, m);
  if (R > m) ans += query(L, R, rt << 1 | 1, m + 1, r);
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  int n, m, t, l, r;
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j += i) d[j]++;
  }
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  build(1, 1, n);
  while (m--) {
    cin >> t >> l >> r;
    if (t == 1)
      update(l, r, 1, 1, n);
    else
      cout << query(l, r, 1, 1, n) << endl;
  }
}
