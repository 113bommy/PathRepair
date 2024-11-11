#include <bits/stdc++.h>
using namespace std;
queue<long long> q;
long long n, m;
long long x[100005], y[100005], z[100005];
long long d[100005], dp[100005];
bool done[100005];
pair<long long, long long> leo[100005];
vector<pair<long long, long long> > g[100005], v;
void bfs(long long s) {
  for (long long i = 0; i < n; i++) {
    d[i] = 1000000007;
  }
  d[s] = 0;
  q.push(0);
  while (!q.empty()) {
    long long u = q.front();
    q.pop();
    for (long long i = 0; i < g[u].size(); i++) {
      long long v = g[u][i].first;
      if (d[v] > d[u] + 1) {
        d[v] = d[u] + 1;
        q.push(v);
      }
    }
  }
}
int main() {
  scanf("%lld", &n);
  scanf("%lld", &m);
  long long work = 0;
  for (long long i = 0; i < m; i++) {
    scanf("%lld", &x[i]);
    scanf("%lld", &y[i]);
    scanf("%lld", &z[i]);
    x[i]--;
    y[i]--;
    work += z[i];
    g[x[i]].push_back(make_pair(y[i], i));
    g[y[i]].push_back(make_pair(x[i], i));
  }
  bfs(0);
  for (long long i = 0; i < n; i++) {
    v.push_back(make_pair(d[i], i));
    dp[i] = 1000000007;
  }
  sort(v.begin(), v.end());
  dp[0] = 0;
  for (long long i = 0; i < n; i++) {
    long long u = v[i].second;
    for (long long j = 0; j < g[u].size(); j++) {
      long long next = g[u][j].first;
      long long add = 1 - z[g[u][j].second];
      if (d[next] == d[u] + 1 && dp[next] > dp[u] + add) {
        dp[next] = dp[u] + add;
        leo[next] = make_pair(u, g[u][j].second);
      }
    }
  }
  long long ney = n - 1;
  while (ney != 0) {
    done[leo[ney].second] = true;
    ney = leo[ney].first;
  }
  cout << work - d[n - 1] + 2 * dp[n - 1] << "\n";
  for (long long i = 0; i < m; i++) {
    if (done[i] ^ z[i]) {
      cout << x[i] + 1 << " " << y[i] + 1 << " " << 1 - z[i] << "\n";
    }
  }
  return 0;
}
