#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
ostream& operator<<(ostream& out, const pair<A, B>& p) {
  return out << "(" << p.first << ", " << p.second << ")";
}
template <class A>
ostream& operator<<(ostream& out, const vector<A>& v) {
  out << "[";
  for (int i = 0; i < v.size(); ++i) {
    if (i) out << ", ";
    out << v[i];
  }
  return out << "]";
}
const int N = 106;
int n, k;
const long long MOD = 1e9 + 7;
long long mul(long long o1, long long o2) { return o1 * o2 % MOD; }
vector<int> adj[N];
vector<int> dis[N];
void init() {
  for (int i = (0); i < (n); ++i) {
    vector<int>().swap(adj[i]);
    vector<int>().swap(dis[i]);
    dis[i].resize(N);
  }
}
vector<int> cnt;
long long getDP(int sub) {
  long long dp[sub + 2][k + 1];
  for (int i = (0); i < (sub + 2); ++i) {
    for (int j = (0); j < (k + 1); ++j) {
      dp[i][j] = 0;
    }
  }
  dp[0][0] = 1;
  for (int i = (0); i < (sub); ++i) {
    for (int j = 0; j <= k; ++j) {
      dp[i + 1][j] += dp[i][j];
      dp[i + 1][j] %= MOD;
      dp[i + 1][j + 1] += mul(dp[i][j], cnt[i]);
      dp[i + 1][j + 1] %= MOD;
    }
  }
  return dp[sub][k];
}
void sol() {
  cin >> n >> k;
  for (int i = (0); i < (n); ++i) {
    dis[i].resize(n);
  }
  for (int i = (1); i < (n); ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  long long ans = 0;
  if (k == 2) {
    ans = (1ll * n * (n - 1) / 2) % MOD;
  } else {
    bool vis[n];
    for (int center = (0); center < (n); ++center) {
      for (int i = (0); i < (n); ++i) {
        vis[i] = false;
      }
      vis[center] = true;
      vector<pair<int, int> > layer;
      vector<int>(n).swap(cnt);
      int sz = adj[center].size();
      for (int i = (0); i < (sz); ++i) {
        vis[adj[center][i]] = true;
        layer.emplace_back(i, adj[center][i]);
        cnt[i] = 1;
      }
      while (!layer.empty()) {
        ans += getDP(sz);
        ans %= MOD;
        vector<pair<int, int> > next_layer;
        for (pair<int, int> e : layer) {
          --cnt[e.first];
          for (int to : adj[e.second]) {
            if (vis[to]) continue;
            ++cnt[e.first];
            next_layer.emplace_back(e.first, to);
            vis[to] = true;
          }
        }
        swap(next_layer, layer);
        vector<pair<int, int> >().swap(next_layer);
      }
    }
  }
  cout << ans << endl;
  init();
}
int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  for (; t; --t) {
    sol();
  }
  return 0;
}
