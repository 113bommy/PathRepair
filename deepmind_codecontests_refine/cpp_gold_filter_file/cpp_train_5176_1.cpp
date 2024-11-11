#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int MX = 10000010;
const int MN = 100010;
int exp(int x, int n) {
  int ret = 1;
  while (n) {
    if (n & 1) ret = 1LL * ret * x % mod;
    x = 1LL * x * x % mod;
    n >>= 1;
  }
  return ret;
}
vector<int> pr;
int pchk[MX];
void sieve() {
  for (int i = 2; i < MX; i++) {
    if (!pchk[i]) {
      pr.push_back(i);
      pchk[i] = i;
    }
    for (int j = 0; j < pr.size() && i * pr[j] < MX; j++) {
      pchk[i * pr[j]] = pr[j];
      if (i % pr[j] == 0) break;
    }
  }
}
int N, Q;
vector<int> adj[MN];
int A[MN];
struct Query {
  int u, v, w, x, id;
};
Query query[MN];
int par[20][MN], dep[MN], tin[MN], invt[MN], timer;
void dfs0(int u, int p) {
  tin[u] = timer++;
  par[0][u] = p;
  for (int i = 1; i < 20; i++) {
    int t = par[i - 1][u];
    if (t == -1) break;
    par[i][u] = par[i - 1][t];
  }
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == p) continue;
    dep[v] = dep[u] + 1;
    dfs0(v, u);
  }
}
int lca(int a, int b) {
  if (dep[a] < dep[b]) swap(a, b);
  int diff = dep[a] - dep[b];
  for (int i = 0; i < 20; i++) {
    if (diff & (1 << i)) a = par[i][a];
  }
  if (a == b) return a;
  for (int i = 20; i--;) {
    if (par[i][a] != par[i][b]) {
      a = par[i][a];
      b = par[i][b];
    }
  }
  return par[0][a];
}
unordered_map<int, vector<int> > V, X;
vector<int> tadj[MN], P;
stack<int> stk;
int ta[MN], dp[MN][30];
void dfs1(int u) {
  for (int i = 0; i < 30; i++) {
    dp[u][i] += min(i, ta[u]);
  }
  for (int i = 0; i < tadj[u].size(); i++) {
    int v = tadj[u][i];
    for (int j = 0; j < 30; j++) {
      dp[v][j] = dp[u][j];
    }
    dfs1(v);
  }
}
int ans[MN];
int main() {
  sieve();
  scanf("%d", &N);
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  dfs0(0, -1);
  for (int i = 0; i < N; i++) invt[tin[i]] = i;
  scanf("%d", &Q);
  for (int i = 0; i < Q; i++) {
    int u, v, x;
    scanf("%d %d %d", &u, &v, &x);
    u--;
    v--;
    query[i] = {u, v, lca(u, v), x, i};
  }
  for (int i = 0; i < N; i++) {
    vector<int> fact;
    int n = A[i];
    while (n != 1) {
      if (fact.size() == 0 || fact.back() != pchk[n]) fact.push_back(pchk[n]);
      n /= pchk[n];
    }
    for (int j = 0; j < fact.size(); j++) {
      V[fact[j]].push_back(tin[i]);
    }
  }
  for (int i = 0; i < Q; i++) {
    int u = query[i].u;
    int v = query[i].v;
    int w = query[i].w;
    vector<int> fact;
    int n = query[i].x;
    while (n != 1) {
      if (fact.size() == 0 || fact.back() != pchk[n]) fact.push_back(pchk[n]);
      n /= pchk[n];
    }
    for (int j = 0; j < fact.size(); j++) {
      V[fact[j]].push_back(tin[u]);
      V[fact[j]].push_back(tin[v]);
      V[fact[j]].push_back(tin[w]);
      X[fact[j]].push_back(i);
    }
  }
  for (int i = 0; i < Q; i++) ans[i] = 1;
  for (unordered_map<int, vector<int> >::iterator it = V.begin(); it != V.end();
       it++) {
    int p = it->first;
    vector<int> T = it->second;
    sort(T.begin(), T.end());
    T.resize(unique(T.begin(), T.end()) - T.begin());
    P.clear();
    stk.push(invt[T[0]]);
    P.push_back(invt[T[0]]);
    for (int i = 1; i < T.size(); i++) {
      int u = invt[T[i - 1]];
      int v = invt[T[i]];
      int x = lca(u, v);
      int la = -1;
      while (!stk.empty() && tin[stk.top()] >= tin[x]) {
        int t = stk.top();
        stk.pop();
        if (la != -1) tadj[t].push_back(la);
        la = t;
      }
      if (la != -1 && x != la) tadj[x].push_back(la);
      stk.push(x);
      stk.push(v);
      P.push_back(x);
      P.push_back(v);
    }
    int la = -1;
    while (!stk.empty()) {
      int t = stk.top();
      stk.pop();
      if (la != -1) tadj[t].push_back(la);
      la = t;
    }
    for (int i = 0; i < P.size(); i++) {
      int n = A[P[i]];
      int cnt = 0;
      while (n % p == 0) n /= p, cnt++;
      ta[P[i]] = cnt;
    }
    for (int i = 0; i < 30; i++) dp[la][i] = 0;
    dfs1(la);
    for (int i = 0; i < X[p].size(); i++) {
      int id = X[p][i];
      int n = query[id].x;
      int cnt = 0;
      while (n % p == 0) n /= p, cnt++;
      int u = query[id].u;
      int v = query[id].v;
      int w = query[id].w;
      ans[id] =
          1LL * ans[id] *
          exp(p, dp[u][cnt] + dp[v][cnt] - 2 * dp[w][cnt] + min(cnt, ta[w])) %
          mod;
    }
    for (int i = 0; i < P.size(); i++) {
      tadj[P[i]].clear();
    }
  }
  for (int i = 0; i < Q; i++) {
    printf("%d\n", ans[i]);
  }
}
