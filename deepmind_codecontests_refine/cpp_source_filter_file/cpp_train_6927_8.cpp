#include <bits/stdc++.h>
using namespace std;
list<int> out[6000];
list<int> in[6000];
vector<pair<int, int> > E;
int n, m;
bool vis[6000];
stack<int> S;
int P[6000];
int Ps[6000];
bool nBlind[6000];
int Cykl[6000];
int Find(int x) {
  if (P[x] == x)
    return x;
  else
    return P[x] = Find(P[x]);
}
void Union(int a, int b) { P[Find(a)] = Find(b); }
void dfs(int x) {
  vis[x] = true;
  for (int y : out[x])
    if (vis[y] == false) dfs(y);
  S.push(x);
}
void dfs2(int x) {
  vis[x] = true;
  for (int y : in[x])
    if (vis[y] == false) {
      Union(x, y);
      dfs2(y);
    }
}
int D[6000];
int Szukajcyklu(int x) {
  for (int i = 1; i <= n; ++i) D[i] = -1;
  D[x] = 0;
  queue<int> Q;
  Q.push(x);
  while (!Q.empty()) {
    int c = Q.front();
    for (int d : out[c])
      if (D[d] == -1) {
        D[d] = D[c] + 1;
        Q.push(d);
      }
    Q.pop();
  }
  int mincykl = 100000000;
  for (int y : in[x])
    if (D[y] != -1) mincykl = min(mincykl, D[y]);
  if (mincykl == 100000000) mincykl = -1;
  return mincykl + 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  scanf("%d%d", &n, &m);
  int a, b;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &a, &b);
    out[a].push_back(b);
    in[b].push_back(a);
    E.push_back(pair<int, int>(a, b));
  }
  for (int i = 1; i <= n; ++i)
    if (vis[i] == false) dfs(i);
  for (int i = 1; i <= n; ++i) {
    P[i] = i;
    vis[i] = false;
  }
  while (!S.empty()) {
    if (vis[S.top()] == false) dfs2(S.top());
    S.pop();
  }
  for (int i = 1; i <= n; ++i) {
    in[i].clear();
    out[i].clear();
  }
  for (int i = 0; i < m; ++i) {
    int a = E[i].first;
    int b = E[i].second;
    int Fa = Find(a);
    int Fb = Find(b);
    if (Fa == Fb) {
      out[a].push_back(b);
      in[b].push_back(a);
    } else
      nBlind[Fb] = true;
  }
  for (int i = 1; i <= n; ++i)
    if (nBlind[Find(i)] == false) {
      int sc = Szukajcyklu(i);
      if (sc < Cykl[Find(i)] || Cykl[Find(i)] == 0) Cykl[Find(i)] = sc;
    }
  long long res = n;
  for (int i = 1; i <= n; ++i)
    if (Find(i) == i && nBlind[i] == false) {
      if (Cykl[i] != 0) res += 1 + Cykl[i] * 998ll;
    }
  printf("%lld\n", res);
}
