#include <bits/stdc++.h>
const int inf = 1e9 + 10;
using namespace std;
struct operation {
  int a, b, c, d;
  operation(int a = 0, int b = 0, int c = 0, int d = 0)
      : a(a), b(b), c(c), d(d) {}
};
int N, M;
long long v[5020];
operation r[5020];
long long tree[4 * 5020], lazy[4 * 5020];
int m(int l, int r) { return (l + r) / 2; }
void refresh(int pos, int l, int r) {
  long long k = lazy[pos];
  lazy[pos] = 0;
  tree[pos] += k;
  if (l == r) return;
  lazy[2 * pos] += k;
  lazy[2 * pos + 1] += k;
}
void updtree(int pos, int l, int r, int ini, int endi, int val) {
  refresh(pos, l, r);
  if (r < ini || l > endi) return;
  if (l >= ini && r <= endi) {
    lazy[pos] += val;
    refresh(pos, l, r);
    return;
  }
  updtree(pos * 2, l, m(l, r), ini, endi, val);
  updtree(pos * 2 + 1, m(l, r) + 1, r, ini, endi, val);
  tree[pos] = max(tree[pos * 2], tree[pos * 2 + 1]);
}
long long querytree(int pos, int l, int r, int ini, int endi) {
  refresh(pos, l, r);
  if (r < ini || l > endi) return -inf;
  if (l >= ini && r <= endi) return tree[pos];
  long long re = querytree(pos * 2, l, m(l, r), ini, endi);
  long long rd = querytree(pos * 2 + 1, m(l, r) + 1, r, ini, endi);
  return max(re, rd);
}
int bit[5020];
void upd(int x, int val) {
  for (int i = x; i < 5020; i += (i & -i)) bit[i] += val;
}
long long query(int x) {
  long long tot = 0;
  for (int i = x; i != 0; i -= (i & -i)) tot += bit[i];
  return tot;
}
void NewValue(int l, int r, int val) {
  for (int i = l; i < r + 1; i++) {
    long long k = query(i);
    v[i] = min(v[i], val - k);
  }
}
void print(int pos, int l, int r) {
  printf("%d %d-> %d\n", l, r, tree[pos]);
  if (l == r) return;
  print(2 * pos, l, m(l, r));
  print(2 * pos + 1, m(l, r) + 1, r);
}
int main() {
  for (int i = 0; i < 5020; i++) v[i] = inf;
  scanf("%d%d", &N, &M);
  for (int i = 0; i < M; i++) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    r[i] = operation(a, b, c, d);
    if (a == 1) {
      upd(b, d);
      upd(c + 1, -d);
      continue;
    }
    NewValue(b, c, d);
  }
  for (int i = 1; i < N + 1; i++) updtree(1, 1, N, i, i, v[i]);
  for (int i = 0; i < M; i++) {
    if (r[i].a == 1) {
      updtree(1, 1, N, r[i].b, r[i].c, r[i].d);
      continue;
    }
    if (querytree(1, 1, N, r[i].b, r[i].c) != r[i].d) {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  for (int i = 1; i < N + 1; i++) printf("%lld ", v[i]);
}
