#include <bits/stdc++.h>
using namespace std;
const int N = (int)2e5 + 5;
const int M = 1 << 18;
const int K = 5;
const int L = 1 << K;
const int INF = (int)1e9;
int n, k;
int tree[L][2 * M];
int get(int v, int tl, int tr, int mask, int l, int r) {
  if (tr <= l || r <= tl) return -INF;
  if (l <= tl && tr <= r) return tree[mask][v];
  int tm = (tl + tr) / 2;
  int ansL = get(2 * v, tl, tm, mask, l, r);
  int ansR = get(2 * v + 1, tm, tr, mask, l, r);
  return max(ansL, ansR);
}
int get(int l, int r, int mask) {
  int res = get(1, 0, M, mask, l, r);
  return res;
}
void update(int v, int tl, int tr, int pos, int mask, int new_val) {
  if (pos < tl || tr <= pos) return;
  if (tl + 1 == tr) {
    tree[mask][v] = new_val;
    return;
  }
  int tm = (tl + tr) / 2;
  update(2 * v, tl, tm, pos, mask, new_val);
  update(2 * v + 1, tm, tr, pos, mask, new_val);
  tree[mask][v] = max(tree[mask][2 * v], tree[mask][2 * v + 1]);
}
int a[K];
void upd(int pos) {
  for (int i = 0; i < k; ++i) scanf("%d", a + i);
  for (int mask = 0; mask < (1 << k); ++mask) {
    int val = 0;
    for (int i = 0; i < k; ++i) {
      if ((mask >> i) & 1)
        val += a[i];
      else
        val -= a[i];
    }
    update(1, 0, M, pos, mask, val);
  }
}
int main() {
  scanf("%d %d", &n, &k);
  for (int mask = 0; mask < (1 << k); ++mask) {
    for (int i = 1; i < 2 * M; ++i) tree[mask][i] = -INF;
  }
  for (int i = 0; i < n; ++i) upd(i);
  int q;
  scanf("%d", &q);
  while (q--) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int pos;
      scanf("%d", &pos);
      --pos;
      upd(pos);
    } else {
      int l, r;
      scanf("%d %d", &l, &r);
      --l;
      --r;
      int ans = 0;
      for (int mask = 0; mask < (1 << k); mask += 2) {
        ans = max(ans,
                  get(l, r + 1, mask) + get(l, r + 1, mask ^ ((1 << k) - 1)));
      }
      printf("%d\n", ans);
    }
  }
}
