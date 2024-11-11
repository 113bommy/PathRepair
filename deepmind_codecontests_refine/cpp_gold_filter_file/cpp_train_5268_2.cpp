#include <bits/stdc++.h>
using namespace std;
const int MAXN = 11;
const int MAXM = 100010;
struct node {
  int l[MAXN], r[MAXN], qtd;
  node() { qtd = 0; }
};
int v[MAXN][MAXM];
int n;
node t[4 * MAXM];
int aux[5 * MAXN];
void mapdown(node& n1) {
  for (int i = 0; i < (n); ++i) {
    aux[i] = n1.l[i];
    aux[i + n] = n1.r[i];
  }
  sort(aux, aux + 2 * n);
  int sz = unique(aux, aux + 2 * n) - aux;
  for (int i = 0; i < (n); ++i) {
    n1.l[i] = lower_bound(aux, aux + sz, n1.l[i]) - aux;
    n1.r[i] = lower_bound(aux, aux + sz, n1.r[i]) - aux;
  }
}
node merge(node n1, node n2, int l, int r) {
  if (!n1.qtd) return n2;
  if (!n2.qtd) return n1;
  mapdown(n1);
  mapdown(n2);
  for (int i = 0; i < (n); ++i) {
    n2.l[i] += 2 * n;
    n2.r[i] += 2 * n;
  }
  node ans;
  ans.qtd = n1.qtd + n2.qtd;
  auto& v1 = n1.r;
  auto& v2 = n2.l;
  for (int i = 0; i < (n); ++i)
    if (v[i][l] == v[i][r] && v1[i] != v2[i]) {
      --ans.qtd;
      int looking = max(v1[i], v2[i]);
      int newv = min(v1[i], v2[i]);
      for (int j = 0; j < (n); ++j) {
        if (n1.l[j] == looking) n1.l[j] = newv;
        if (n1.r[j] == looking) n1.r[j] = newv;
        if (n2.l[j] == looking) n2.l[j] = newv;
        if (n2.r[j] == looking) n2.r[j] = newv;
      }
    }
  for (int i = 0; i < (n); ++i) {
    ans.l[i] = n1.l[i];
    ans.r[i] = n2.r[i];
  }
  return ans;
}
void build(int idx, int l, int r) {
  if (l == r) {
    t[idx].qtd = 1;
    t[idx].l[0] = t[idx].r[0] = 0;
    for (int i = 1; i < (n); ++i) {
      if (v[i][l] != v[i - 1][l]) {
        ++t[idx].qtd;
      }
      t[idx].l[i] = t[idx].r[i] = t[idx].qtd - 1;
    }
    return;
  }
  int m = (l + r) / 2;
  build(2 * idx, l, m);
  build(2 * idx + 1, m + 1, r);
  t[idx] = merge(t[2 * idx], t[2 * idx + 1], m, m + 1);
}
node query(int idx, int l, int r, int x, int y) {
  if (y < l || x > r) return node();
  if (l >= x && r <= y) {
    return t[idx];
  }
  int m = (l + r) / 2;
  node n1 = query(2 * idx, l, m, x, y);
  node n2 = query(2 * idx + 1, m + 1, r, x, y);
  return merge(n1, n2, m, m + 1);
}
int main() {
  int m, q;
  scanf(" %d %d", &(n), &(m));
  scanf(" %d", &(q));
  for (int i = 0; i < (n); ++i)
    for (int j = 0; j < (m); ++j) scanf(" %d", &(v[i][j]));
  build(1, 0, m - 1);
  while (q--) {
    int x, y;
    scanf(" %d %d", &(x), &(y));
    --x;
    --y;
    printf("%d\n", query(1, 0, m - 1, x, y).qtd);
  }
  return 0;
}
