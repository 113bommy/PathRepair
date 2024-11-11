#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5, INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int ST[maxn << 2], lazy[maxn << 2];
int n, m, q, a[maxn], b[maxn];
void Push_down(int rt) {
  if (lazy[rt]) {
    lazy[(rt << 1)] += lazy[rt];
    lazy[((rt << 1) | 1)] += lazy[rt];
    ST[(rt << 1)] += lazy[rt];
    ST[((rt << 1) | 1)] += lazy[rt];
    lazy[rt] = 0;
  }
}
void Push_up(int rt) { ST[rt] = max(ST[(rt << 1)], ST[((rt << 1) | 1)]); }
void Update(int rt, int l, int r, int L, int R, int c) {
  if (l <= L && R <= r) {
    ST[rt] += c;
    lazy[rt] += c;
    return;
  }
  Push_down(rt);
  int mid = (L + R) >> 1;
  if (l <= mid) Update((rt << 1), l, r, L, mid, c);
  if (r > mid) Update(((rt << 1) | 1), l, r, mid + 1, R, c);
  Push_up(rt);
}
int Query(int rt, int L, int R) {
  if (L == R) return L;
  Push_down(rt);
  int mid = (L + R) >> 1;
  if (ST[((rt << 1) | 1)] > 0) return Query(((rt << 1) | 1), mid + 1, R);
  return Query((rt << 1), L, mid);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    Update(1, 1, a[i], 1, maxn - 1, 1);
  }
  for (int i = 1; i <= m; ++i) {
    cin >> b[i];
    Update(1, 1, b[i], 1, maxn - 1, -1);
  }
  int op, p, v;
  cin >> q;
  for (int i = 1; i <= q; ++i) {
    cin >> op >> p >> v;
    if (op == 1) {
      Update(1, 1, a[p], 1, maxn - 1, -1);
      a[p] = v;
      Update(1, 1, a[p], 1, maxn - 1, 1);
    } else if (op == 2) {
      Update(1, 1, b[p], 1, maxn - 1, 1);
      b[p] = v;
      Update(1, 1, b[p], 1, maxn - 1, -1);
    }
    if (ST[1] <= 0)
      cout << -1 << endl;
    else
      cout << Query(1, 1, maxn - 1) << endl;
  }
  return 0;
}
