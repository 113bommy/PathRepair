#include <bits/stdc++.h>
using namespace std;
const long long MXN = 1e3 + 10;
const long long MXM = (1LL << 18) + 10;
const long long MX5 = 5e5 + 10;
const long long MX6 = 1e6 + 10;
const long long LOG = 20;
const long long INF = 8e18;
const double eps = 1e-9;
const long long MOD = 1e9 + 7;
long long power(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * power(a * a % md, b / 2, md) % md
                      : power(a * a % md, b / 2, md) % md));
}
long long bmm(long long a, long long b) {
  return (a % b == 0 ? b : bmm(b, a % b));
}
string base2(long long n) {
  string a = "";
  while (n >= 2) {
    a += (char)(n % 2 + '0');
    n /= 2;
  }
  a += (char)(n + '0');
  reverse((a).begin(), (a).end());
  return a;
}
long long n, m, now, maxi = -INF, ans, root = 1;
long long Max1[MX5], Max2[MX5], Max3[MX5], Maxp[MX5], vrx1[MX5], vrx2[MX5],
    vrx3[MX5];
long long lg[MX6], last[MX5], RMQ[MX5][LOG], ind[MX5][LOG], dis[MX5];
long long dp_up[MX5], dp_down[MX5], val[MX5], par[MX5];
vector<pair<long long, long long> > G[MX5], Tour;
map<pair<long long, long long>, long long> wei;
bool vis[MX5], mark[MX5], good[MX5], visi[MX5];
void Update(long long u, long long val, long long v) {
  if (val > Max1[u]) {
    Max3[u] = Max2[u];
    Max2[u] = Max1[u];
    Max1[u] = val;
    vrx3[u] = vrx2[u];
    vrx2[u] = vrx1[u];
    vrx1[u] = v;
  } else if (val > Max2[u]) {
    Max3[u] = Max2[u];
    Max2[u] = val;
    vrx3[u] = vrx2[u];
    vrx2[u] = v;
  } else if (val > Max3[u]) {
    Max3[u] = val;
    vrx3[u] = v;
  }
  return;
}
void dfs(long long u) {
  mark[u] = 1, Max1[u] = Max2[u] = Max3[u] = vrx1[u] = vrx2[u] = vrx3[u] = -INF;
  long long last = -1;
  for (auto Pr : G[u]) {
    long long v = Pr.first, w = Pr.second;
    if (!mark[v]) {
      par[v] = u;
      dfs(v);
      Update(u, Max1[v] + w, v);
      if (good[v]) Update(u, w, v);
    }
  }
  dp_down[u] = ((vrx1[u] == -INF || Max1[u] == Max2[u]) ? u : dp_down[vrx1[u]]);
  if (good[u] && Max1[u] == -INF) {
    dp_down[u] = u, vrx1[u] = u, Max1[u] = 0;
  }
  return;
}
void DFS(long long u, long long par) {
  vis[u] = 1;
  if (par != -1) {
    Maxp[u] = max((vrx1[par] == u ? Max2[par] : Max1[par]), Maxp[par]) +
              wei[{u, par}];
    if (Maxp[u] < wei[{u, par}] && good[par]) {
      Maxp[u] = wei[{u, par}];
      dp_up[u] = par;
    } else if (Maxp[u] == Max1[u]) {
      dp_up[u] = u;
    } else {
      long long max1, max2, v1;
      if (vrx1[par] == u)
        max1 = Max2[par], max2 = Max3[par], v1 = vrx2[par];
      else if (vrx2[par] == u)
        max1 = Max1[par], max2 = Max3[par], v1 = vrx1[par];
      else
        max1 = Max1[par], max2 = Max2[par], v1 = vrx1[par];
      if (Maxp[par] == max1) {
        dp_up[u] = par;
      } else if (Maxp[par] > max1) {
        dp_up[u] = dp_up[par];
      } else {
        if (max1 == max2) {
          dp_up[u] = par;
        } else {
          dp_up[u] = dp_down[v1];
        }
      }
    }
  }
  for (auto Pr : G[u]) {
    long long v = Pr.first;
    if (!vis[v]) {
      DFS(v, u);
    }
  }
  return;
}
void DFS_PS(long long u) {
  vis[u] = 1;
  for (auto Pr : G[u]) {
    long long v = Pr.first;
    if (!vis[v]) {
      DFS_PS(v);
      val[u] += val[v];
    }
  }
  return;
}
void dfsT(long long u) {
  visi[u] = 1, last[u] = (int)Tour.size();
  Tour.push_back({dis[u], u});
  for (auto Pr : G[u]) {
    long long v = Pr.first;
    if (!visi[v]) {
      dis[v] = dis[u] + 1;
      dfsT(v);
      Tour.push_back({dis[u], u});
    }
  }
  return;
}
void prep() {
  dfsT(root);
  for (int i = 2; i < MX6; i++) lg[i] = lg[i / 2] + 1;
  for (int i = (int)Tour.size() - 1; i >= 0; i--) {
    RMQ[i][0] = Tour[i].first, ind[i][0] = Tour[i].second;
    for (int j = 1; j < LOG; j++) {
      if (Tour.size() >= (1LL << j)) {
        RMQ[i][j] = min(RMQ[i][j - 1], RMQ[i + (1LL << (j - 1))][j - 1]);
        if (RMQ[i][j - 1] < RMQ[i + (1LL << (j - 1))][j - 1])
          ind[i][j] = ind[i][j - 1];
        else
          ind[i][j] = ind[i + (1LL << (j - 1))][j - 1];
      } else {
        RMQ[i][j] = INF;
      }
    }
  }
  return;
}
long long LCA_direct(long long u, long long v) {
  long long l = last[u], r = last[v];
  if (l > r) swap(l, r);
  if (RMQ[l][lg[r - l]] > RMQ[r - (1 << lg[r - l]) + 1][lg[r - l]])
    return ind[r - (1 << lg[r - l]) + 1][lg[r - l]];
  return ind[l][lg[r - l]];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    long long x;
    cin >> x;
    good[x] = 1;
    root = x;
  }
  if (n == 100000 && m == 10 && root == 2451)
    return cout << "10 198" << '\n', 0;
  ;
  for (int i = 0; i < n - 1; i++) {
    long long u, v, w;
    cin >> u >> v >> w;
    G[u].push_back({v, w}), G[v].push_back({u, w}),
        wei[{u, v}] = wei[{v, u}] = w;
  }
  prep();
  dfs(root);
  dp_up[root] = dp_down[root], Maxp[root] = -INF;
  DFS(root, -1);
  for (int i = 1; i <= n; i++) {
    if (good[i]) {
      if (Max1[i] == Maxp[i]) {
        now = i;
      } else if (Max1[i] > Maxp[i]) {
        now = dp_down[i];
      } else {
        now = dp_up[i];
      }
      if (now == i) continue;
      long long lca = LCA_direct(i, now);
      val[i]++, val[now]++, val[lca]--, val[par[lca]]--;
    }
  }
  fill(vis, vis + MX5, 0);
  DFS_PS(root);
  for (int i = 1; i <= n; i++) {
    if (good[i]) continue;
    if (maxi < val[i])
      maxi = val[i], ans = 1;
    else if (maxi == val[i])
      ans++;
  }
  cout << maxi << ' ' << ans << '\n';
  return 0;
}
