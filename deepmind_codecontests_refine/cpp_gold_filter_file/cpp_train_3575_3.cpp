#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int G, R, n;
int d[MAXN], m;
long long s[MAXN];
int itv[MAXN][4];
int b[MAXN * 4];
int st[MAXN * 4], ed[MAXN * 4];
long long rm[MAXN];
int fst[MAXN * 4];
int f(int x) {
  int l = 1, r = m;
  while (l < r) {
    int mid = (l + r) / 2;
    if (ed[mid] < x)
      l = mid + 1;
    else if (st[mid] > x)
      r = mid - 1;
    else
      return mid;
  }
  return l;
}
struct SEGMENT_TREE {
  int left, right, cover;
} Segtree[1048579 * 2];
void Build(int p, int l, int r) {
  Segtree[p].left = l;
  Segtree[p].right = r;
  Segtree[p].cover = -1;
  if (l != r) {
    int mid = (l + r) >> 1;
    Build(2 * p, l, mid), Build(2 * p + 1, mid + 1, r);
  }
}
void Insert(int p, int l, int r, int v) {
  if (Segtree[p].left == l && Segtree[p].right == r)
    Segtree[p].cover = v;
  else {
    int mid = (Segtree[p].left + Segtree[p].right) >> 1;
    if (Segtree[p].cover != -1) {
      Insert(2 * p, Segtree[p].left, mid, Segtree[p].cover);
      Insert(2 * p + 1, mid + 1, Segtree[p].right, Segtree[p].cover);
      Segtree[p].cover = -1;
    }
    if (r <= mid)
      Insert(2 * p, l, r, v);
    else if (l > mid)
      Insert(2 * p + 1, l, r, v);
    else
      Insert(2 * p, l, mid, v), Insert(2 * p + 1, mid + 1, r, v);
  }
}
void push_down(int p) {
  if (Segtree[p].left == Segtree[p].right)
    fst[Segtree[p].left] = Segtree[p].cover;
  else {
    if (Segtree[p].cover != -1) {
      for (int i = Segtree[p].left; i <= Segtree[p].right; i++)
        fst[i] = Segtree[p].cover;
      return;
    }
    push_down(2 * p);
    push_down(2 * p + 1);
  }
}
int ask(int p, int x) {
  if (Segtree[p].left == Segtree[p].right || Segtree[p].cover != -1)
    return Segtree[p].cover;
  int mid = (Segtree[p].left + Segtree[p].right) >> 1;
  if (x <= mid)
    return ask(2 * p, x);
  else
    return ask(2 * p + 1, x);
}
int main() {
  scanf("%d%d%d", &n, &G, &R);
  for (int i = 1; i <= n + 1; i++) scanf("%d", &d[i]);
  for (int i = 1; i <= n + 1; i++) s[i] = s[i - 1] + d[i];
  for (int i = 1; i <= n; i++) {
    int S = s[i] % (R + G);
    itv[i][0] = max(G - S, 0);
    itv[i][1] = R + G - 1 - S;
    itv[i][2] = R + G + min(0, G - S);
    itv[i][3] = R + G - 1;
  }
  for (int i = 1; i <= n; i++) {
    if (itv[i][0] <= itv[i][1]) {
      b[++m] = itv[i][0];
      b[++m] = itv[i][1];
    }
    if (itv[i][2] <= itv[i][3]) {
      b[++m] = itv[i][2];
      b[++m] = itv[i][3];
    }
  }
  b[++m] = 0;
  b[++m] = R + G - 1;
  sort(b + 1, b + m + 1);
  int x = 0;
  for (int i = 1; i <= m; i++) {
    if (i == 1 || b[i] != b[i - 1]) {
      if (i != 1 && b[i] - b[i - 1] != 1)
        st[++x] = b[i - 1] + 1, ed[x] = b[i] - 1;
      st[++x] = b[i], ed[x] = b[i];
    }
  }
  m = x;
  Build(1, 1, m);
  for (int i = n; i >= 1; i--) {
    if (itv[i][0] <= itv[i][1]) Insert(1, f(itv[i][0]), f(itv[i][1]), i);
    if (itv[i][2] <= itv[i][3]) Insert(1, f(itv[i][2]), f(itv[i][3]), i);
    int x = ((R + G) - s[i] % (R + G)) % (R + G);
    int t = ask(1, f(x));
    if (t == -1)
      rm[i] = s[n + 1] - s[i];
    else
      rm[i] = ((s[t] - s[i]) / (R + G) + 1) * (R + G) + rm[t];
  }
  push_down(1);
  int T;
  scanf("%d", &T);
  while (T--) {
    int x;
    scanf("%d", &x);
    int y = x % (G + R);
    if (fst[f(y)] == -1)
      printf("%I64d\n", s[n + 1] + x);
    else
      printf("%I64d\n",
             ((s[fst[f(y)]] + x) / (R + G) + 1) * (R + G) + rm[fst[f(y)]]);
  }
  return 0;
}
