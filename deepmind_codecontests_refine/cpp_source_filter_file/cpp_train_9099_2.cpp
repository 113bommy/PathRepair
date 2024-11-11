#include <bits/stdc++.h>
using namespace std;
int Log2[110005];
set<int> iset;
struct node {
  int idx, l, r, x;
  node(){};
  node(int a, int b, int c, int d) : idx(a), l(b), r(c), x(d){};
};
void Jireh(vector<node> &v, int L, int R) {
  int i, l, r;
  for (i = 0; i < ((int)(v).size()); i++) {
    l = v[i].l, r = v[i].r;
    if ((l >= L && l <= R) || (r >= L && r <= R) || (L >= l && L <= r) ||
        (R >= l && R <= r))
      iset.insert(v[i].x);
  }
}
void pre(int limit) {
  int i;
  Log2[1] = 1;
  for (i = 2; i <= limit; i++) Log2[i] = Log2[i - 1] + !(i & (i - 1));
}
int main() {
  pre(110000);
  int i, j, n, m, op, idx, l, r, x, L, R;
  vector<node> level[7005];
  while (scanf("%d %d", &n, &m) != EOF) {
    for (i = 1; i <= n; i++) (level[i]).clear();
    for (i = 1; i <= m; i++) {
      scanf("%d", &op);
      if (op == 1) {
        scanf("%d %d %d %d", &idx, &l, &r, &x);
        level[idx].push_back(node(idx, l, r, x));
      } else {
        (iset).clear();
        scanf("%d %d", &idx, &x);
        L = R = x;
        for (j = idx; j <= n; j++) {
          Jireh(level[j], L, R);
          L -= Log2[L - 1];
          R += Log2[R];
        }
        printf("%d\n", ((int)(iset).size()));
      }
    }
  }
  return 0;
}
