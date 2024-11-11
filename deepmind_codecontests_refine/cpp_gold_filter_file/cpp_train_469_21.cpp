#include <bits/stdc++.h>
using namespace std;
struct node {
  int id, v;
} tree[4 * 100005];
int in[100005];
void build(int nod, int s, int e) {
  if (s == e) {
    tree[nod].id = s;
    tree[nod].v = in[s];
    return;
  }
  int mid = (s + e) / 2, l = 2 * nod, r = l + 1;
  build(l, s, mid);
  build(r, mid + 1, e);
  if (tree[l].v > tree[r].v) {
    tree[nod].v = tree[l].v;
    tree[nod].id = tree[l].id;
  } else {
    tree[nod].v = tree[r].v;
    tree[nod].id = tree[r].id;
  }
}
pair<int, int> query(int nod, int s, int e, int i, int j) {
  if (s > j || e < i) return {-1, -1};
  if (s >= i && e <= j) return {tree[nod].v, tree[nod].id};
  int mid = (s + e) / 2, l = 2 * nod, r = l + 1;
  pair<int, int> a = query(l, s, mid, i, j);
  pair<int, int> b = query(r, mid + 1, e, i, j);
  if (a.first > b.first)
    return a;
  else
    return b;
}
long long save[100005];
long long ans[100005];
int main() {
  int n, i;
  scanf("%d", &n);
  for (i = 1; i < n; i++) {
    scanf("%d", &in[i]);
  }
  build(1, 1, n);
  save[n - 1] = 1;
  ans[n - 1] = 1;
  pair<int, int> a = query(1, 1, n, 6, 8);
  for (i = n - 2; i >= 1; i--) {
    pair<int, int> pp = query(1, 1, n, i + 1, in[i]);
    save[i] = pp.second - i + save[pp.second] + n - in[i];
    ans[i] = ans[i + 1] + save[i];
  }
  printf("%I64d\n", ans[1]);
}
