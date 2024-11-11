#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const int INF = INT_MAX;
const long long LLINF = 1000000000000000000LL;
const long long MAX = 105;
const long long MOD = 1000000007;
long long N, K, deg;
long long tree[MAX][MAX];
long long cache[MAX][MAX];
vector<int> adj[MAX];
bool visited[MAX];
void sub(long long i, long long d, long long idx) {
  tree[i][d]++;
  visited[idx] = true;
  for (auto& it : adj[idx]) {
    if (!visited[it]) {
      sub(i, d + 1, it);
    }
  }
}
long long DP(long long n, long long k, long long d) {
  if (k == 0) {
    return 1;
  }
  if (n == deg) {
    return 0;
  }
  long long& ret = cache[n][k];
  if (ret != -1) {
    return ret;
  }
  ret = DP(n + 1, k, d) + DP(n + 1, k - 1, d) * tree[n][d];
  ret %= MOD;
  return ret;
}
long long root(long long n) {
  deg = adj[n].size();
  visited[n] = true;
  int idx = 0;
  for (auto& it : adj[n]) {
    sub(idx, 0, it);
    ++idx;
  }
  long long ans = 0;
  for (int d = 0; d <= N; d++) {
    memset(cache, -1, sizeof(cache));
    ans += DP(0, K, d);
    ans %= MOD;
  }
  return ans;
}
void solve() {
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    adj[i].clear();
  }
  for (int i = 0; i < N - 1; i++) {
    long long a, b;
    cin >> a >> b;
    --a;
    --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  if (K == 2) {
    cout << N * (N - 1) / 2 << "\n";
    return;
  }
  long long ret = 0;
  for (int i = 0; i < N; i++) {
    if (adj[i].size() >= K) {
      memset(tree, 0, sizeof(tree));
      memset(visited, 0, sizeof(visited));
      ret += root(i);
      ret %= MOD;
    }
  }
  cout << ret << "\n";
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
