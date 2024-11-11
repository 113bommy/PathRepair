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
  int par[MAXN];
  int waysdown[MAXN][MAXLEN + 1];
  int waysup[MAXN][MAXLEN + 1];
  int sumways[MAXN][MAXLEN + 1];
  int tot[MAXLEN + 1];
  int one[MAXLEN + 1];
  int many[MAXLEN + 1];
  void calcmany() {
    assert(one[0] == 0);
    for (int k = (0); k <= (MAXLEN); ++k) many[k] = k == 0 ? 1 : 0;
    for (int rep = (0); rep < (MAXLEN); ++rep)
      for (int i = MAXLEN; i >= 0; --i) {
        for (int j = (1); j <= (MAXLEN - i); ++j)
          many[i + j] = (many[i + j] + (long long)many[i] * one[j]);
        many[i] = i == 0 ? 1 : 0;
      }
  }
  void dfsinit(int at) {
    for (int i = (0); i < (((int)(adj[at]).size())); ++i) {
      int to = adj[at][i];
      if (to == par[at]) continue;
      par[to] = at;
      dfsinit(to);
    }
  }
  void calcdown(int at) {
    for (int k = (0); k <= (MAXLEN); ++k) sumways[at][k] = 0;
    for (int i = (0); i < (((int)(adj[at]).size())); ++i) {
      int to = adj[at][i];
      if (to == par[at]) continue;
      calcdown(to);
      for (int k = (0); k <= (MAXLEN); ++k)
        inc(sumways[at][k], waysdown[to][k]);
    }
    if (par[at] != -1) {
      for (int k = (0); k <= (MAXLEN); ++k) one[k] = sumways[at][k];
      calcmany();
      for (int k = (0); k <= (MAXLEN); ++k)
        waysdown[at][k] = k == 0 ? 0 : many[k - 1];
    }
  }
  void calcup(int at) {
    if (par[at] != -1) {
      for (int k = (0); k <= (MAXLEN); ++k)
        one[k] = (sumways[par[at]][k] + MOD - waysdown[at][k]) % MOD;
      calcmany();
      for (int k = (0); k <= (MAXLEN); ++k)
        waysup[at][k] = k == 0 ? 0 : many[k - 1];
      for (int k = (0); k <= (MAXLEN); ++k) inc(sumways[at][k], waysup[at][k]);
    }
    for (int i = (0); i < (((int)(adj[at]).size())); ++i) {
      int to = adj[at][i];
      if (to == par[at]) continue;
      calcup(to);
    }
  }
  void calc() {
    par[0] = -1;
    dfsinit(0);
    calcdown(0);
    calcup(0);
    for (int k = (0); k <= (MAXLEN); ++k) tot[k] = 0;
    for (int at = (0); at < (n); ++at) {
      for (int k = (0); k <= (MAXLEN); ++k) one[k] = sumways[at][k];
      calcmany();
      for (int k = (0); k <= (MAXLEN); ++k) inc(tot[k], many[k]);
    }
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
