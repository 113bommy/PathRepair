#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > adj;
const int MAXN = 1e5 + 5;
int par[MAXN][18];
int ht[MAXN];
bool vst[MAXN];
int sub[MAXN];
void dfs(int cur) {
  vst[cur] = true;
  ++sub[cur];
  for (int i = 0; i < adj[cur].size(); ++i) {
    int next = adj[cur][i];
    if (!vst[next]) {
      par[next][0] = cur;
      ht[next] = ht[cur] + 1;
      dfs(next);
      sub[cur] += sub[next];
    }
  }
}
int lca(int u, int v) {
  if (ht[u] < ht[v]) swap(u, v);
  for (int i = 17; i >= 0; --i) {
    int p2 = (1 << i);
    if (ht[u] - p2 >= ht[v]) u = par[u][i];
  }
  if (u == v) return u;
  for (int i = 17; i >= 0; --i) {
    if (par[u][i] != par[v][i] && par[u][i] != -1) {
      u = par[u][i];
      v = par[v][i];
      if (u == v) return u;
    }
  }
  return par[u][0];
}
int bf1(int cur, int anc) {
  for (int i = 17; i >= 0; --i) {
    if (ht[cur] - (1 << i) > ht[anc]) cur = par[cur][i];
  }
  return cur;
}
bool isa(int x, int y) {
  for (int i = 17; i >= 0; --i) {
    if (ht[x] - (1 << i) >= ht[y]) x = par[x][i];
  }
  return x == y;
}
int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    adj.push_back({});
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < 18; ++j) par[i][j] = -1;
  }
  for (int i = 0; i < N - 1; ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(0);
  for (int i = 1; (1 << i) < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (par[j][i - 1] == -1) continue;
      par[j][i] = par[par[j][i - 1]][i - 1];
    }
  }
  int Q;
  cin >> Q;
  for (int j = 0; j < Q; ++j) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    if (x == y)
      cout << N << "\n";
    else if (abs(ht[x] - ht[y]) % 2 == 1) {
      cout << 0 << "\n";
    } else {
      int cur = lca(x, y);
      if (ht[x] == ht[y]) {
        int a = bf1(x, cur);
        int b = bf1(y, cur);
        cout << N - sub[a] - sub[b] << "\n";
      } else {
        if (ht[x] < ht[y]) swap(x, y);
        int dist = (ht[x] + ht[y]) / 2 - ht[cur];
        if (isa(x, y)) dist = (ht[x] - ht[y]) / 2;
        int p = x;
        int cd = dist;
        for (int i = 17; i >= 0; --i) {
          if ((1 << i) <= cd) {
            cd -= (1 << i);
            p = par[p][i];
          }
        }
        int q = x;
        --dist;
        for (int i = 17; i >= 0; --i) {
          if ((1 << i) <= dist) {
            dist -= (1 << i);
            q = par[q][i];
          }
        }
        cout << sub[p] - sub[q] << "\n";
      }
    }
  }
}
