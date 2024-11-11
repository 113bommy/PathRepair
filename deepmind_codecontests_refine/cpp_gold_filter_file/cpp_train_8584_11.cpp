#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3fffffff;
const long long mod = 1000000007;
const int maxn = 1e5 + 10;
int a[maxn];
int seg[60][maxn * 4];
void pushup(int x) {
  for (int i = 0; i < 60; i++) {
    seg[i][x] = seg[i][x * 2] + seg[(i + seg[i][x * 2]) % 60][x * 2 + 1];
  }
}
void build(int i, int l, int r) {
  if (l == r) {
    for (int o = 0; o < 60; o++) seg[o][i] = 1 + (o % a[l] == 0);
    return;
  }
  int m = (l + r) / 2;
  build(i * 2, l, m);
  build(i * 2 + 1, m + 1, r);
  pushup(i);
}
void update(int i, int l, int r, int pos, int v) {
  if (l == r) {
    for (int o = 0; o < 60; o++) seg[o][i] = 1 + (o % a[pos] == 0);
    return;
  }
  int m = (l + r) / 2;
  if (pos <= m)
    update(i * 2, l, m, pos, v);
  else
    update(i * 2 + 1, m + 1, r, pos, v);
  pushup(i);
}
int query(int o, int i, int L, int R, int l, int r) {
  if (L == l && R == r) {
    return seg[o][i];
  }
  int m = (L + R) / 2;
  if (r <= m)
    return query(o, i * 2, L, m, l, r);
  else if (l > m)
    return query(o, i * 2 + 1, m + 1, R, l, r);
  else {
    int ans = query(o, i * 2, L, m, l, m);
    return ans + query((o + ans) % 60, i * 2 + 1, m + 1, R, m + 1, r);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n + 1; i++) scanf("%d", &a[i]);
  build(1, 1, n);
  int m;
  scanf("%d", &m);
  while (m--) {
    char s[2];
    scanf("%s", s);
    int x, y;
    scanf("%d%d", &x, &y);
    if (s[0] == 'C') {
      a[x] = y;
      update(1, 1, n, x, y);
    } else if (s[0] == 'A') {
      printf("%d\n", query(0, 1, 1, n, x, y - 1));
    }
  }
  return 0;
}
