#include <bits/stdc++.h>
using namespace std;
const int MAX = 5005;
const long long oo = 1LL << 60;
int N;
vector<int> adj[MAX], edge[MAX];
long long cnt[MAX];
long long acc_down[MAX];
long long acc_up[MAX];
int comp[MAX], typ;
long long ans;
void dfs_down(int v, int p) {
  cnt[v] = 1;
  comp[v] = typ;
  for (int i = 0; i < (int)adj[v].size(); i++) {
    int w = adj[v][i], cost = edge[v][i];
    if (w == p) continue;
    dfs_down(w, v);
    cnt[v] += cnt[w];
    acc_down[v] += cost * cnt[w] + acc_down[w];
  }
}
void dfs_up(int v, int p) {
  for (int i = 0; i < (int)adj[v].size(); i++) {
    int w = adj[v][i], cost = edge[v][i];
    if (w == p) continue;
    acc_up[w] = acc_up[v] + cost * (cnt[comp[v]] - cnt[w]) + acc_down[v] -
                acc_down[w] - cost * cnt[w];
    dfs_up(w, v);
  }
}
void process(int v, int w, int cost) {
  memset(acc_down, 0, sizeof(acc_down));
  memset(acc_up, 0, sizeof(acc_up));
  typ = v;
  dfs_down(v, w);
  dfs_up(v, w);
  typ = w;
  dfs_down(w, v);
  dfs_up(w, v);
  long long S = 0, T = 0, min_S = oo, min_T = oo;
  for (int i = 1; i <= N; i++) {
    if (comp[i] == v) {
      S += acc_down[i] + acc_up[i];
      min_S = min(min_S, acc_down[i] + acc_up[i]);
    } else {
      T += acc_down[i] + acc_up[i];
      min_T = min(min_T, acc_down[i] + acc_up[i]);
    }
  }
  S >>= 1, T >>= 1;
  ans = min(ans,
            S + T + cnt[w] * min_S + cnt[v] * min_T + cnt[v] * cnt[w] * cost);
}
void dfs(int v, int p) {
  for (int i = 0; i < (int)adj[v].size(); i++) {
    int w = adj[v][i], cost = edge[v][i];
    if (w == p) continue;
    process(v, w, cost);
    dfs(w, v);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> N;
  for (int i = 1; i < N; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    adj[a].push_back(b);
    adj[b].push_back(a);
    edge[a].push_back(w);
    edge[b].push_back(w);
  }
  ans = oo;
  dfs(1, -1);
  cout << ans << endl;
  return 0;
}
