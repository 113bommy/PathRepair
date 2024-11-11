#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-O2")
using namespace std;
const int N = 300000 + 10;
const long long MOD = 1000000000 + 7;
const long long INF = 1000000010;
const long long LOG = 25;
int n, m, mark[N], com[N], cnt[N], par[N], num[N], ans[N];
vector<int> G[N], Gin[N], g[N], gin[N], ft;
int pnt = 0;
void DFS(int v) {
  mark[v] = 1;
  for (auto u : G[v])
    if (!mark[u]) DFS(u);
  ft.push_back(v);
}
void DFS2(int v, int P) {
  com[v] = P;
  mark[v] = 1;
  for (auto u : Gin[v]) {
    if (!mark[u]) DFS2(u, P);
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int v, u;
    cin >> v >> u;
    G[v].push_back(u), Gin[u].push_back(v);
  }
  for (int i = 1; i <= n; i++)
    if (!mark[i]) DFS(i);
  memset(mark, 0, sizeof mark);
  reverse(ft.begin(), ft.end());
  for (int i = 0; i < n; i++) {
    if (!mark[ft[i]]) DFS2(ft[i], ++pnt);
  }
  for (int i = 1; i <= n; i++) {
    for (auto u : G[i]) {
      if (com[u] == com[i]) continue;
      g[com[i]].push_back(com[u]), gin[com[u]].push_back(com[i]);
    }
  }
  int ted = 0;
  set<int> st;
  for (int i = pnt; i >= 1; i--) {
    for (auto u : g[i]) {
      cnt[u]++;
      if (cnt[u] == 1) {
        st.erase(u);
        ted--;
        par[u] = i;
        num[i]++;
      } else if (cnt[u] == 2) {
        num[par[u]]--;
      }
    }
    if (ted != 0) {
      if (ted > 1)
        ans[i] = 2;
      else
        ans[i] = 1 + num[*st.begin()];
    }
    ted++;
    st.insert(i);
  }
  st.clear();
  ted = 0;
  memset(par, 0, sizeof par);
  memset(cnt, 0, sizeof cnt);
  memset(num, 0, sizeof num);
  for (int i = 1; i <= pnt; i++) {
    for (auto u : gin[i]) {
      cnt[u]++;
      if (cnt[u] == 1) {
        st.erase(u);
        ted--;
        par[u] = i;
        num[i]++;
      } else if (cnt[u] == 2) {
        num[par[u]]--;
      }
    }
    if (ted != 0) {
      if (ted >= 2)
        ans[i] += 2;
      else
        ans[i] += 1 + num[*st.begin()];
    }
    st.insert(i);
    ted++;
  }
  int res = 0;
  for (int i = 1; i <= n; i++) {
    if (ans[com[i]] < 2) res++;
  }
  cout << res << '\n';
  return 0;
}
