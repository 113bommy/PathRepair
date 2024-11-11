#include <bits/stdc++.h>
using namespace std;
vector<int> vt[100005];
int Time[100005 * 2];
int tree[100005 * 35], lchild[100005 * 35], rchild[100005 * 35], root[100005],
    tot;
void insert(int last, int cur, int x, int L, int R, int k) {
  tree[cur] = tree[last] + k;
  lchild[cur] = lchild[last];
  rchild[cur] = rchild[last];
  if (L == R) return;
  int mid = L + R >> 1;
  if (x <= mid)
    insert(lchild[last], lchild[cur] = ++tot, x, L, mid, k);
  else
    insert(rchild[last], rchild[cur] = ++tot, x, mid + 1, R, k);
}
int query(int l, int r, int L, int R, int root) {
  if (l <= L && R <= r) return tree[root];
  int mid = L + R >> 1;
  if (r <= mid)
    return query(l, r, L, mid, lchild[root]);
  else if (l > mid)
    return query(l, r, mid + 1, R, rchild[root]);
  else
    return query(l, mid, L, mid, lchild[root]) +
           query(mid + 1, r, mid + 1, R, rchild[root]);
}
int main() {
  int n, k, q, top = 0, x;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    vt[x].push_back(i);
    insert(Time[top], Time[top + 1] = ++tot, i, 1, n, 1), top++;
    if (vt[x].size() > k)
      insert(Time[top], Time[top + 1] = ++tot, vt[x][vt[x].size() - k - 1], 1,
             n, -1),
          top++;
    root[i] = Time[top];
  }
  int last = 0;
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    l = (l + last) % n + 1;
    r = (r + last) % n + 1;
    if (l > r) swap(l, r);
    last = query(l, r, 1, n, root[r]);
    printf("%d\n", last);
  }
}
