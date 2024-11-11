#include <bits/stdc++.h>
using namespace std;
const int maxn = 400010, inf = ~0U >> 1;
struct Querys {
  int a, b, id;
} qur[maxn];
struct Segment_Tree {
  int head[maxn << 2], next[maxn << 2], F[maxn << 2], Ecnt;
  int maxh[maxn << 2];
  int n;
  void Update(int o) { maxh[o] = max(maxh[(o << 1)], maxh[(o << 1 | 1)]); }
  void Change(int o, int l, int r, int pos, int c) {
    if (l == r) {
      maxh[o] = c;
      return;
    }
    if (pos <= ((l + r) >> 1)) Change((o << 1), l, ((l + r) >> 1), pos, c);
    if (pos > ((l + r) >> 1))
      Change((o << 1 | 1), ((l + r) >> 1) + 1, r, pos, c);
    Update(o);
  }
  int Query(int o, int l, int r, int a, int b) {
    if (a <= l && r <= b) return maxh[o];
    int res = 0;
    if (a <= ((l + r) >> 1))
      res = max(res, Query((o << 1), l, ((l + r) >> 1), a, b));
    if (b > ((l + r) >> 1))
      res = max(res, Query((o << 1 | 1), ((l + r) >> 1) + 1, r, a, b));
    return res;
  }
  int Query(int a, int b) {
    if (b < a) return 0;
    return Query(1, 1, n, a, b);
  }
  void Change(int x, int c) { Change(1, 1, n, x, c); }
  void Insert(int x, int c) {
    if (head[x] && F[head[x]] > c) return;
    next[++Ecnt] = head[x];
    head[x] = Ecnt;
    F[Ecnt] = c;
    Change(x, c);
  }
  void Delete(int x, int c) {
    if (head[x] == 0 || F[head[x]] != c) return;
    head[x] = next[head[x]];
    Change(x, F[head[x]]);
  }
  void Clear() {
    memset(maxh, 0, sizeof(maxh));
    memset(head, 0, sizeof(head));
    Ecnt = 0;
  }
} Tl, Tr;
int h[maxn];
int ht[maxn << 1], hs;
map<int, int> M;
int fl[maxn], fr[maxn];
int keynode[maxn];
int ans[maxn];
int n, q, uans;
bool cmp(const Querys &a, const Querys &b) { return a.a < b.a; }
bool cmptl(int a, int b) { return a < b; }
bool cmptr(int a, int b) { return a > b; }
void Init() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
  for (int i = 1; i <= q; i++)
    scanf("%d%d", &qur[i].a, &qur[i].b), qur[i].id = i;
  sort(qur + 1, qur + 1 + q, cmp);
  memcpy(ht, h, sizeof(h));
  for (int i = 1; i <= q; i++) ht[n + i] = qur[i].b;
  sort(ht + 1, ht + 1 + n + q);
  hs = unique(ht + 1, ht + 1 + n + q) - (ht + 1);
  for (int i = 1; i <= hs; i++) M[ht[i]] = i;
  for (int i = 1; i <= n; i++) h[i] = M[h[i]];
  for (int i = 1; i <= q; i++) qur[i].b = M[qur[i].b];
  Tl.n = Tr.n = hs;
}
int Q[maxn], top;
void Get_F() {
  memset(Q, 0, sizeof(Q));
  top = 0;
  for (int i = 1; i <= n; i++) {
    int l = 0, r = top, mid;
    while (l < r)
      if (Q[mid = ((l + r + 1) >> 1)] < h[i])
        l = mid;
      else
        r = mid - 1;
    fl[i] = l + 1;
    if (l == top)
      Q[++top] = h[i];
    else
      Q[l + 1] = min(Q[l + 1], h[i]);
  }
  uans = top;
  memset(Q, 0, sizeof(Q));
  top = 0;
  Q[0] = inf;
  for (int i = n; i >= 1; i--) {
    int l = 0, r = top, mid;
    while (l < r)
      if (Q[mid = ((l + r + 1) >> 1)] > h[i])
        l = mid;
      else
        r = mid - 1;
    fr[i] = l + 1;
    if (l == top)
      Q[++top] = h[i];
    else
      Q[l + 1] = max(Q[l + 1], h[i]);
  }
}
void Get_KeyNode() {
  Tl.Clear();
  Tr.Clear();
  M.clear();
  for (int i = n; i >= 1; i--) Tr.Insert(h[i], fr[i]);
  for (int i = 1; i <= n; i++) {
    Tr.Delete(h[i], fr[i]);
    int kl = Tl.Query(1, h[i] - 1), kr = Tr.Query(h[i] + 1, hs);
    if (kl + kr + 1 == uans)
      keynode[i] = kl + 1, M[kl + 1]++;
    else
      keynode[i] = 0;
    Tl.Insert(h[i], fl[i]);
  }
  for (int i = 1; i <= n; i++)
    if (keynode[i]) keynode[i] = (M[keynode[i]] > 1) ? 0 : 1;
}
void Solve() {
  Tl.Clear();
  Tr.Clear();
  for (int i = n; i >= 1; i--) Tr.Insert(h[i], fr[i]);
  for (int i = 1, pos = 0; i <= q; i++) {
    while (pos < qur[i].a) {
      Tl.Insert(h[pos], fl[pos]);
      ++pos;
      Tr.Delete(h[pos], fr[pos]);
    }
    int res = Tl.Query(1, qur[i].b - 1) + Tr.Query(qur[i].b + 1, hs) + 1;
    if (res < uans)
      ans[qur[i].id] = keynode[qur[i].a] == 1 ? uans - 1 : uans;
    else
      ans[qur[i].id] = res;
  }
  for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
}
int main() {
  Init();
  Get_F();
  Get_KeyNode();
  Solve();
  return 0;
}
