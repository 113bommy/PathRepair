#include <bits/stdc++.h>
int max(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}
struct node {
  int ch[2];
} no[500010 << 4];
int val[500010 << 2];
int query(int v, int l, int r, int ll, int rr) {
  if (!v) return 0;
  if (l == ll && rr == r) {
    return val[v];
  }
  int m = (l + r) >> 1;
  if (rr <= m)
    return query(no[v].ch[0], l, m, ll, rr);
  else if (m < ll)
    return query(no[v].ch[1], m + 1, r, ll, rr);
  else
    return max(query(no[v].ch[0], l, m, ll, m),
               query(no[v].ch[1], m + 1, r, m + 1, rr));
}
int tot;
void insert(int &v, int l, int r, int pos, int ans) {
  if (!v) v = ++tot;
  val[v] = max(val[v], ans);
  if (l == r) return;
  int m = (l + r) >> 1;
  if (pos <= m)
    insert(no[v].ch[0], l, m, pos, ans);
  else
    insert(no[v].ch[1], m + 1, r, pos, ans);
}
int rt[500010];
int main() {
  int n, m;
  memset(no, 0, sizeof no);
  scanf("%d%d", &n, &m);
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    c++;
    int len = query(rt[a], 1, 100001, 1, c - 1) + 1;
    ans = max(len, ans);
    insert(rt[b], 1, 100001, c, len);
  }
  printf("%d", ans);
}
