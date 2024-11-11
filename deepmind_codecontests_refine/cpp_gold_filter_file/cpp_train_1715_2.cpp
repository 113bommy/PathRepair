#include <bits/stdc++.h>
using namespace std;
int dsu[200005];
long long f[200005];
long long lf[200005];
int getgp(int u) {
  if (dsu[u] == 0)
    return u;
  else
    return dsu[u] = getgp(dsu[u]);
}
void bind(int u, int v) {
  u = getgp(u);
  v = getgp(v);
  if (u == v) return;
  dsu[u] = v;
}
struct Query {
  int l, r;
};
Query query[200005];
int idx[200005];
long long h[200005];
long long ans[200005];
int cmp(int a, int b) { return query[a].l > query[b].l; }
int stk[200005];
int top = -1;
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%I64d%I64d", lf + i, h + i);
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    scanf("%d%d", &query[i].l, &query[i].r);
    idx[i] = i;
  }
  sort(idx, idx + q, cmp);
  f[n] = 0;
  stk[++top] = n;
  int j = 0;
  for (int i = n - 1; i > 0; --i) {
    long long rf = -1e9 - 10;
    while (top >= 0 && lf[stk[top]] <= lf[i] + h[i]) {
      rf = f[stk[top]];
      bind(stk[top], i);
      --top;
    }
    int u = getgp(i);
    stk[++top] = u;
    lf[u] = lf[i];
    if (top > 0) {
      rf = max(rf, f[stk[top - 1]] + lf[i] + h[i] - lf[stk[top - 1]]);
    }
    f[u] = rf;
    while (j < q && query[idx[j]].l == i) {
      ans[idx[j]] = f[getgp(query[idx[j]].r)] - f[getgp(query[idx[j]].l)];
      ++j;
    }
  }
  for (int i = 0; i < q; ++i) {
    printf("%d\n", ans[i]);
  }
}
int main() {
  solve();
  return 0;
}
