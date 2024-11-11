#include <bits/stdc++.h>
using namespace std;
inline int rd() {
  int x = 0;
  char c = getchar();
  bool f = 0;
  while (c < '0' && c != '-') c = getchar();
  if (c == '-') f = 1, c = getchar();
  while (c >= '0') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return f ? -x : x;
}
const int SIZE = 2e5 + 100;
int n;
int fa[SIZE], num[SIZE];
long long sumb[SIZE];
int rt[SIZE];
int cnt[SIZE * 20], lson[SIZE * 20], rson[SIZE * 20], node_cnt;
long long sum[SIZE * 20], res[SIZE * 20];
void Up(int p) {
  cnt[p] = cnt[lson[p]] + cnt[rson[p]];
  sum[p] = sum[lson[p]] + sum[rson[p]];
  res[p] = res[lson[p]] + res[rson[p]] + sum[lson[p]] * cnt[rson[p]];
}
void Insert(int &now, int L, int R, int x) {
  if (now == 0) now = ++node_cnt;
  if (L == R) {
    cnt[now] = 1;
    sum[now] = res[now] = x;
    return;
  }
  int mid = (L + R) >> 1;
  if (x <= mid)
    Insert(lson[now], L, mid, x);
  else
    Insert(rson[now], mid + 1, R, x);
  Up(now);
}
int Merge(int a, int b) {
  if (a == 0 || b == 0) return a + b;
  lson[a] = Merge(lson[a], lson[b]);
  rson[a] = Merge(rson[a], rson[b]);
  Up(a);
  return a;
}
long long ans;
void Uni(int a, int b) {
  ans -= res[rt[a]] + res[rt[b]] + (a - 1) * sumb[a] + (b - 1) * sumb[b];
  fa[b] = a;
  sumb[a] += sumb[b];
  num[a] += num[b];
  rt[a] = Merge(rt[a], rt[b]);
  ans += res[rt[a]] + (a - 1) * sumb[a];
}
int Find(int x) {
  if (x == fa[x]) return x;
  return fa[x] = Find(fa[x]);
}
void _main() {
  n = rd();
  for (register int i = 1, _n = 200000; i <= _n; ++i) fa[i] = i, num[i] = 0;
  for (register int i = 1, _n = n; i <= _n; ++i) {
    int a = rd(), b = rd();
    int x = Find(a);
    ans -= res[rt[x]];
    Insert(rt[x], 1, n, b);
    ++num[x];
    ans += 1LL * ((x - 1) - a) * b;
    sumb[x] += b;
    ans += res[rt[x]];
    if (x + num[x] <= 200000) Uni(x, x + num[x]);
    printf("%lld\n", ans);
  }
}
int main() {
  _main();
  return 0;
}
