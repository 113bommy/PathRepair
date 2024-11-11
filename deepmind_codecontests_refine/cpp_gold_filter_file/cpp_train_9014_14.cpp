#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100100];
int ans[100100], vst[100100], pre[100100], sz[100100];
int II, I, flag, num;
bool dfs(int u, int fa = -1) {
  vst[u] = 1;
  if (adj[u].size() == 1) num++;
  for (int v : adj[u]) {
    if (vst[v] && v != fa) {
      pre[v] = u, I = u;
      return true;
    }
    if (!vst[v]) {
      pre[v] = u;
      if (dfs(v, u)) return true;
    }
  }
  return false;
}
void calc(int u) {
  ans[u] = 1 + (adj[u].size() > 1);
  for (int v : adj[u])
    if (vst[v] != 2) vst[v] = 2, calc(v);
}
int calc(int u, int fa) {
  int ans = 1;
  for (int v : adj[u])
    if (v != fa) ans += calc(v, u);
  return ans;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) adj[i].clear(), vst[i] = ans[i] = 0;
    while (m--) {
      int u, v;
      scanf("%d %d", &u, &v);
      adj[u].push_back(v), adj[v].push_back(u);
    }
    II = -1, flag = 0;
    for (int i = 1; i <= n; i++)
      if (!vst[i]) {
        num = 0;
        flag = dfs(i);
        if (flag) break;
        if (num > 3) II = i;
      }
    if (flag) {
      for (int u = I;; u = pre[u]) {
        ans[u] = 728;
        if (pre[u] == I) break;
      }
    } else if (~II)
      vst[II] = 2, calc(II);
    else {
      flag = 0;
      for (int u = 1; u <= n; u++)
        if (adj[u].size() == 3) {
          for (int v : adj[u]) sz[v] = calc(v, u);
          sort(adj[u].begin(), adj[u].end(),
               [](int a, int b) { return sz[a] < sz[b]; });
          if (sz[adj[u][0]] >= 2) {
            flag = 1;
            ans[u] = 3;
            for (int v : adj[u]) {
              ans[v] = 2;
              for (int c : adj[v])
                if (c != u) {
                  ans[c] = 1;
                  break;
                }
            }
            break;
          }
          if (sz[adj[u][0]] == 1) {
            if (sz[adj[u][1]] >= 3) {
              flag = 1;
              ans[u] = 4;
              ans[adj[u][0]] = 2;
              for (int i = 1; i < 3; i++) {
                int v = adj[u][i];
                ans[v] = 3;
                for (int c : adj[v])
                  if (c != u) {
                    ans[c] = 2;
                    for (int d : adj[c])
                      if (d != v) {
                        ans[d] = 1;
                        break;
                      }
                    break;
                  }
              }
              break;
            }
            if (sz[adj[u][1]] == 2 && sz[adj[u][2]] >= 5) {
              flag = 1;
              ans[u] = 6;
              ans[adj[u][0]] = 3;
              int v = adj[u][1];
              ans[v] = 4;
              for (int c : adj[v])
                if (c != u) {
                  ans[c] = 2;
                  break;
                }
              int a5 = adj[u][2];
              ans[a5] = 5;
              for (int x : adj[a5])
                if (x != u) {
                  int a4 = x;
                  ans[a4] = 4;
                  for (int x : adj[a4])
                    if (x != a5) {
                      int a3 = x;
                      ans[a3] = 3;
                      for (int x : adj[a3])
                        if (x != a4) {
                          int a2 = x;
                          ans[a2] = 2;
                          for (int x : adj[a2])
                            if (x != a3) {
                              ans[x] = 1;
                              break;
                            }
                          break;
                        }
                      break;
                    }
                  break;
                }
              break;
            }
          }
        }
      if (!flag) {
        puts("NO");
        continue;
      }
    }
    puts("YES");
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    puts("");
  }
}
