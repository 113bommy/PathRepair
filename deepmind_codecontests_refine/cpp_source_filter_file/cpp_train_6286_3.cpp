#include <bits/stdc++.h>
using namespace std;
int n;
typedef struct $ {
  int pa[501];
  int siz[501];
  int conn;
  void init() {
    int i;
    for (i = 1; i <= n; i++) {
      pa[i] = i;
      siz[i] = 1;
    }
    conn = n;
  }
  int findparent(int v) {
    while (v != pa[v]) {
      pa[v] = pa[pa[v]];
      v = pa[v];
    }
    return v;
  }
  void merge(int a, int b) {
    a = findparent(a);
    b = findparent(b);
    if (a == b) return;
    conn--;
    if (siz[a] < siz[b]) {
      swap(a, b);
    }
    pa[b] = a;
    siz[a] += siz[b];
    siz[b] = 0;
  }
} dsu;
dsu pref[10001], suf[10001];
int l[10001], r[10001];
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int m;
  cin >> n >> m;
  int i, u, v;
  for (i = 1; i <= m; i++) {
    cin >> l[i] >> r[i];
  }
  pref[0].init();
  suf[m + 1].init();
  for (i = 1; i <= m; i++) {
    pref[i] = pref[i - 1];
    pref[i].merge(l[i], r[i]);
  }
  for (i = m; i >= 1; i--) {
    suf[i] = suf[i + 1];
    suf[i].merge(l[i], r[i]);
  }
  int q, L, R;
  cin >> q;
  while (q--) {
    cin >> L >> R;
    dsu ans = pref[L - 1];
    for (i = 1; i <= n; i++) {
      ans.merge(i, suf[R + 1].findparent(i));
    }
    cout << ans.conn << '\n';
  }
  return 0;
}
