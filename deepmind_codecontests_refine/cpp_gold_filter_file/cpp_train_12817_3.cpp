#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long int M = 1e9 + 7;
long long int MOD = 998244353;
const double PI = 3.141592653589793238460;
bitset<N> bs;
vector<int> adj[300001];
long long int dp1[300010], dp2[300010];
map<pair<long long int, long long int>, long long int> m;
long long int val[300010];
long long int maxa = 0;
void dfs(int s, int p) {
  for (int x : adj[s]) {
    if (x == p) continue;
    dfs(x, s);
    long long int tmp = dp1[x] - m[{x, s}];
    if (tmp >= dp1[s]) {
      dp2[s] = dp1[s];
      dp1[s] = tmp;
    } else if (dp2[s] < tmp)
      dp2[s] = tmp;
  }
  dp1[s] += val[s], dp2[s] += val[s];
}
int main() {
  long long int n, u, v, w;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> val[i];
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v >> w;
    adj[u].push_back(v);
    adj[v].push_back(u);
    m[{u, v}] = w;
    m[{v, u}] = w;
  }
  dfs(1, 0);
  for (int i = 1; i <= n; i++) maxa = max(maxa, dp1[i] + dp2[i] - val[i]);
  cout << maxa;
}
