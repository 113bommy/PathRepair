#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 4000;
const int MOD = 998244353;
const int MAXLEN = 75 / 2;
void inc(int &a, int b) {
  if ((a += b) >= MOD) a -= MOD;
}
struct G {
  int n;
  vector<int> adj[MAXN];
  int tot[MAXLEN + 1];
  bool alive[MAXN];
  int sz[MAXN];
  int lst[MAXN], nlst;
  int id[MAXN], par[MAXN];
  int d1[MAXN][2 * MAXLEN + 1];
  int d2[MAXN][2 * MAXLEN + 1];
  void dfslst(int at) {
    id[at] = nlst;
    lst[nlst++] = at;
    for (int i = (0); i < (((int)(adj[at]).size())); ++i) {
      int to = adj[at][i];
      if (to == par[at] || !alive[to]) continue;
      par[to] = at;
      dfslst(to);
    }
  }
  void process(int cent) {
    nlst = 0;
    par[cent] = -1;
    dfslst(cent);
    for (int i = (0); i < (n); ++i)
      d1[i][0] = d2[i][0] = lst[i] == cent ? 1 : 0;
    for (int k = (1); k <= (2 * MAXLEN); ++k) {
      for (int i = (0); i < (nlst); ++i) {
        d1[i][k] = d2[i][k] = 0;
        int at = lst[i];
        for (int j = (0); j < (((int)(adj[at]).size())); ++j) {
          int to = adj[at][j];
          if (!alive[to]) continue;
          if (at != cent) inc(d1[i][k], d1[id[to]][k - 1]);
          inc(d2[i][k], d2[id[to]][k - 1]);
        }
      }
    }
    for (int i = (0); i < (nlst); ++i)
      for (int k1 = (0); k1 <= (2 * MAXLEN); ++k1)
        for (int k2 = (0); k2 <= (2 * MAXLEN - k1); ++k2)
          if ((k1 + k2) % 2 == 0) {
            int k = (k1 + k2) / 2;
            tot[k] = (tot[k] + (long long)d1[i][k1] * d2[i][k2]) % MOD;
          }
  }
  void dfssz(int at, int par) {
    sz[at] = 1;
    for (int i = (0); i < (((int)(adj[at]).size())); ++i) {
      int to = adj[at][i];
      if (to == par || !alive[to]) continue;
      dfssz(to, at);
      sz[at] += sz[to];
    }
  }
  int dfscentroid(int at, int par, int rootsz) {
    for (int i = (0); i < (((int)(adj[at]).size())); ++i) {
      int to = adj[at][i];
      if (to == par || !alive[to]) continue;
      if (2 * sz[to] > rootsz) return dfscentroid(to, at, rootsz);
    }
    return at;
  }
  int centroid(int root) {
    dfssz(root, -1);
    return dfscentroid(root, -1, sz[root]);
  }
  void decompose(int root) {
    int cent = centroid(root);
    process(cent);
    alive[cent] = false;
    for (int i = (0); i < (((int)(adj[cent]).size())); ++i) {
      int to = adj[cent][i];
      if (!alive[to]) continue;
      decompose(to);
    }
  }
  void calc() {
    for (int i = (0); i < (n); ++i) alive[i] = true;
    decompose(0);
  }
};
G a, b;
int len;
int C[2 * MAXLEN + 1][2 * MAXLEN + 1];
void run() {
  for (int i = (0); i <= (2 * MAXLEN); ++i) {
    C[i][0] = C[i][i] = 1;
    for (int j = (1); j < (i); ++j)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
  }
  scanf("%d%d%d", &a.n, &b.n, &len);
  for (int i = (0); i < (a.n - 1); ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u, --v;
    a.adj[u].push_back(v), a.adj[v].push_back(u);
  }
  for (int i = (0); i < (b.n - 1); ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u, --v;
    b.adj[u].push_back(v), b.adj[v].push_back(u);
  }
  if (len % 2 != 0) {
    printf("0\n");
    return;
  } else
    len /= 2;
  a.calc();
  b.calc();
  int ret = 0;
  for (int k = (0); k <= (len); ++k)
    ret =
        (ret + (long long)a.tot[k] * b.tot[len - k] % MOD * C[2 * len][2 * k]) %
        MOD;
  printf("%d\n", ret);
}
int main() {
  run();
  return 0;
}
