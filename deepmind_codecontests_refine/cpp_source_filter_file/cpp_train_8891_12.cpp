#include <bits/stdc++.h>
using namespace std;
vector<int> adj[200000];
int n, m, ar[200000], cnt;
int L[200000], R[200000], lev[200000];
int tree[2][200000 * 4];
void read() {
  int a, b;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", ar + i);
  for (int i = 1; i < n; i++) {
    scanf("%d %d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  return;
}
void update(int *tree, int ind, int bas, int son, int a, int b, int val) {
  if (son < a || bas > b) return;
  if (a <= bas && b >= son) {
    tree[ind] += val;
    return;
  }
  int ort = (bas + son) >> 1;
  update(tree, ((ind) << 1), bas, ort, a, b, val);
  update(tree, (((ind) << 1) | 1), ort + 1, son, a, b, val);
  return;
}
int find(int *tree, int ind, int bas, int son, int a) {
  if (son < a || bas > a) return 0;
  if (bas == son) return tree[ind];
  int ort = (bas + son) >> 1;
  int t1 = find(tree, ((ind) << 1), bas, ort, a);
  int t2 = find(tree, (((ind) << 1) | 1), ort + 1, son, a);
  return t1 + t2 + tree[ind];
}
void gen(int nod) {
  int i, b;
  L[nod] = ++cnt;
  for (i = 0; i < adj[nod].size(); i++) {
    b = adj[nod][i];
    if (L[b] == 0) {
      lev[b] = lev[nod] + 1;
      gen(b);
    }
  }
  R[nod] = cnt;
  return;
}
void solve() {
  int q, x, t, val;
  lev[1] = 1;
  gen(1);
  while (m--) {
    scanf("%d", &q);
    if (q == 1) {
      scanf("%d %d", &x, &val);
      update(tree[lev[x] & 1], 1, 1, n, L[x], R[x], val);
    } else {
      scanf("%d", &x);
      t = lev[x] & 1;
      printf("%d\n", ar[x] + find(tree[t], 1, 1, n, L[x]) -
                         find(tree[!t], 1, 1, n, L[x]));
    }
  }
  return;
}
int main() {
  read();
  solve();
  return 0;
}
