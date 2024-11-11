#include <bits/stdc++.h>
long long int n, m, arr[200000];
long long int tree[400000];
void buildtree(long long int node, long long int st, long long int en,
               long long int flag) {
  if (st == en) {
    tree[node] = arr[st];
    return;
  }
  long long int mid = (st + en) / 2;
  buildtree(node * 2, st, mid, flag ^ 1);
  buildtree(node * 2 + 1, mid + 1, en, flag ^ 1);
  if (flag == 1)
    tree[node] = tree[node * 2] | tree[node * 2 + 1];
  else
    tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
  return;
}
void query(long long int node, long long int st, long long int en,
           long long int flag, long long int pos, long long int val) {
  if (st == en) {
    if (st == pos) tree[node] = val;
    return;
  }
  long long int mid = (st + en) / 2;
  if (pos <= mid)
    query(node * 2, st, mid, flag ^ 1, pos, val);
  else
    query(node * 2 + 1, mid + 1, en, flag ^ 1, pos, val);
  if (flag == 1)
    tree[node] = tree[node * 2] | tree[node * 2 + 1];
  else
    tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
  return;
}
int main() {
  long long int f, i;
  scanf("%lld%lld", &n, &m);
  f = f % n;
  n = (1 << n);
  for (i = 1; i <= n; i++) scanf("%lld", &arr[i]);
  buildtree(1, 1, n, f);
  for (i = 0; i < m; i++) {
    long long int pos, val;
    scanf("%lld %lld", &pos, &val);
    query(1, 1, n, f, pos, val);
    printf("%lld\n", tree[1]);
  }
  return 0;
}
