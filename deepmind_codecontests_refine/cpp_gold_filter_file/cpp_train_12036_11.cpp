#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 50000;
const int MAXQ = 150000;
const int BITS = 16;
const int LBITS = BITS / 2 - 1;
const int HBITS = BITS - LBITS;
const int STEP = 1 << LBITS;
const int MAXS = (2 << HBITS) - 1;
typedef struct S {
  int c[2], mx;
} S;
int n, nq;
int a[MAXN];
vector<int> adj[MAXN];
vector<pair<int, int> > q[MAXN];
int ans[MAXQ];
int d[MAXN], par[MAXN];
int stck[MAXN], nstck;
int jump[MAXN];
int bstep[MAXN][1 << HBITS];
S s[MAXS];
int ns, root;
int creates() {
  assert(ns < MAXS);
  int at = ns++;
  s[at].c[0] = s[at].c[1] = -1, s[at].mx = -1;
  return at;
}
void addtotree(int val) {
  int mask = val >> LBITS;
  int at = root;
  for (int i = HBITS - 1; i >= 0; --i) {
    int j = (mask >> i) & 1;
    if (s[at].c[j] == -1) s[at].c[j] = creates();
    at = s[at].c[j];
  }
  s[at].mx = max(s[at].mx, val);
}
void walktree(int id, int off, int at, int bit) {
  if (bit < 0) {
    bstep[id][off] = s[at].mx ^ (off << LBITS);
    return;
  }
  for (int j = (0); j < (2); ++j) {
    int to = s[at].c[1 - j];
    if (to == -1) to = s[at].c[j];
    assert(to != -1);
    walktree(id, off + (j << bit), to, bit - 1);
  }
}
void calcstep(int at) {
  ns = 0;
  root = creates();
  jump[at] = stck[nstck - STEP - 1];
  for (int i = (0); i < (STEP); ++i) addtotree(a[stck[nstck - i - 1]] ^ i);
  walktree(at, 0, root, HBITS - 1);
}
void dfs(int at, int p) {
  par[at] = p;
  d[at] = par[at] == -1 ? 0 : d[par[at]] + 1;
  stck[nstck++] = at;
  if (nstck > STEP) calcstep(at);
  for (int i = (0); i < (((int)(adj[at]).size())); ++i) {
    int to = adj[at][i];
    if (to == par[at]) continue;
    dfs(to, at);
  }
  --nstck;
}
void run() {
  scanf("%d%d", &n, &nq);
  for (int i = (0); i < (n); ++i) scanf("%d", &a[i]);
  for (int i = (0); i < (n - 1); ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = (0); i < (nq); ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    q[b].push_back(make_pair(a, i));
    ans[i] = -1;
  }
  nstck = 0;
  dfs(0, -1);
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (((int)(q[i]).size())); ++j) {
      int u = q[i][j].first, v = i, idx = q[i][j].second, dst = 0;
      while (d[v] - STEP >= d[u]) {
        ans[idx] = max(ans[idx], bstep[v][dst >> LBITS]);
        v = jump[v], dst += STEP;
      }
      while (true) {
        ans[idx] = max(ans[idx], a[v] ^ dst);
        if (u == v)
          break;
        else
          v = par[v], ++dst;
      }
    }
  for (int i = (0); i < (nq); ++i) printf("%d\n", ans[i]);
}
int main() {
  run();
  return 0;
}
