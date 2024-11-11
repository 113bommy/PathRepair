#include <bits/stdc++.h>
using namespace std;
int n, m, par[100001] = {}, ans[100001] = {}, cnt[100001] = {};
int cyc = -1;
bool pos = 1;
vector<int> adj[100001];
int fn(int x) { return par[x] = (par[x] == x) ? x : fn(par[x]); }
bool jn(int a, int b) {
  a = fn(a), b = fn(b);
  if (a != b) {
    par[b] = a;
    return 1;
  }
  return 0;
}
bool dfs(int u, int p, int dst) {
  bool ret = 0;
  if (u == dst)
    ret = 1;
  else {
    for (auto v : adj[u]) {
      if (v != p) ret |= dfs(v, u, dst);
    }
  }
  if (ret) ans[u] = 2;
  return ret;
}
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    pos = 1;
    cyc = -1;
    for (int i = 0; i < n; i++) {
      par[i] = i;
      cnt[i] = -1;
      adj[i].clear();
      ans[i] = 0;
    }
    for (int j = 0; j < m; j++) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      if (u > v) swap(u, v);
      adj[u].push_back(v);
      adj[v].push_back(u);
      if (!jn(u, v)) cyc = fn(u);
    }
    if (cyc >= 0) {
      for (int i = 0; i < n; i++) {
        if (fn(i) == fn(cyc)) ans[i] = 1;
      }
    } else {
      pos = 0;
      for (int i = 0; i < n && !pos; i++) {
        if (adj[i].size() > 3) {
          ans[i] = 2;
          for (auto x : adj[i]) {
            ans[x] = 1;
          }
          pos = 1;
        } else if (adj[i].size() == 3) {
          if (cnt[fn(i)] == -1)
            cnt[fn(i)] = i;
          else {
            dfs(cnt[fn(i)], -1, i);
            for (auto v : adj[cnt[fn(i)]]) {
              if (!ans[v]) {
                ans[v] = 1;
              }
            }
            for (auto v : adj[i]) {
              if (!ans[v]) {
                ans[v] = 1;
              }
            }
            pos = 1;
          }
          bool c = 1;
          vector<pair<int, int> > posD;
          for (auto v : adj[i]) {
            c &= (adj[v].size() == 2);
            int p = i, u = v, cr = 1;
            while (adj[u].size() >= 2) {
              if (adj[u][0] != p) {
                p = u;
                u = adj[u][0];
              } else {
                p = u;
                u = adj[u][1];
              }
              cr++;
            }
            posD.push_back({cr, v});
          }
          sort(posD.begin(), posD.end());
          if (c) {
            ans[i] = 3;
            for (auto v : adj[i]) {
              for (auto vv : adj[v]) {
                if (vv != i) ans[vv] = 1;
              }
              ans[v] = 2;
            }
            pos = 1;
          } else if (posD[1].first >= 3 && posD[2].first >= 3) {
            ans[i] = 4;
            for (auto v : posD) {
              if (v.first < 3) continue;
              int p = i, u = v.second, cr = 1;
              while (cr <= 3) {
                ans[u] = 4 - cr;
                cr++;
                if (cr > 3) break;
                if (adj[u][0] != p) {
                  p = u;
                  u = adj[u][0];
                } else {
                  p = u;
                  u = adj[u][1];
                }
              }
            }
            ans[posD[0].second] = 2;
            pos = 1;
          } else if (posD[1].first >= 2 && posD[2].first >= 5) {
            ans[i] = 6;
            int p = i, u = posD[1].second, cr = 1;
            while (cr <= 2) {
              ans[u] = 6 - 2 * cr;
              cr++;
              if (cr > 2) break;
              if (adj[u][0] != p) {
                p = u;
                u = adj[u][0];
              } else {
                p = u;
                u = adj[u][1];
              }
            }
            p = i, u = posD[2].second, cr = 1;
            while (cr <= 5) {
              ans[u] = 6 - cr;
              cr++;
              if (cr > 5) break;
              if (adj[u][0] != p) {
                p = u;
                u = adj[u][0];
              } else {
                p = u;
                u = adj[u][1];
              }
            }
            ans[posD[0].second] = 3;
            pos = 1;
          }
        }
      }
    }
    if (pos) {
      cout << "YES\n";
      for (int i = 0; i < n; i++) {
        cout << ans[i];
        if (i + 1 < n) cout << " ";
      }
      cout << "\n";
    } else {
      cout << "NO\n";
    }
    for (int i = 0; i < n; i++) {
      par[i] = i;
      cnt[i] = -1;
      adj[i].clear();
      ans[i] = 0;
    }
  }
  return 0;
}
