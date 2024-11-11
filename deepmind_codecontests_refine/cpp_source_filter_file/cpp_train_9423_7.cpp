#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;
long long INF = 1e18;
int n, k, a, b, q, arr[200005] = {}, suma[400010], sumb[400010];
void segbuild(int u = 1, int lo = 0, int hi = n + 1) {
  if (lo == hi) {
    suma[u] = sumb[u] = 0;
  } else {
    int mi = lo + hi >> 1;
    segbuild(u << 1, lo, mi);
    segbuild(u << 1 | 1, mi + 1, hi);
    suma[u] = suma[u << 1] + suma[u << 1 | 1];
    sumb[u] = sumb[u << 1] + sumb[u << 1 | 1];
  }
}
pair<int, int> segquery(int l, int r, int u = 1, int lo = 0, int hi = n + 1) {
  if (l == lo && r == hi) return {suma[u], sumb[u]};
  int mi = lo + hi >> 1;
  if (r <= mi)
    return segquery(l, r, u << 1, lo, mi);
  else if (l > mi)
    return segquery(l, r, u << 1 | 1, mi + 1, hi);
  else {
    pair<int, int> resl = segquery(l, mi, u << 1, lo, mi);
    pair<int, int> resr = segquery(mi + 1, r, u << 1 | 1, mi + 1, hi);
    return {resl.first + resr.first, resl.second + resr.second};
  }
}
void segupdate(int k, int v, int u = 1, int lo = 0, int hi = n + 1) {
  if (lo == hi) {
    suma[u] = min(a, v);
    sumb[u] = min(b, v);
  } else {
    int mi = lo + hi >> 1;
    if (k <= mi)
      segupdate(k, v, u << 1, lo, mi);
    else
      segupdate(k, v, u << 1 | 1, mi + 1, hi);
    suma[u] = suma[u << 1] + suma[u << 1 | 1];
    sumb[u] = sumb[u << 1] + sumb[u << 1 | 1];
  }
}
int solve() {
  cin >> n >> k >> a >> b >> q;
  segbuild();
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int d, v;
      cin >> d >> v;
      arr[d] += v;
      segupdate(d, arr[d]);
    } else {
      int d;
      cin >> d;
      cout << segquery(0, d - 1).second + segquery(d + k, n + 1).first << endl;
    }
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  solve();
  return 0;
}
