#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, M = 1e6 + 5;
const int Z = 300;
struct node {
  int l;
  int r;
  int id;
} a[N];
long long cnt[M * 2];
int f[N];
long long ans[N];
int pos[N], k;
long long res;
inline bool cmp(const node &x, const node &y) {
  if (pos[x.l] == pos[y.l])
    return x.r < y.r;
  else
    return x.l < y.l;
}
inline void update(int x, int y) {
  int t = x ^ k;
  if (t == x) {
    res -= cnt[x] * (cnt[x] - 1) / 2LL;
    cnt[x] += y;
    res += cnt[x] * (cnt[x - 1]) / 2LL;
    return;
  }
  if (y > 0)
    res += cnt[t];
  else
    res -= cnt[t];
  cnt[x] += y;
  return;
}
inline int read() {
  char ch = getchar();
  int res = 0;
  while (ch < '0') ch = getchar();
  while (ch >= '0') {
    res = res * 10 + ch - 48;
    ch = getchar();
  }
  return res;
}
int main() {
  int n, m;
  n = read();
  m = read();
  k = read();
  for (int i = (1); i <= (n); i++) f[i] = read();
  for (int i = (2); i <= (n); i++) f[i] ^= f[i - 1];
  for (int i = (1); i <= (n); i++) pos[i] = i / Z;
  for (int i = (1); i <= (m); i++) {
    a[i].l = read();
    a[i].r = read();
  }
  for (int i = (1); i <= (m); i++) a[i].id = i;
  sort(a + 1, a + 1 + m, cmp);
  int tx = 0, ty = -1;
  for (int i = (1); i <= (m); i++) {
    int x = a[i].l - 1, y = a[i].r;
    while (ty < y) {
      update(f[ty + 1], 1);
      ty++;
    }
    while (ty > y) {
      update(f[ty], -1);
      ty--;
    }
    while (tx < x) {
      update(f[tx], -1);
      tx++;
    }
    while (tx > x) {
      update(f[tx - 1], 1);
      tx--;
    }
    ans[a[i].id] = res;
  }
  for (int i = (1); i <= (m); i++) printf("%I64d\n", ans[i]);
  return 0;
}
