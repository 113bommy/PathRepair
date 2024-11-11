#include <bits/stdc++.h>
using namespace std;
const int me = 20;
struct GaussXOR {
  int table[me];
  GaussXOR() {
    for (int i = 0; i < me; i++) {
      table[i] = 0;
    }
  }
  int size() {
    int ans = 0;
    for (int i = 0; i < me; i++) {
      if (table[i]) ans++;
    }
    return ans;
  }
  bool is_comb(int x) {
    for (int i = me - 1; i >= 0; i--) {
      x = std::min(x, x ^ table[i]);
    }
    return x == 0;
  }
  void add(int x) {
    for (int i = me - 1; i >= 0; i--) {
      if ((table[i] == 0) and (x & (1 << i))) {
        table[i] = x;
        x = 0;
      } else {
        x = std::min(x, x ^ table[i]);
      }
    }
  }
  int max() {
    int ans = 0;
    for (int i = me - 1; i >= 0; i--) {
      ans = std::max(ans, ans ^ table[i]);
    }
    return ans;
  }
};
int v[500010];
struct Q {
  int l, r, id;
};
GaussXOR ans[500010];
GaussXOR temp[500010];
void build(int i, int j, vector<Q> query) {
  if ((j - i + 1) <= 20) {
    for (Q aux : query) {
      for (int x = aux.l; x <= aux.r; x++) ans[aux.id].add(v[x]);
    }
    return;
  }
  int m = (i + j) / 2;
  GaussXOR g = GaussXOR();
  for (int x = m; x >= i; x--) {
    g.add(v[x]);
    temp[i] = g;
  }
  g = GaussXOR();
  for (int x = m + 1; x <= j; x++) {
    g.add(v[x]);
    temp[i] = g;
  }
  vector<Q> vl, vr;
  for (Q aux : query) {
    if (aux.r <= m) {
      vl.push_back(aux);
    } else if (aux.l >= (m + 1)) {
      vr.push_back(aux);
    } else {
      for (int x = 0; x < me; x++) {
        ans[aux.id].add(temp[aux.l].table[x]);
        ans[aux.id].add(temp[aux.r].table[x]);
      }
    }
  }
  query.clear();
  build(i, m, vl);
  build(m + 1, j, vr);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
  }
  int q;
  scanf("%d", &q);
  vector<Q> query(q);
  for (int i = 0; i < q; i++) {
    scanf("%d %d", &query[i].l, &query[i].r);
    query[i].id = i;
  }
  build(1, n, query);
  for (int i = 0; i < q; i++) {
    printf("%d\n", ans[i].max());
  }
  return 0;
}
