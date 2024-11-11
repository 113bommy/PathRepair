#include <bits/stdc++.h>
using namespace std;
int n, NUM;
int t[400500][100];
void up(int rt) {
  for (int i = 0; i < 60; ++i)
    t[rt][i] = t[rt << 1][i] + t[rt << 1 | 1][(i + t[rt << 1][i]) % 60];
}
void build(int l, int r, int rt) {
  if (l == r) {
    int v;
    scanf("%d", &v);
    for (int i = 0; i < 60; ++i) {
      if (i % v)
        t[rt][i] = 1;
      else
        t[rt][i] = 2;
    }
    return;
  }
  int m = (l + r) >> 1;
  build(l, m, rt << 1);
  build(m + 1, r, rt << 1 | 1);
  up(rt);
}
void update(int q, int v, int l, int r, int rt) {
  if (l == r) {
    for (int i = 0; i < 60; ++i) {
      if (i % v)
        t[rt][i] = 1;
      else
        t[rt][i] = 2;
    }
    return;
  }
  int m = (l + r) >> 1;
  if (q <= m)
    update(q, v, l, m, rt << 1);
  else
    update(q, v, m + 1, r, rt << 1 | 1);
  up(rt);
}
int query(int L, int R, int v, int l, int r, int rt) {
  if (L <= l && r <= R) {
    return t[rt][v];
  }
  int m = (l + r) >> 1, s1 = 0, s2 = 0;
  if (L <= m) s1 = query(L, R, v, l, m, rt << 1);
  if (m < R) s2 = query(L, R, v + s1, m + 1, r, rt << 1 | 1);
  return s1 + s2;
}
int main() {
  scanf("%d", &n);
  build(1, n, 1);
  scanf("%d", &NUM);
  while (NUM--) {
    char C;
    int A, B;
    cin >> C >> A >> B;
    if (C == 'A')
      printf("%d\n", query(A, B - 1, 0, 1, n, 1));
    else
      update(A, B, 1, n, 1);
  }
  return 0;
}
