#include <bits/stdc++.h>
using namespace std;
const int NR = 1e6 + 5;
struct Que {
  int id, l, r, ans;
};
int n, m;
int a[NR], b[NR];
int s[NR];
Que q[NR];
int sum[NR], pos[NR], poss[NR];
int lowbit(int x) { return x & (-x); }
void add(int i, int k) {
  for (; i <= n; i += lowbit(i)) s[i] ^= k;
}
int query(int i) {
  int ans = 0;
  for (; i > 0; i -= lowbit(i)) ans ^= s[i];
  return ans;
}
bool cmp(Que x, Que y) { return x.r < y.r; }
bool cmp2(Que x, Que y) { return x.id < y.id; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    add(i, a[i]);
    b[i] = a[i];
  }
  sort(b + 1, b + 1 + n);
  int tmp = unique(b + 1, b + 1 + n) - b - 1;
  for (int i = 1; i <= n; i++) a[i] = lower_bound(b + 1, b + 1 + tmp, a[i]) - b;
  for (int i = 1; i <= n; i++) sum[i] = query(i);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &q[i].l, &q[i].r);
    q[i].id = i;
  }
  sort(q + 1, q + 1 + m, cmp);
  for (int i = 1; i <= m; i++) {
    if (q[i].r != q[i - 1].r) poss[q[i].r] = i;
  }
  for (int i = 1; i <= n; i++) {
    if (pos[a[i]]) add(pos[a[i]], a[i]);
    int x = poss[i];
    while (q[x].r == i) {
      q[x].ans = (query(i) ^ query(q[x].l - 1)) ^ (sum[i] ^ sum[q[x].l - 1]);
      x++;
    }
    pos[a[i]] = i;
  }
  sort(q + 1, q + 1 + m, cmp2);
  for (int i = 1; i <= m; i++) printf("%d\n", q[i].ans);
  return 0;
}
