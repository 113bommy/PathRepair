#include <bits/stdc++.h>
using namespace std;
const int moo = 1000000007;
const int N = 100005;
const int B = 355, BLK = 2;
int n, cnt, Q, a[N], L[B], R[B];
int arl[B][B], arr[B][B];
int bas1, bas2, p1[B], p2[B];
int flag[B];
int rnd() {
  int x = 0;
  for (int i = (int)(1); i <= (int)(9); i++) x = x * 10 + rand() % 10;
  return x;
}
void init_seed() {
  for (; clock() < 30; rnd())
    ;
  bas1 = rnd() % 50000000 * 2 + 1 + 1926 * 817;
  bas2 = rnd() % 50000000 * 2 + 1 + 1926 * 817;
  p1[0] = p2[0] = 1;
  for (int i = (int)(1); i <= (int)(B - 1); i++)
    p1[i] = 1ll * p1[i - 1] * bas1 % moo;
  for (int i = (int)(1); i <= (int)(B - 1); i++)
    p2[i] = 1ll * p2[i - 1] * bas2 % moo;
}
struct Hash_node {
  int a[B], v1[B], v2[B], top;
  void init() { top = 0; }
  void ins(int x) { a[++top] = x; }
  void build() {
    v1[0] = v2[0] = 0;
    for (int i = (int)(1); i <= (int)(top); i++)
      v1[i] = (1ll * v1[i - 1] * bas1 + a[i] + N) % moo;
    for (int i = (int)(1); i <= (int)(top); i++)
      v2[i] = (1ll * v2[i - 1] * bas2 + a[i] + N) % moo;
  }
  pair<int, int> ask(int r, int len) {
    int key1 = (v1[r] + moo - 1ll * v1[r - len] * p1[len] % moo) % moo;
    int key2 = (v2[r] + moo - 1ll * v2[r - len] * p2[len] % moo) % moo;
    return pair<int, int>(key1, key2);
  }
} hsh1[B], hsh2[B];
void build(int id, int l, int r) {
  static int q[B], top;
  top = flag[id] = 0;
  for (int i = (int)(l); i <= (int)(r); i++)
    if (a[i] < 0 && top && q[top] == -a[i])
      --top;
    else
      q[++top] = a[i];
  for (int i = (int)(2); i <= (int)(top); i++)
    if (q[i] < 0 && q[i - 1] > 0) flag[id] = 1;
  if (flag[id]) return;
  hsh1[id].init();
  hsh2[id].init();
  for (int i = (int)(top); i >= (int)(1); i--)
    if (q[i] < 0) hsh1[id].ins(q[i]);
  for (int i = (int)(1); i <= (int)(top); i++)
    if (q[i] > 0) hsh2[id].ins(q[i]);
  hsh1[id].build();
  hsh2[id].build();
}
void change(int x, int y) {
  a[x] = y;
  int be = (x - 1) / BLK + 1;
  build(be, L[be], R[be]);
}
int top, ok;
pair<int, int> q[B];
void insert(int id) {
  if (flag[id]) ok = 0;
  if (!ok) return;
  int len = hsh1[id].top;
  for (; top && ok && len;) {
    int v = min(q[top].second, len);
    if (hsh1[q[top].first].ask(q[top].second, v) != hsh2[id].ask(len, v))
      ok = 0;
    if (!(q[top].second -= v)) --top;
    len -= v;
  }
  if (len) ok = 0;
  if (hsh2[id].top) q[++top] = pair<int, int>(id, hsh2[id].top);
}
bool query(int l, int r) {
  int bl = (l - 1) / BLK + 1, br = (r - 1) / BLK + 1;
  if (bl == br) {
    static int q[B], top;
    top = 0;
    for (int i = (int)(l); i <= (int)(r); i++)
      if (a[i] < 0 && top && q[top] == -a[i])
        --top;
      else
        q[++top] = a[i];
    return !top;
  } else {
    build(cnt + 1, l, R[bl]);
    build(cnt + 2, L[br], r);
    top = 0;
    ok = 1;
    insert(cnt + 1);
    for (int i = (int)(bl + 1); i <= (int)(br - 1); i++) insert(i);
    insert(cnt + 2);
    return ok && !top;
  }
}
int main() {
  init_seed();
  scanf("%d%*d", &n);
  for (int i = (int)(1); i <= (int)(n); i++) scanf("%d", &a[i]);
  cnt = (n - 1) / BLK + 1;
  for (int i = (int)(1); i <= (int)(cnt); i++) {
    L[i] = (i - 1) * BLK + 1;
    R[i] = min(n, i * BLK);
    build(i, L[i], R[i]);
  }
  scanf("%d", &Q);
  while (Q--) {
    int tp, x, y;
    scanf("%d%d%d", &tp, &x, &y);
    if (tp == 1)
      change(x, y);
    else
      puts(query(x, y) ? "Yes" : "No");
  }
}
