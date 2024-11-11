#include <bits/stdc++.h>
using namespace std;
long long mM(long long a, long long b, long long p = 1000000007) {
  long long res = 0;
  if (a >= p) a %= p;
  while (b) {
    if (b & 1ll) res = (res + a);
    if (res >= p) res %= p;
    a = (2 * a);
    if (a >= p) a %= p;
    b >>= 1ll;
  }
  return res;
}
long long fpow(long long first, long long second, long long p = 1000000007) {
  if (first >= p) first = first % p;
  long long res = 1;
  while (second) {
    if (second & 1ll) res *= first;
    if (res < 0) res += p;
    if (res >= p) res %= p;
    second = second >> 1ll;
    first *= first;
    if (first < 0) first += p;
    if (first >= p) first %= p;
  }
  return res;
}
long long inv(long long n, long long p = 1000000007) {
  return fpow(n, p - 2, p);
}
long long modmul(long long first, long long second, long long p = 1000000007) {
  if (first < 0) first += p;
  if (first >= p) first %= p;
  if (second < 0) second += p;
  if (second >= p) second %= p;
  return (first * second) % p;
}
long long modadd(long long first, long long second, long long p = 1000000007) {
  if (first < 0) first += p;
  if (first >= p) first %= p;
  if (second < 0) second += p;
  if (second >= p) second %= p;
  long long temp = first + second;
  if (temp >= p) temp %= p;
  return temp;
}
long long d, n;
vector<int> val(2005, 0), visited(2005, 0), dp(2005, 0);
vector<vector<int> > adj(2005, vector<int>());
void dfs(int src, int root) {
  visited[src]++;
  dp[src] = 1;
  for (auto e : adj[src])
    if (!visited[e] && (val[e] >= val[root] && val[e] <= val[root] + d) &&
        (val[e] != val[root] || root < e)) {
      dfs(e, root);
      dp[src] = modmul(dp[src], dp[e] + 1);
    }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1, tc = 0;
  while (t--) {
    cin >> d >> n;
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dp[j] = 0;
        visited[j] = 0;
      }
      dfs(i, i);
      ans = modadd(ans, dp[i]);
    }
    cout << ans << "\n";
  }
}
