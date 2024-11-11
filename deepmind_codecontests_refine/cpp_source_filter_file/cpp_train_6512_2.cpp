#include <bits/stdc++.h>
using namespace std;
static const int M = 100005;
int inv[M], Exp[M];
int disUp[M], disDown[M];
int sz[M], dep[M];
map<int, int> cnta, cntb;
int P;
struct node {
  int to, cost;
};
vector<node> es[M];
void extgcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1, y = 0;
    return;
  }
  extgcd(b, a % b, y, x);
  y -= a / b * x;
}
void Get_size(int u, int fa) {
  sz[u] = 1;
  for (int i = 0; i < es[u].size(); ++i) {
    int v = es[u][i].to;
    if (v != fa) {
      disUp[v] = (1LL * disUp[u] + 1LL * es[u][i].cost * Exp[dep[u]]) % P;
      disDown[v] = (1LL * disDown[u] * 10 + es[u][i].cost) % P;
      dep[v] = dep[u] + 1;
      Get_size(v, u);
      sz[u] += sz[v];
    }
  }
}
void Query(int u, int fa, int rt, long long &ans) {
  int DISUp = 1LL * ((long long)disUp[u] - disUp[rt] + P) * inv[dep[rt]] % P;
  int Tmpb = 1LL * ((long long)disDown[rt] - DISUp + P) * inv[dep[rt]] % P;
  if (cntb.count(Tmpb)) ans += cntb[Tmpb];
  int DISDown =
      ((1LL * disDown[u] - 1LL * disDown[rt] * inv[dep[u] - dep[rt]]) % P + P) %
      P;
  int Tmpa =
      (1LL * (P - DISDown) * inv[dep[u] - dep[rt]] % P * Exp[dep[rt]] % P +
       disUp[rt]) %
      P;
  if (cnta.count(Tmpa)) ans += cnta[Tmpa];
  for (int i = 0; i < es[u].size(); ++i)
    if (es[u][i].to != fa) Query(es[u][i].to, u, rt, ans);
}
void Add(int u, int fa) {
  ++cnta[disUp[u]];
  ++cntb[1LL * disDown[u] * inv[dep[u]] % P];
  for (int i = 0; i < es[u].size(); ++i)
    if (es[u][i].to != fa) Add(es[u][i].to, u);
}
void solve(int u, int fa, long long &ans) {
  int Mx = 0, Wson = -1;
  for (int i = 0, v; i < es[u].size(); ++i) {
    v = es[u][i].to;
    if (v != fa && Mx < sz[v]) Mx = sz[v], Wson = v;
  }
  for (int i = 0, v; i < es[u].size(); ++i) {
    v = es[u][i].to;
    if (v != fa && v != Wson) {
      solve(v, u, ans);
      cnta.clear(), cntb.clear();
    }
  }
  if (~Wson) solve(Wson, u, ans);
  for (int i = 0, v; i < es[u].size(); ++i) {
    v = es[u][i].to;
    if (v != fa && v != Wson) {
      Query(v, u, u, ans);
      Add(v, u);
    }
  }
  int Tmpb = 1LL * disDown[u] * inv[dep[u]] % P;
  if (cntb.count(Tmpb)) ans += cntb[Tmpb];
  int Tmpa = disUp[u];
  if (cnta.count(Tmpa)) ans += cnta[Tmpa];
  ++cnta[disUp[u]];
  ++cntb[1LL * disDown[u] * inv[dep[u]] % P];
}
int main() {
  int n;
  scanf("%d%d", &n, &P);
  if (P == 1) {
    cout << 1LL * n * (n - 1) << endl;
    return 0;
  }
  long long x, y;
  extgcd(10, P, x, y);
  x = (x % P + P) % P;
  inv[0] = Exp[0] = 1, inv[1] = x;
  for (int i = 1; i < M; ++i) {
    inv[i] = 1LL * inv[i - 1] * inv[1] % P;
    Exp[i] = 1LL * Exp[i - 1] * 10 % P;
  }
  for (int i = 1, u, v, c; i < n; ++i) {
    scanf("%d%d%d", &u, &v, &c);
    es[u].push_back((node){v, c});
    es[v].push_back((node){u, c});
  }
  Get_size(0, 0);
  long long ans = 0;
  solve(0, 0, ans);
  cout << ans << endl;
  return 0;
}
