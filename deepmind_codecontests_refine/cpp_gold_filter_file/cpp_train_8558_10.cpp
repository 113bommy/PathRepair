#include <bits/stdc++.h>
using namespace std;
struct data {
  long long u, v, w;
  data(){};
  data(long long u, long long v, long long w) : u(u), v(v), w(w){};
};
const long long N = 2e5 + 4;
long long n;
vector<long long> adj[N];
data ore;
pair<long long, long long> Trace[N][3];
long long dp[N][3], res;
void DFS(long long dad, long long u) {
  Trace[u][1] = pair<long long, long long>(u, u);
  dp[u][2] = -(long long)1e9 + 7;
  vector<long long> V_1, V_2;
  for (long long v : adj[u])
    if (v != dad) {
      DFS(u, v);
      if (dp[u][1] < dp[v][1] + 1) {
        dp[u][1] = dp[v][1] + 1;
        Trace[u][1] = Trace[v][1];
      }
      if (dp[u][2] < dp[v][2] + 1) {
        dp[u][2] = dp[v][2] + 1;
        Trace[u][2] = Trace[v][2];
      }
      V_1.push_back(v);
      V_2.push_back(v);
    }
  if (V_1.empty()) return;
  sort(V_1.begin(), V_1.end(),
       [](long long u, long long v) { return dp[u][1] > dp[v][1]; });
  sort(V_2.begin(), V_2.end(),
       [](long long u, long long v) { return dp[u][2] > dp[v][2]; });
  if ((long long)V_1.size() >= 2) {
    long long p1 = V_1[0], p2 = V_1[1];
    if (dp[u][2] < dp[p1][1] + dp[p2][1] + 2) {
      dp[u][2] = dp[p1][1] + dp[p2][1] + 2;
      Trace[u][2] =
          pair<long long, long long>(Trace[p1][1].first, Trace[p2][1].first);
    }
    if (res < dp[p1][1] + dp[p2][1] + 2) {
      res = dp[p1][1] + dp[p2][1] + 2;
      ore = data(u, Trace[p1][1].first, Trace[p2][1].first);
    }
  }
  for (long long i = 0; i <= (long long)1; ++i)
    for (long long j = 0; j <= (long long)1; ++j)
      if (i < (long long)V_1.size() && j < (long long)V_2.size() &&
          V_1[i] != V_2[j]) {
        if (res < dp[V_1[i]][1] + dp[V_2[j]][2] + 2) {
          res = dp[V_1[i]][1] + dp[V_2[j]][2] + 2;
          ore = data(Trace[V_1[i]][1].first, Trace[V_2[j]][2].first,
                     Trace[V_2[j]][2].second);
        }
      }
  if ((long long)V_1.size() >= 3) {
    long long p = V_1[0], q = V_1[1], t = V_1[2];
    if (res < dp[p][1] + dp[q][1] + dp[t][1] + 3) {
      res = dp[p][1] + dp[q][1] + dp[t][1] + 3;
      ore = data(Trace[p][1].first, Trace[q][1].first, Trace[t][1].first);
    }
  }
}
void sol() {
  long long root;
  for (long long u = 1; u <= (long long)n; ++u)
    if ((long long)adj[u].size() > 1) root = u;
  DFS(0, root);
  cout << res << '\n' << ore.u << " " << ore.v << " " << ore.w << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (fopen("input.txt", "r")) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  }
  cin >> n;
  for (long long i = 1; i < (long long)n; ++i) {
    long long u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  sol();
  return 0;
}
