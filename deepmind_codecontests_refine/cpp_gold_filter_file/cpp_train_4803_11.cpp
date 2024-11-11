#include <bits/stdc++.h>
using namespace std;
int N, M;
int I[100005], O[100005];
long long Mx;
typedef pair<pair<int, int>, long long> piil;
vector<piil> G[100005];
bool rv[100005], vis[100005];
int Topo[100005];
bool cmp(int& a, int& b) { return O[a] > O[b]; }
int T, E;
bool dfs(int u) {
  I[u] = ++T;
  for (piil e : G[u]) {
    int v = e.first.second;
    long long w = e.second;
    if (I[v]) {
      if (!O[v]) {
        if (w > Mx) return false;
      }
    } else if (w > Mx && !dfs(v))
      return false;
  }
  O[u] = ++T;
  return true;
}
bool chk(long long X) {
  Mx = X;
  memset(I, 0, sizeof(I)), memset(O, 0, sizeof(O));
  T = 0;
  for (int i = 1; i <= N; i++)
    if (!I[i] && !dfs(i)) return false;
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  int a, b;
  long long w, mxw = 0;
  for (int i = 1; i <= M; i++) {
    cin >> a >> b >> w;
    G[a].push_back(make_pair(make_pair(i, b), w));
    mxw = max(mxw, w);
  }
  long long lo = -1, hi = mxw;
  while (lo + 1 < hi) {
    long long md = (lo + hi) / 2;
    if (chk(md))
      hi = md;
    else
      lo = md;
  }
  chk(hi);
  for (int i = 0; i <= N - 1; i++) Topo[i] = i + 1;
  memset(vis, 0, sizeof(vis));
  sort(Topo, Topo + N, cmp);
  int Cnt = 0;
  for (int i = 0; i <= N - 1; i++) {
    int u = Topo[i];
    vis[u] = true;
    for (piil Ei : G[u]) {
      int id = Ei.first.first, v = Ei.first.second;
      long long w = Ei.second;
      if (w <= hi && vis[v]) {
        rv[id] = true;
        Cnt++;
      }
    }
  }
  cout << hi << ' ' << Cnt << '\n';
  for (int i = 1; i <= M; i++)
    if (rv[i]) cout << i << ' ';
  return 0;
}
