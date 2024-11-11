#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXH = 300;
const int MAXW = 300;
const int MAXN = MAXH * MAXW;
const int MAXQ = 2000000;
const int MAXV = 2000000;
const int DX[] = {-1, 0, +1, 0}, DY[] = {0, +1, 0, -1};
struct E {
  int t, z;
  E() {}
  E(int t, int z) : t(t), z(z) {}
};
int h, w, nq;
int qx[MAXQ], qy[MAXQ], qv[MAXQ], qans[MAXQ];
int g[MAXH][MAXW];
vector<E> added[MAXV + 1];
vector<E> removed[MAXV + 1];
int n;
int id[MAXH][MAXW];
vector<int> adj[MAXN];
bool alive[MAXN];
int ufpar[MAXN], ufsz[MAXN];
int delta[MAXQ + 1];
int uffind(int x) {
  if (ufpar[x] == x) return x;
  return ufpar[x] = uffind(ufpar[x]);
}
bool ufunite(int x, int y) {
  x = uffind(x), y = uffind(y);
  if (x == y) return false;
  if (ufsz[x] < ufsz[y]) swap(x, y);
  ufpar[y] = x, ufsz[x] += ufsz[y];
  return true;
}
void solve() {
  n = h * w;
  for (int x = (0); x < (h); ++x)
    for (int y = (0); y < (w); ++y) id[x][y] = x * w + y;
  for (int i = (0); i < (n); ++i) adj[i].clear();
  for (int x = (0); x < (h); ++x)
    for (int y = (0); y < (w); ++y)
      for (int k = (0); k < (4); ++k) {
        int nx = x + DX[k], ny = y + DY[k];
        if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        adj[id[x][y]].push_back(id[nx][ny]);
      }
  for (int x = (0); x < (h); ++x)
    for (int y = (0); y < (w); ++y) g[x][y] = 0;
  for (int x = (0); x < (h); ++x)
    for (int y = (0); y < (w); ++y) added[g[x][y]].push_back(E(-1, id[x][y]));
  for (int i = (0); i < (nq); ++i) {
    int x = qx[i], y = qy[i], v = qv[i];
    if (g[x][y] == v) continue;
    removed[g[x][y]].push_back(E(i, id[x][y]));
    g[x][y] = v;
    added[g[x][y]].push_back(E(i, id[x][y]));
  }
  for (int x = (0); x < (h); ++x)
    for (int y = (0); y < (w); ++y) removed[g[x][y]].push_back(E(nq, id[x][y]));
  for (int i = (0); i < (n); ++i) alive[i] = false;
  for (int i = (0); i <= (nq); ++i) delta[i] = 0;
  for (int v = (0); v <= (MAXV); ++v) {
    int ncomp = 0;
    for (int i = (0); i < (((int)(added[v]).size())); ++i) {
      int ocomp = ncomp, t = added[v][i].t, at = added[v][i].z;
      assert(!alive[at]);
      alive[at] = true, ufpar[at] = at, ufsz[at] = 1, ++ncomp;
      for (int j = (0); j < (((int)(adj[at]).size())); ++j) {
        int to = adj[at][j];
        if (!alive[to]) continue;
        if (ufunite(at, to)) --ncomp;
      }
      delta[max(t, 0)] += ncomp - ocomp;
    }
    for (int i = (0); i < (((int)(added[v]).size())); ++i)
      alive[added[v][i].z] = false;
    ncomp = 0;
    for (int i = ((int)(removed[v]).size()) - 1; i >= 0; --i) {
      int ocomp = ncomp, t = removed[v][i].t, at = removed[v][i].z;
      assert(!alive[at]);
      alive[at] = true, ufpar[at] = at, ufsz[at] = 1, ++ncomp;
      for (int j = (0); j < (((int)(adj[at]).size())); ++j) {
        int to = adj[at][j];
        if (!alive[to]) continue;
        if (ufunite(at, to)) --ncomp;
      }
      delta[max(t, 0)] -= ncomp - ocomp;
    }
    for (int i = (0); i < (((int)(removed[v]).size())); ++i)
      alive[removed[v][i].z] = false;
  }
  qans[0] = delta[0];
  for (int i = (1); i < (nq); ++i) qans[i] = qans[i - 1] + delta[i];
}
void run() {
  scanf("%d%d%d", &h, &w, &nq);
  for (int i = (0); i < (nq); ++i)
    scanf("%d%d%d", &qx[i], &qy[i], &qv[i]), --qx[i], --qy[i];
  solve();
  for (int i = (0); i < (nq); ++i) printf("%d\n", qans[i]);
}
int main() {
  run();
  return 0;
}
