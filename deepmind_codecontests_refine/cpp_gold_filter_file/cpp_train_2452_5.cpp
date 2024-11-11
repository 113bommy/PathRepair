#include <bits/stdc++.h>
using namespace std;
const int N = 1010, M = 30010;
const int INF = 2000 * 1000 * 1000LL + 10;
struct NODE {
  int u, w, ind;
  NODE(int _u, int _w, int _ind) {
    u = _u;
    w = _w;
    ind = _ind;
  }
};
vector<NODE> adj[N];
vector<int> vc;
int st[N], d[N], edge[M], start, tmp, ans(INF), ansi1(-1), ansi2(-1), s, t, m;
bool mark[N];
void DFS1(int v, int par, int ind) {
  mark[v] = 1;
  st[v] = start++;
  for (auto u : adj[v])
    if (!mark[u.u]) {
      DFS1(u.u, v, u.ind);
      d[v] += d[u.u];
    } else if (u.ind != ind && st[v] > st[u.u]) {
      d[v]++;
      d[u.u]--;
    }
  if (mark[t] && st[v] <= st[t] && v != par) {
    vc.push_back(ind);
    if (!d[v] && edge[ind] < ans) {
      ans = edge[ind];
      ansi1 = ind;
    }
  }
  return;
}
void DFS2(int v, int ind, int ign) {
  mark[v] = 1;
  st[v] = start++;
  for (auto u : adj[v])
    if (u.ind != ign) {
      if (!mark[u.u]) {
        DFS2(u.u, u.ind, ign);
        d[v] += d[u.u];
      } else if (u.ind != ind && st[v] > st[u.u]) {
        d[v]++;
        d[u.u]--;
      }
    }
  if (ind != m && !d[v] && mark[t] && st[v] <= st[t] && ans > edge[ind] + tmp) {
    ans = edge[ind] + tmp;
    ansi1 = ind, ansi2 = ign;
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, u, v, w;
  cin >> n >> m >> s >> t;
  s--, t--;
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> w;
    adj[--u].push_back(*new NODE(--v, w, i));
    adj[v].push_back(*new NODE(u, w, i));
    edge[i] = w;
  }
  DFS1(s, s, m);
  if (!mark[t]) {
    cout << "0\n0\n";
    return 0;
  }
  for (auto u : vc) {
    memset(mark, 0, sizeof mark);
    memset(d, 0, sizeof d);
    memset(st, 0, sizeof st);
    tmp = edge[u];
    DFS2(s, m, u);
  }
  if (ans == INF) {
    cout << -1 << endl;
    return 0;
  }
  cout << ans << endl;
  if (ansi1 == -1) swap(ansi1, ansi2);
  if (ansi2 == -1)
    cout << "1\n" << ansi1 + 1 << endl;
  else
    cout << "2\n" << ansi1 + 1 << " " << ansi2 + 1 << endl;
  return 0;
}
