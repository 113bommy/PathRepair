#include <bits/stdc++.h>
using namespace std;
const int N = 500050;
const int inf = 0x3f3f3f3f;
const long long llinf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
clock_t TIME__START, TIME__END;
void program_end() {}
const int BLOCK = 550;
int n, q;
vector<int> e[N];
struct tp3 {
  int v, white, dist;
};
vector<tp3> g[N];
int used[N], black[N], oldc[N];
int d[N], cl[N];
struct querys {
  int type, node;
} Q[N];
void make_g(int u, int fa = 0, int white = 0, int dist = 0) {
  if (used[u]) {
    if (fa) g[fa].push_back({u, white, dist});
    for (auto v : e[u]) make_g(v, u, 0, 0);
  } else {
    if (!black[u]) white++;
    for (auto v : e[u]) make_g(v, u, white, dist + 1);
  }
}
void work1(int u) {
  if (!black[u]) return black[u] = 1, void();
  d[u]++;
  for (auto [v, white, dist] : g[u]) {
    if (white + 1 <= d[u]) work1(v);
  }
}
void work2(int u) {
  d[u] = black[u] = 0, cl[u] = 1;
  for (auto &vv : g[u]) {
    vv.white = vv.dist;
    work2(vv.v);
  }
}
void make_e(int u, int lef, int iscl) {
  if (used[u]) {
    lef = d[u];
    iscl = (iscl | cl[u]);
  } else {
    black[u] = oldc[u];
    if (iscl) black[u] = 0;
    if (!black[u] && lef > 0) {
      lef--;
      black[u] = 1;
    }
  }
  for (auto v : e[u]) make_e(v, lef, iscl);
}
inline void solve() {
  scanf("%d%d", &n, &q);
  for (int i = 2; i <= n; ++i) {
    int p;
    scanf("%d", &p);
    e[p].push_back(i);
  }
  for (int i = 1; i <= q; ++i) scanf("%d%d", &Q[i].type, &Q[i].node);
  for (int ql = 1; ql <= q; ql += BLOCK) {
    int qr = min(q, ql + BLOCK - 1);
    for (int i = 1; i <= n; ++i) {
      g[i].clear(), used[i] = 0;
      oldc[i] = black[i];
      d[i] = cl[i] = 0;
    }
    for (int i = ql; i <= qr; ++i) used[Q[i].node] = 1;
    make_g(1);
    for (int i = ql; i <= qr; ++i) {
      int u = Q[i].node;
      switch (Q[i].type) {
        case 1: {
          work1(u);
          break;
        }
        case 2: {
          work2(u);
          break;
        }
        case 3: {
          puts((black[u]) ? "black" : "white");
          break;
        }
      }
    }
    make_e(1, 0, 0);
  }
}
int main() {
  TIME__START = clock();
  int Test = 1;
  while (Test--) {
    solve();
  }
  TIME__END = clock();
  program_end();
  return 0;
}
