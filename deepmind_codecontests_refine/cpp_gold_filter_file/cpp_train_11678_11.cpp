#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
long long arr[N];
long long cum[N];
long long seg[4 * N], lazy[4 * N], tmp[4 * N];
int n;
void build(int ind = 0, int ns = 0, int ne = n - 1) {
  if (ns == ne) {
    seg[ind] = cum[ns];
    return;
  }
  int mid = ns + (ne - ns) / 2;
  int lf = ind * 2 + 1, rt = lf + 1;
  build(lf, ns, mid);
  build(rt, mid + 1, ne);
  seg[ind] = max(seg[lf], seg[rt]);
}
void propagate(int id, int ns, int ne) {
  int mid = ns + (ne - ns) / 2;
  int lf = (id << 1) + 1, rt = lf + 1;
  if (ns == ne) return;
  seg[lf] += lazy[id];
  lazy[lf] += lazy[id];
  seg[rt] += lazy[id];
  lazy[rt] += lazy[id];
  lazy[id] = 0;
}
long long query(int qs, int qe, int ind = 0, int ns = 0, int ne = n - 1) {
  if (ns > qe || ne < qs) return -1e18;
  propagate(ind, ns, ne);
  if (qs <= ns && ne <= qe) return seg[ind];
  int mid = ns + (ne - ns) / 2;
  int lf = ind * 2 + 1, rt = lf + 1;
  long long x = query(qs, qe, lf, ns, mid);
  long long y = query(qs, qe, rt, mid + 1, ne);
  return max(x, y);
}
void update(int qs, int qe, int v, int ind = 0, int ns = 0, int ne = n - 1) {
  if (ns > qe || ne < qs) return;
  propagate(ind, ns, ne);
  if (qs <= ns && ne <= qe) {
    lazy[ind] += v;
    seg[ind] += v;
    return;
  }
  int mid = ns + (ne - ns) / 2;
  int lf = ind * 2 + 1, rt = lf + 1;
  update(qs, qe, v, lf, ns, mid);
  update(qs, qe, v, rt, mid + 1, ne);
  seg[ind] = max(seg[lf], seg[rt]);
}
int main() {
  int m, kk;
  scanf("%d %d %d", &n, &m, &kk);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", arr + i);
  }
  for (int i = 1; i <= n; i++) {
    cum[i] = cum[i - 1] + arr[i];
  }
  n++;
  build();
  memcpy(tmp, seg, sizeof(seg));
  long long res = 0;
  for (int j = 0; j < m; j++) {
    memcpy(seg, tmp, sizeof(tmp));
    memset(lazy, 0, sizeof(lazy));
    for (int k = n - 1; k >= j + 1; k--) {
      if ((k - 1) % m == j) {
        update(k, n, -kk);
        long long q = query(k, n);
        res = max(res, q - cum[k - 1]);
      }
    }
  }
  printf("%lld\n", res);
  return 0;
}
