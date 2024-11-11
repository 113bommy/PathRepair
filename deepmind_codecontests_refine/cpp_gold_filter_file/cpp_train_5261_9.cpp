#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 200000;
typedef struct S {
  int l, r, idx;
} S;
bool operator<(const S &a, const S &b) {
  if (a.l != b.l) return a.l > b.l;
  if (a.r != b.r) return a.r < b.r;
  return a.idx < b.idx;
}
int n;
S s[MAXN];
int x[2 * MAXN], nx;
int ret[MAXN];
int bt[2 * MAXN + 1];
int bget(int idx) {
  ++idx;
  int ret = 0;
  while (idx > 0) {
    ret += bt[idx];
    idx -= idx & -idx;
  }
  return ret;
}
void bmod(int idx, int by) {
  ++idx;
  while (idx <= nx) {
    bt[idx] += by;
    idx += idx & -idx;
  }
}
void run() {
  scanf("%d", &n);
  for (int i = (0); i < (n); ++i) scanf("%d%d", &s[i].l, &s[i].r), s[i].idx = i;
  nx = 0;
  for (int i = (0); i < (n); ++i) x[nx++] = s[i].l, x[nx++] = s[i].r;
  sort(x, x + nx);
  nx = unique(x, x + nx) - x;
  for (int i = (0); i < (n); ++i)
    s[i].l = lower_bound(x, x + nx, s[i].l) - x,
    s[i].r = lower_bound(x, x + nx, s[i].r) - x;
  sort(s, s + n);
  memset(bt, 0, sizeof(bt));
  for (int i = (0); i < (n); ++i) {
    ret[s[i].idx] = bget(s[i].r);
    bmod(s[i].r, +1);
  }
  for (int i = (0); i < (n); ++i) printf("%d\n", ret[i]);
}
int main() {
  run();
  return 0;
}
