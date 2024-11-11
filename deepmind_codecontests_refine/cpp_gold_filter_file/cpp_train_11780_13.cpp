#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 200000;
const int MAX_M = 200000;
const int MAX_E2 = 1 << 19;
const int BN = 18;
const int INF = 1 << 30;
template <typename T, const int MAX_E2>
struct SegTreeMin {
  int e2;
  T nodes[MAX_E2], inf;
  SegTreeMin() {}
  void init(int n, T _inf) {
    inf = _inf;
    for (e2 = 1; e2 < n; e2 <<= 1)
      ;
    fill(nodes, nodes + MAX_E2, inf);
  }
  T &geti(int i) { return nodes[e2 - 1 + i]; }
  void seti(int i, T v) { geti(i) = v; }
  void setall() {
    for (int j = e2 - 2; j >= 0; j--)
      nodes[j] = min(nodes[j * 2 + 1], nodes[j * 2 + 2]);
  }
  void set(int i, T v) {
    int j = e2 - 1 + i;
    nodes[j] = v;
    while (j > 0) {
      j = (j - 1) / 2;
      nodes[j] = min(nodes[j * 2 + 1], nodes[j * 2 + 2]);
    }
  }
  T min_range(int r0, int r1, int k, int i0, int i1) {
    if (r1 <= i0 || i1 <= r0) return inf;
    if (r0 <= i0 && i1 <= r1) return nodes[k];
    int im = (i0 + i1) / 2;
    T v0 = min_range(r0, r1, k * 2 + 1, i0, im);
    T v1 = min_range(r0, r1, k * 2 + 2, im, i1);
    return min(v0, v1);
  }
  T min_range(int r0, int r1) { return min_range(r0, r1, 0, 0, e2); }
};
int pts[MAX_N], as[MAX_M], nxts[MAX_N], pos[MAX_N];
int ps[MAX_M][BN], ds[MAX_M];
SegTreeMin<int, MAX_E2> st;
int ancestor(int u, int d) {
  if (ds[u] < d) return -1;
  for (int i = BN - 1; i >= 0; i--)
    if ((d >> i) & 1) u = ps[u][i];
  return u;
}
int main() {
  int n, m, qn;
  scanf("%d%d%d", &n, &m, &qn);
  for (int i = 0; i < n; i++) scanf("%d", pts + i), pts[i]--;
  for (int i = 0; i < m; i++) scanf("%d", as + i), as[i]--;
  for (int i = 0; i < n; i++) {
    int p0 = pts[i], p1 = pts[(i + 1) % n];
    nxts[p0] = p1;
  }
  memset(pos, -1, sizeof(pos));
  for (int u = m - 1; u >= 0; u--) {
    pos[as[u]] = u;
    int v = pos[nxts[as[u]]];
    ps[u][0] = v;
    ds[u] = (v < 0) ? 0 : ds[v] + 1;
  }
  for (int i = 0; i < BN - 1; i++)
    for (int u = 0; u < m; u++)
      ps[u][i + 1] = (ps[u][i] >= 0) ? ps[ps[u][i]][i] : -1;
  st.init(m, INF);
  for (int u = 0; u < m; u++) {
    int v = ancestor(u, n - 1);
    st.seti(u, (v >= 0) ? v : INF);
  }
  st.setall();
  while (qn--) {
    int l, r;
    scanf("%d%d", &l, &r);
    l--;
    int v = st.min_range(l, r);
    if (v < r)
      putchar('1');
    else
      putchar('0');
  }
  putchar('\n');
  return 0;
}
