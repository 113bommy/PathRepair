#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;
const int N = 5e5 + 5;
int n, m, q, ans[N];
struct node {
  int cnt, id;
} c[N];
struct ask {
  int id;
  long long x;
} Q[N];
int st[N << 2];
void update(int o, int l, int r, int pos) {
  if (l == r) {
    ++st[o];
    return;
  }
  int mid = l + r >> 1;
  if (pos <= mid)
    update(o << 1, l, mid, pos);
  else
    update(o << 1 | 1, mid + 1, r, pos);
  st[o] = st[o << 1] + st[o << 1 | 1];
}
int query(int o, int l, int r, int k) {
  if (l == r) return l;
  int mid = l + r >> 1;
  if (k <= st[o << 1])
    return query(o << 1, l, mid, k);
  else
    return query(o << 1 | 1, mid + 1, r, k - st[o << 1]);
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    ++c[x].cnt;
  }
  for (int i = 1; i <= m; i++) c[i].id = i;
  for (int i = 1; i <= q; i++) {
    long long x;
    scanf("%lld", &x);
    Q[i].id = i, Q[i].x = x;
  }
  sort(c + 1, c + 1 + m, [](const node& a, const node& b) {
    return a.cnt == b.cnt ? a.id < b.id : a.cnt < b.cnt;
  });
  sort(Q + 1, Q + 1 + n, [](const ask& a, const ask& b) { return a.x < b.x; });
  long long now = n;
  int j = 1;
  for (int i = 1; i <= m; i++) {
    long long nxt = (i == m ? 2e18 : 1ll * (c[i + 1].cnt - c[i].cnt) * i + now);
    update(1, 1, m, c[i].id);
    while (j <= q && Q[j].x <= nxt) {
      long long x = Q[j].x;
      int tmp = (x - now) % i;
      if (!tmp) tmp = i;
      ans[Q[j].id] = query(1, 1, m, tmp);
      ++j;
    }
    now = nxt;
  }
  for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
  return 0;
}
