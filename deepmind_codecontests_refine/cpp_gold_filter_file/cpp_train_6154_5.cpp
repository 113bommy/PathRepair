#include <bits/stdc++.h>
using namespace std;
const int MAXN = 400005;
template <typename T>
inline void read(T &AKNOI) {
  T x = 0, flag = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  AKNOI = flag * x;
}
int f[MAXN], R[MAXN];
int tot, root[MAXN], lc[MAXN * 20], rc[MAXN * 20], cnt[MAXN * 20];
long long sum[MAXN * 20], ans;
int getf(int v) { return (f[v] == v) ? v : f[v] = getf(f[v]); }
void Insert(int &rt, int b, int e, int p) {
  rt = ++tot;
  cnt[rt] += 1;
  sum[rt] += p;
  if (b == e) return;
  int mid = (b + e) >> 1;
  if (p <= mid)
    Insert(lc[rt], b, mid, p);
  else
    Insert(rc[rt], mid + 1, e, p);
}
int Merge(int x, int y) {
  if (!x || !y) return x + y;
  ans -= sum[lc[x]] * cnt[rc[x]] + sum[lc[y]] * cnt[rc[y]];
  cnt[x] += cnt[y];
  sum[x] += sum[y];
  lc[x] = Merge(lc[x], lc[y]);
  rc[x] = Merge(rc[x], rc[y]);
  ans += sum[lc[x]] * cnt[rc[x]];
  return x;
}
void Combine(int x, int y) {
  x = getf(x);
  y = getf(y);
  f[y] = x;
  R[x] = R[y];
  ans -= sum[root[x]] * x + sum[root[y]] * y;
  root[x] = Merge(root[x], root[y]);
  ans += sum[root[x]] * x;
}
void solve() {
  for (int i = 1; i < MAXN; ++i) {
    f[i] = R[i] = i;
  }
  int n;
  read(n);
  for (int i = 1; i <= n; ++i) {
    int a, b;
    read(a);
    read(b);
    int p = root[a] ? R[getf(a)] + 1 : a;
    ans += 1LL * (p - a) * b;
    Insert(root[p], 1, n, b);
    if (root[p - 1]) Combine(p - 1, p);
    if (root[p + 1]) Combine(p, p + 1);
    printf("%lld\n", ans);
  }
}
int main() {
  solve();
  return 0;
}
