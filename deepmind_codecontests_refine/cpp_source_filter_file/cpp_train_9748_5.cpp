#include <bits/stdc++.h>
using namespace std;
inline int gi() {
  register int data = 0, w = 1;
  register char ch = 0;
  while (!isdigit(ch) && ch != '-') ch = getchar();
  if (ch == '-') w = -1, ch = getchar();
  while (isdigit(ch)) data = 10 * data + ch - '0', ch = getchar();
  return w * data;
}
const int MAX_N = 2e5 + 5;
int N, M, Q;
long long f[MAX_N], A[MAX_N], B[MAX_N];
long long mn[MAX_N << 2], tg[MAX_N << 2];
void puttag(int o, int v) { mn[o] += v, tg[o] += v; }
void pushup(int o) { mn[o] = min(mn[(o << 1)], mn[(o << 1 | 1)]); }
void pushdown(int o) {
  if (!tg[o]) return;
  puttag((o << 1), tg[o]), puttag((o << 1 | 1), tg[o]);
  tg[o] = 0;
}
void build(int o, int l, int r) {
  tg[o] = mn[o] = 0;
  if (l == r) return (void)(mn[o] = B[l]);
  int mid = (l + r) >> 1;
  build((o << 1), l, mid), build((o << 1 | 1), mid + 1, r);
  pushup(o);
}
void modify(int o, int l, int r, int ql, int qr, int v) {
  if (ql <= l && r <= qr) return puttag(o, v);
  pushdown(o);
  int mid = (l + r) >> 1;
  if (ql <= mid) modify((o << 1), l, mid, ql, qr, v);
  if (qr > mid) modify((o << 1 | 1), mid + 1, r, ql, qr, v);
  pushup(o);
}
vector<pair<int, int> > G[MAX_N];
int main() {
  N = gi(), M = gi(), Q = gi();
  for (int i = 2; i <= N; i++) A[i - 1] = gi(), B[i] = gi();
  for (int i = 1; i <= M; i++) {
    int u = gi(), v = gi(), w = gi();
    G[u].push_back(make_pair(v, w));
  }
  build(1, 1, N);
  for (int x = 1; x <= N; x++) {
    for (auto it : G[x]) modify(1, 1, N, 1, it.first, it.second);
    f[x] = mn[1];
  }
  for (int i = 1; i <= N; i++) B[i] = A[i] + f[i];
  build(1, 1, N);
  printf("%lld\n", mn[1]);
  while (Q--) {
    int id = gi(), v = gi();
    modify(1, 1, N, id, id, v - A[id]);
    A[id] = v;
    printf("%lld\n", mn[1]);
  }
  return 0;
}
