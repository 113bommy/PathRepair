#include <bits/stdc++.h>
using namespace std;
long long rr[] = {0, 1, 1, 1, 0, -1, -1, -1};
long long cc[] = {1, 1, 0, -1, -1, -1, 0, 1};
const long long mod = 1e9 + 7;
const long long N = 300050;
vector<long long> vis, dis;
vector<vector<long long> > adj;
void dfs(long long node) {
  vis[node] = 1;
  for (long long child : adj[node]) {
    if (!vis[child]) {
      dis[child] = dis[node] + 1;
      dfs(child);
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long test = 1;
  cin >> test;
  while (test--) {
    long long n;
    cin >> n;
    dis = vis = vector<long long>(n + 1, 0);
    adj = vector<vector<long long> >(n + 1);
    for (long long i = 0; i < n - 1; i++) {
      long long a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    long long k1;
    cin >> k1;
    long long x[k1];
    for (long long i = 0; i < k1; i++) {
      cin >> x[i];
    }
    long long k2;
    cin >> k2;
    long long y[k2];
    for (long long i = 0; i < k2; i++) {
      cin >> y[i];
    }
    cout << "B " << y[0] << endl;
    long long X;
    cin >> X;
    dfs(X);
    long long mx = INT_MAX, Y;
    for (long long i = 0; i < k1; i++) {
      if (mx > dis[x[i]]) {
        X = x[i];
        mx = dis[x[i]];
      }
    }
    cout << "A " << X << endl;
    cin >> Y;
    long long ok = 0;
    for (long long i = 0; i < k2; i++) {
      if (Y == y[i]) {
        ok = 1;
      }
    }
    if (ok) {
      cout << "B " << Y << endl;
      cin >> Y;
      cout << "C " << Y << endl;
    } else
      cout << "C " << -1 << endl;
  }
  return 0;
}
