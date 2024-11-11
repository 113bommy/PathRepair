#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
int aux = -1;
int ind[MAXN], ent[MAXN], visit[MAXN];
vector<int> lig[MAXN];
struct no {
  int esq, dir;
  int h;
  int v, val;
};
no vet[MAXN];
struct node {
  int sum_par, sum_impar;
};
node tree[4 * MAXN], lazy[4 * MAXN];
node operator+(node a, node b) {
  node r;
  r.sum_impar = a.sum_impar + b.sum_impar;
  r.sum_par = a.sum_par + b.sum_par;
  return r;
}
void dfs(int i, int pai) {
  if (visit[i] == 1) return;
  visit[i] = 1;
  aux++;
  ind[i] = aux;
  vet[aux].v = i;
  vet[aux].esq = aux;
  vet[aux].val = ent[i];
  if (i != 0) vet[aux].h = vet[ind[pai]].h + 1;
  int t = lig[i].size();
  for (int j = 0; j < t; j++) dfs(lig[i][j], i);
  vet[ind[i]].dir = aux;
}
void build(int i, int l, int r) {
  lazy[i].sum_par = 0;
  lazy[i].sum_impar = 0;
  if (l == r) {
    tree[i].sum_par = 0;
    tree[i].sum_impar = 0;
  } else {
    int L = 2 * i + 1, R = 2 * i + 2, mid = (l + r) / 2;
    build(L, l, mid);
    build(R, mid + 1, r);
    tree[i] = tree[L] + tree[R];
  }
}
void refresh(int i, int l, int r) {
  tree[i].sum_par += lazy[i].sum_par;
  tree[i].sum_impar += lazy[i].sum_impar;
  if (l != r) {
    lazy[2 * i + 1].sum_impar += lazy[i].sum_impar;
    lazy[2 * i + 1].sum_par += lazy[i].sum_par;
    lazy[2 * i + 2].sum_impar += lazy[i].sum_impar;
    lazy[2 * i + 2].sum_par += lazy[i].sum_par;
  }
  lazy[i].sum_impar = 0;
  lazy[i].sum_par = 0;
}
void update(int i, int l, int r, int ql, int qr, int vert, int val) {
  refresh(i, l, r);
  if (ql > r || l > qr) return;
  if (ql <= l && r <= qr) {
    if (vet[ind[vert]].h % 2 == 0) {
      lazy[i].sum_par += val;
      lazy[i].sum_impar -= val;
    } else {
      lazy[i].sum_par -= val;
      lazy[i].sum_impar += val;
    }
    refresh(i, l, r);
    return;
  }
  int L = 2 * i + 1, R = 2 * i + 2, mid = (l + r) / 2;
  update(L, l, mid, ql, qr, vert, val);
  update(R, mid + 1, r, ql, qr, vert, val);
}
int query(int i, int l, int r, int vert) {
  refresh(i, l, r);
  if (l > ind[vert] || r < ind[vert]) return 0;
  if (l == r) {
    if (vet[ind[vert]].h % 2 == 0)
      return vet[ind[vert]].val + tree[i].sum_par;
    else
      return vet[ind[vert]].val + tree[i].sum_impar;
  }
  int L = 2 * i + 1, R = 2 * i + 2, mid = (l + r) / 2;
  if (ind[vert] > mid)
    return query(R, mid + 1, r, vert);
  else
    return query(L, l, mid, vert);
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &ent[i]);
  int u, v;
  for (int i = 0; i < n - 1; i++) {
    scanf("%d %d", &u, &v);
    lig[u - 1].push_back(v - 1);
    lig[v - 1].push_back(u - 1);
  }
  vet[0].h = 0;
  dfs(0, 0);
  build(0, 0, n - 1);
  int op, a, b;
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &op, &a);
    if (op == 1) {
      scanf("%d", &b);
      update(0, 0, n - 1, vet[ind[a - 1]].esq, vet[ind[a - 1]].dir, a - 1, b);
    } else {
      int resp = query(0, 0, n - 1, a - 1);
      printf("%d\n", resp);
    }
  }
}
