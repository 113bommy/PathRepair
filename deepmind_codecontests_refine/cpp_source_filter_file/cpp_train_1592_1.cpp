#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops", \
                     "omit-frame-pointer", "inline")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native", "no-zero-upper")
using namespace std;
const long long mod = (1e9 + 7);
const long double eps = (1e-9);
const long long oo = (long long)(2e18 + 5);
set<int> g[(long long)(1e5 + 5)];
bool ady[(long long)(1e5 + 5) / 10 + 5][(long long)(1e5 + 5) / 10 + 5];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) g[i].clear();
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      g[u].insert(v);
      g[v].insert(u);
    }
    if (k > 20) {
      vector<int> oks;
      for (int i = 0; i < n; i++)
        if (g[i].size() >= k - 1) oks.push_back(i);
      vector<int> pos(n);
      for (int i = 0; i < oks.size(); i++) {
        pos[oks[i]] = i + 1;
        for (int j = 0; j < oks.size(); j++) ady[i][j] = 0;
      }
      vector<int> cant(n);
      for (auto u : oks)
        for (auto v : g[u])
          if (pos[v]) {
            cant[u]++;
            ady[pos[u] - 1][pos[v] - 1] = 1;
            ady[pos[v] - 1][pos[u] - 1] = 1;
          }
      queue<int> q;
      vector<bool> mk(n);
      for (int i = 0; i < n; i++)
        if (cant[i] < k) {
          mk[i] = 1;
          q.push(i);
        }
      bool clique = 0;
      vector<int> ans;
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (cant[u] < k - 1) {
          for (int i = 0; i < oks.size(); i++)
            if (ady[i][pos[u] - 1]) {
              ady[i][pos[u] - 1] = 0;
              ady[pos[u] - 1][i] = 0;
              cant[oks[i]]--;
              if (cant[oks[i]] < k && !mk[oks[i]]) {
                mk[oks[i]] = 1;
                q.push(oks[i]);
              }
            }
        } else {
          vector<int> ads;
          for (int i = 0; i < oks.size(); i++)
            if (ady[i][pos[u] - 1]) ads.push_back(i);
          clique = 1;
          for (auto u : ads) {
            for (auto v : ads)
              if (u != v) clique &= ady[u][v];
            if (!clique) break;
          }
          if (clique) {
            ans = ads;
            ans.push_back(pos[u]);
            break;
          }
          for (int i = 0; i < oks.size(); i++)
            if (ady[i][pos[u] - 1]) {
              ady[i][pos[u] - 1] = 0;
              ady[pos[u] - 1][i] = 0;
              cant[oks[i]]--;
              if (cant[oks[i]] < k && !mk[oks[i]]) {
                mk[oks[i]] = 1;
                q.push(oks[i]);
              }
            }
        }
      }
      if (clique) {
        cout << 2 << '\n';
        for (int i = 0; i < ans.size(); i++) {
          ans[i] = oks[ans[i]];
          cout << ans[i] + 1 << ' ';
        }
        cout << '\n';
        continue;
      }
      ans.clear();
      for (int i = 0; i < n; i++)
        if (!mk[i]) ans.push_back(i);
      if (ans.size() > k) {
        cout << 1 << ' ' << ans.size() << '\n';
        for (int i = 0; i < ans.size(); i++) cout << ans[i] + 1 << ' ';
        cout << '\n';
        continue;
      } else
        cout << (-1) << '\n';
    } else {
      queue<int> q;
      vector<bool> mk(n);
      for (int i = 0; i < n; i++)
        if (g[i].size() < k) {
          mk[i] = 1;
          q.push(i);
        }
      bool clique = 0;
      vector<int> ans;
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (g[u].size() < k - 1) {
          for (auto v : g[u]) {
            g[v].erase(u);
            if (g[v].size() < k && !mk[v]) {
              mk[v] = 1;
              q.push(v);
            }
          }
        } else {
          ans.clear();
          ans.push_back(u);
          for (auto v : g[u]) ans.push_back(v);
          clique = 1;
          for (auto u : ans)
            for (auto v : ans)
              if (u != v) clique &= g[u].count(v);
          if (clique) break;
          for (auto v : g[u]) {
            g[v].erase(u);
            if (g[v].size() < k && !mk[v]) {
              mk[v] = 1;
              q.push(v);
            }
          }
        }
      }
      if (clique) {
        cout << 2 << '\n';
        for (int i = 0; i < ans.size(); i++) cout << ans[i] + 1 << ' ';
        cout << '\n';
        continue;
      }
      ans.clear();
      for (int i = 0; i < n; i++)
        if (!mk[i]) ans.push_back(i);
      if (ans.size() > k) {
        cout << 1 << ' ' << ans.size() << '\n';
        for (int i = 0; i < ans.size(); i++) cout << ans[i] + 1 << ' ';
        cout << '\n';
        continue;
      } else
        cout << (-1) << '\n';
    }
  }
  return 0;
}
