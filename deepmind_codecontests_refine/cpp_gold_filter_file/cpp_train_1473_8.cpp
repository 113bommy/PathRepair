#include <bits/stdc++.h>
using namespace std;
int n, q, a[1000005], mk[1000005 << 2], l[1000005], r[1000005], st[1000005];
long long T[1000005 << 2], ans[1000005];
struct node {
  int x, id;
};
vector<node> vl[1000005], vr[1000005];
void pushdown(int k, int l, int r) {
  mk[k << 1] += mk[k], mk[k << 1 | 1] += mk[k];
  int len = r - l + 1;
  T[k << 1] += 1ll * (len - (len >> 1)) * mk[k],
      T[k << 1 | 1] += 1ll * (len >> 1) * mk[k];
  mk[k] = 0;
}
void add(int l, int r, int a, int b, int k) {
  if (a > b) return;
  if (a <= l && r <= b) return (void)(T[k] += r - l + 1, mk[k]++);
  int mid = (l + r) >> 1;
  if (mk[k]) pushdown(k, l, r);
  if (a <= mid) add(l, mid, a, b, k << 1);
  if (b > mid) add(mid + 1, r, a, b, k << 1 | 1);
  T[k] = T[k << 1] + T[k << 1 | 1];
}
long long que(int l, int r, int a, int b, int k) {
  if (l == a && r == b) return T[k];
  int mid = (l + r) >> 1;
  if (mk[k]) pushdown(k, l, r);
  if (b <= mid) return que(l, mid, a, b, k << 1);
  if (a > mid) return que(mid + 1, r, a, b, k << 1 | 1);
  return que(l, mid, a, mid, k << 1) + que(mid + 1, r, mid + 1, b, k << 1 | 1);
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  a[0] = a[n + 1] = n + 1;
  for (int i = 1; i <= q; i++) scanf("%d", &l[i]);
  for (int i = 1; i <= q; i++) scanf("%d", &r[i]);
  for (int i = 1; i <= q; i++)
    vl[l[i]].push_back((node){r[i], i}), vr[r[i]].push_back((node){l[i], i});
  int top = 0;
  st[top = 1] = 0;
  for (int i = 1; i <= n; i++) {
    while (top && a[st[top]] <= a[i]) --top;
    add(1, n, st[top] + 1, i - 1, 1);
    st[++top] = i;
    int tt = vr[i].size();
    for (int j = 0; j < tt; j++)
      ans[vr[i][j].id] += que(1, n, vr[i][j].x, i, 1);
  }
  memset(T, 0, sizeof(T));
  memset(mk, 0, sizeof(mk));
  st[top = 1] = n + 1;
  for (int i = n; i >= 1; i--) {
    while (top && a[st[top]] <= a[i]) --top;
    add(1, n, i + 1, st[top] - 1, 1);
    st[++top] = i;
    int tt = vl[i].size();
    for (int j = 0; j < tt; j++)
      ans[vl[i][j].id] += que(1, n, i, vl[i][j].x, 1);
  }
  for (int i = 1; i <= q; i++) printf("%lld ", ans[i] + r[i] - l[i] + 1);
}
