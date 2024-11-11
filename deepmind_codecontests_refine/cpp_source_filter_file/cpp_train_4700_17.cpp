#include <bits/stdc++.h>
using namespace std;
int n, m, m1, len, top, a[1000005], size[1000005], dfn[1000005], nex[1000005],
    wen[1000005], hea[1000005], sta[1000005];
struct segment_tree {
  int a[800005], lazy[800005];
  void pushdown(int k) {
    int t = lazy[k];
    a[k << 1] += t;
    lazy[k << 1] += t;
    a[(k << 1) | 1] += t;
    lazy[(k << 1) | 1] += t;
    lazy[k] = 0;
  }
  void update(int l, int r, int k, int x, int y, int z) {
    if (l >= x && r <= y) {
      a[k] += z;
      lazy[k] += z;
      return;
    }
    pushdown(k);
    int mid = (l + r) >> 1;
    if (x <= mid) update(l, mid, k << 1, x, y, z);
    if (y > mid) update(mid + 1, r, (k << 1) | 1, x, y, z);
    a[k] = max(a[k << 1], a[(k << 1) | 1]);
  }
  int find(int l, int r, int k, int x, int y) {
    if (l >= x && r <= y) return a[k];
    pushdown(k);
    int mid = (l + r) >> 1, ans = 0;
    if (x <= mid) ans = find(l, mid, k << 1, x, y);
    if (y > mid) ans = max(ans, find(mid + 1, r, (k << 1) | 1, x, y));
    return ans;
  }
} st;
void add(int x, int y) {
  ++len;
  nex[len] = hea[x];
  wen[len] = y;
  hea[x] = len;
}
void dfs(int x) {
  dfn[x] = ++m1;
  size[x] = 1;
  for (int i = hea[x]; i; i = nex[i]) {
    dfs(wen[i]);
    size[x] += size[wen[i]];
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  a[n + 1] = n + 1;
  ++n;
  for (int i = 1; i <= n; i++) {
    while (top && a[sta[top]] < a[i]) add(i, sta[top--]);
    sta[++top] = i;
  }
  dfs(n);
  for (int i = 1; i <= m; i++)
    st.update(1, n, 1, dfn[i], dfn[i] + size[i] - 1, 1);
  printf("%d", st.a[1]);
  for (int i = m + 1; i < n; i++) {
    st.update(1, n, 1, dfn[i], dfn[i] + size[i] - 1, 1);
    st.update(1, n, 1, dfn[i - m], dfn[i - m] + size[i - m] - 1, -1);
    printf(" %d", st.a[1]);
  }
  return 0;
}
