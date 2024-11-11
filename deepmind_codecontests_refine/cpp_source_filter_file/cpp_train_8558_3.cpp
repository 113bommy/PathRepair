#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
const int MOD = 1e9 + 7;
const double PI = 3.141592653589793238460;
long long power(long long a, long long b) {
  long long res = 1;
  if (a == 0) return 0;
  if (a == 1) return 1;
  for (; b > 0; b >>= 1) {
    if (b & 1) res = (res * a);
    if (res > MOD) res %= MOD;
    a = (a * a);
    if (a > MOD) a = a % MOD;
  }
  return res;
}
bool isPrime[1000000 + 1];
vector<long long> prime;
void seive(int limit) {
  isPrime[0] = isPrime[1] = 1;
  for (int i = 2; i * i <= limit; i++) {
    if (!isPrime[i])
      for (int j = i * i; j <= limit; j += i) {
        isPrime[j] = 1;
      }
  }
  for (int i = 2; i <= limit; i++)
    if (!isPrime[i]) prime.push_back(i);
}
int ls;
int maxi = 0;
int mark[300000];
int visited[300000];
void dfsl(int x, vector<int> adj[], int n, int p = -1, int mx = 0) {
  if (mx > maxi) {
    maxi = mx;
    ls = x;
  }
  for (int y : adj[x]) {
    if (y == p) continue;
    dfsl(y, adj, n, x, mx + 1);
  }
}
int parent[300000];
pair<int, int> dfs(int x, vector<int> adj[], int d = 0, int p = -1) {
  pair<int, int> res = {d, x};
  parent[x] = p;
  for (int y : adj[x]) {
    if (y == p) continue;
    res = max(res, dfs(y, adj, d + 1, x));
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int tt;
  tt = 1;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> adj[n + 1];
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      adj[v].push_back(u);
      adj[u].push_back(v);
    }
    pair<int, int> da = dfs(1, adj);
    pair<int, int> db = dfs(da.second, adj);
    vector<int> v;
    int x = db.second;
    while (x != da.second) {
      v.push_back(x);
      x = parent[x];
    }
    v.push_back(da.second);
    if (v.size() == n) {
      cout << n - 1 << "\n";
      cout << v[0] << ' ' << v[1] << ' ' << v.back();
      return 0;
    }
    queue<int> q;
    for (int i = 0; i < v.size(); i++) q.push(v[i]);
    vector<int> d(n + 1, -1);
    for (int i = 0; i < v.size(); i++) d[v[i]] = 0;
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (int y : adj[x]) {
        if (d[y] == -1) {
          d[y] = d[x] + 1;
          q.push(y);
        }
      }
    }
    pair<int, int> ans = {0, 0};
    for (int i = 1; i <= n; i++) {
      ans = max(ans, {d[i], i});
    }
    cout << (int)v.size() - 1 + ans.first << "\n";
    cout << v[0] << ' ' << ans.second << ' ' << v[1] << "\n";
  }
}
