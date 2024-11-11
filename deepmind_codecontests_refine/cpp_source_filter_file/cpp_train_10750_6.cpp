#include <bits/stdc++.h>
using namespace std;
int n, q;
int A[500006];
vector<pair<int, int> > que[500006];
int ans[500006];
int T[500006 << 2], lz[500006 << 2];
void pu(int rt) { T[rt] = min(T[rt << 1], T[rt << 1 | 1]); }
void pd(int rt) {
  if (lz[rt]) {
    T[rt << 1] += lz[rt], T[rt << 1 | 1] += lz[rt];
    lz[rt << 1] += lz[rt], lz[rt << 1 | 1] += lz[rt];
    lz[rt] = 0;
  }
}
void mdfy(int rt, int l, int r, int L, int R) {
  if (L <= l && R >= r) {
    T[rt]--;
    lz[rt]--;
    return;
  }
  pd(rt);
  int m = l + r >> 1;
  if (L <= m) mdfy(rt << 1, l, m, L, R);
  if (R > m) mdfy(rt << 1 | 1, m + 1, r, L, R);
  pu(rt);
}
int wkr(int rt, int l, int r) {
  if (l == r) {
    T[rt] = 0x3f3f3f3f;
    return l;
  }
  pd(rt);
  int m = l + r >> 1, ret = 0;
  if (!T[rt << 1 | 1])
    ret = wkr(rt << 1 | 1, m + 1, r);
  else
    ret = wkr(rt << 1, l, m);
  pu(rt);
  return ret;
}
void lsj(int rt, int l, int r, int p, int c) {
  if (l == r) {
    T[rt] = c;
    return;
  }
  pd(rt);
  int m = l + r >> 1;
  if (p <= m)
    lsj(rt << 1, l, m, p, c);
  else
    lsj(rt << 1 | 1, m + 1, r, p, c);
  pu(rt);
}
int S[500006];
void add(int x, int c) {
  while (x <= n) S[x] += c, x += (x & -x);
}
int sum(int x) {
  int ret = 0;
  while (x > 0) ret += S[x], x -= (x & -x);
  return ret;
}
void solve() {
  cin >> n >> q;
  for (int i = (1), iend = (n); i <= iend; ++i) scanf("%d", A + i);
  for (int i = (1), iend = (q); i <= iend; ++i) {
    static int l, r;
    scanf("%d%d", &l, &r);
    r = n - r;
    if (l >= r - 1)
      ans[i] = 0;
    else
      que[l + 1].emplace_back(make_pair(r, i));
  }
  memset(T, 0x3f, sizeof T);
  for (int i = (n), iend = (1); i >= iend; --i) {
    if (A[i] <= i) lsj(1, 1, n, i, i - A[i]);
    while (!T[1]) {
      int x = wkr(1, 1, n);
      mdfy(1, 1, n, x, n);
      add(x, 1);
    }
    for (auto t : que[i]) ans[t.second] = sum(t.first) - sum(i - 1);
  }
  for (int i = (1), iend = (q); i <= iend; ++i) printf("%d\n", ans[i]);
}
signed main() { solve(); }
