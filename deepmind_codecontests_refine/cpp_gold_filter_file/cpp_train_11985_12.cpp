#include <bits/stdc++.h>
using namespace std;
void dfs(bool b[], long long height[], vector<long long> adj[],
         vector<pair<long long, long long> > pp[], long long x, long long pre[],
         long long a[]) {
  b[x] = true;
  pre[height[x]] += pre[height[x] - 1];
  vector<long long>::iterator it;
  vector<pair<long long, long long> >::iterator it2;
  for (it2 = pp[x].begin(); it2 != pp[x].end(); it2++) {
    pre[height[x]] += (*it2).second;
    long long temp = min(height[x] + (*it2).first + 1, (long long)(300000));
    pre[temp] -= (*it2).second;
  }
  a[x] = pre[height[x]];
  for (it = adj[x].begin(); it != adj[x].end(); it++) {
    if (!b[(*it)]) {
      height[(*it)] = height[x] + 1;
      dfs(b, height, adj, pp, (*it), pre, a);
    }
  }
  pre[height[x]] -= pre[height[x] - 1];
  for (it2 = pp[x].begin(); it2 != pp[x].end(); it2++) {
    pre[height[x]] -= (*it2).second;
    long long temp = min(height[x] + (*it2).first + 1, (long long)(300000));
    pre[temp] += (*it2).second;
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long n;
  cin >> n;
  vector<long long> adj[n + 1];
  long long a[n + 1];
  memset(a, 0, sizeof(a));
  for (long long i = 1; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  long long m;
  cin >> m;
  long long v[m + 1], d[m + 1], x[m + 1];
  vector<pair<long long, long long> > pp[n + 1];
  for (long long i = 1; i <= m; i++) {
    cin >> v[i] >> d[i] >> x[i];
    pp[v[i]].push_back({d[i], x[i]});
  }
  bool b[n + 1];
  long long height[n + 1];
  for (long long i = 1; i <= n; i++) {
    b[i] = false;
    height[i] = 1;
  }
  long long pre[300001];
  memset(pre, 0, sizeof(pre));
  dfs(b, height, adj, pp, 1, pre, a);
  for (long long i = 1; i <= n; i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
}
