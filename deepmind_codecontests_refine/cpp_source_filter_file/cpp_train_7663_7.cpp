#include <bits/stdc++.h>
using namespace std;
template <typename TP>
inline bool rd(TP& r) {
  r = 0;
  char tmp = getchar();
  while (tmp < '0' || tmp > '9') {
    if (tmp == EOF) return 0;
    tmp = getchar();
  }
  while ('0' <= tmp && tmp <= '9') {
    r = (r << 3) + (r << 1) + tmp - '0';
    tmp = getchar();
  }
  return 1;
}
int n;
long long xs[100100], ys[100100];
struct poi {
  long long x, y;
  poi(long long xx = 0, long long yy = 0) {
    x = xx;
    y = yy;
  }
} ps[100100];
bool vis[100100 * 2];
void lisan(long long q[]) {
  sort(q + 1, q + n + 1);
  q[0] = unique(q + 1, q + n + 1) - (q + 1);
}
int get(long long q[], long long x) {
  return lower_bound(q + 1, q + q[0] + 1, x) - q;
}
int ac[100100 * 2], sz[100100 * 2], es[100100 * 2];
int acs(int x) {
  if (ac[x] == x) return ac[x];
  ac[x] = acs(ac[x]);
  return ac[x];
}
bool merge(int a, int b) {
  a = acs(a);
  b = acs(b);
  if (a == b) {
    es[a]++;
    return 0;
  }
  if (sz[a] < sz[b]) swap(a, b);
  sz[a] += sz[b];
  ac[b] = a;
  es[a] += es[b] + 1;
  return 1;
}
long long ans = 1;
long long power(long long ori, long long t) {
  long long re = 1;
  while (t) {
    if (t & 1) re = re * ori % 1000000007;
    ori = ori * ori % 1000000007;
    t >>= 1;
  }
  return re;
}
int main() {
  rd(n);
  long long x, y;
  for (int i = 1; i <= n; i++) {
    scanf("%I64d %I64d\n", &x, &y);
    ps[i] = poi(x, y);
    xs[i] = x;
    ys[i] = y;
    ac[i] = i;
    ac[i + n] = i + n;
    sz[i] = 1;
    sz[i + n] = 1;
  }
  lisan(xs);
  lisan(ys);
  for (int i = 1; i <= n; i++) merge(get(xs, ps[i].x), n + get(ys, ps[i].y));
  long long tmp;
  for (int i = 1; i <= xs[0]; i++)
    if (!vis[acs(i)]) {
      vis[acs(i)] = 1;
      tmp = power(2, sz[acs(i)]) - 1;
      if (sz[acs(i)] == es[acs(i)]) tmp += 1;
      tmp = (tmp + 1000000007) % 1000000007;
      ans = ans * tmp % 1000000007;
    }
  for (int i = 1; i <= ys[0]; i++)
    if (!vis[acs(i + n)]) {
      vis[acs(i + n)] = 1;
      tmp = power(2, sz[acs(i + n)]) - 1;
      if (sz[acs(i + n)] == es[acs(i + n)]) tmp += 1;
      tmp = (tmp + 1000000007) % 1000000007;
      ans = ans * tmp % 1000000007;
    }
  printf("%I64d\n", ans);
  return 0;
}
