#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7;
int add(int a, int b) {
  if ((a += b) >= P) a -= P;
  return a < 0 ? a + P : a;
}
int mul(int a, int b) { return 1ll * a * b % P; }
int kpow(int a, int b) {
  int r = 1;
  for (; b; b >>= 1, a = mul(a, a)) {
    if (b & 1) r = mul(r, a);
  }
  return r;
}
const int N = 2e5 + 5;
int n, m;
pair<int, int> a[N];
struct node {
  int pos, k, id;
} q[N];
bool cmp(node a, node b) { a.k < b.k; }
int ans[N], b[N << 2], c[N];
void upd(int L, int l, int r, int rt) {
  if (l == r) {
    b[rt] = 1;
    return;
  }
  int m = l + r >> 1;
  if (L <= m)
    upd(L, l, m, rt << 1);
  else
    upd(L, m + 1, r, rt << 1 | 1);
  b[rt] = b[rt << 1] + b[rt << 1 | 1];
}
int qry(int k, int l, int r, int rt) {
  if (l == r) return l;
  int m = l + r >> 1;
  if (b[rt << 1] >= k)
    return qry(k, l, m, rt << 1);
  else
    return qry(k - b[rt << 1], m + 1, r, rt << 1 | 1);
}
int main() {
  scanf("%d", &n);
  for (int i = (1); i < (n + 1); i++)
    scanf("%d", &a[i].first), a[i].second = i, c[i] = a[i].first;
  sort(a + 1, a + n + 1, [](pair<int, int> x, pair<int, int> y) {
    if (x.first != y.first)
      return x.first > y.first;
    else
      return x.second < y.second;
  });
  int m;
  scanf("%d", &m);
  for (int i = (1); i < (m + 1); i++) {
    scanf("%d%d", &q[i].k, &q[i].pos);
    q[i].id = i;
  }
  sort(q + 1, q + m + 1, cmp);
  int l = 0;
  for (int i = (1); i < (m + 1); i++) {
    while (l < q[i].k) l++, upd(a[l].second, 1, n, 1);
    ans[q[i].id] = c[qry(q[i].pos, 1, n, 1)];
  }
  for (int i = (1); i < (m + 1); i++) printf("%d\n", ans[i]);
  return 0;
}
