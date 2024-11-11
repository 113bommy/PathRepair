#include <bits/stdc++.h>
using namespace std;
long long z = 1e9 + 7;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long power(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = (res * a) % z;
      b--;
    } else {
      a = (a * a) % z;
      b = b >> 1;
    }
  }
  return res;
}
long long n, k, ans = 0, p1;
long long dist[50005][505] = {0};
vector<long long> v[50001];
void dfs(long long u, long long p = -1) {
  dist[u][0] = 1;
  for (long long i = 0; i < v[u].size(); i++) {
    if (v[u][i] == p) continue;
    dfs(v[u][i], u);
    for (long long j = 1; j <= k + 1; j++) dist[u][j] += dist[v[u][i]][j - 1];
  }
  for (long long i = 0; i < v[u].size(); i++) {
    if (v[u][i] == p) continue;
    for (long long j = 1; j <= k - 1; j++)
      ans += (dist[u][j] - dist[v[u][i]][j - 1]) * dist[v[u][i]][k - j - 1];
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  t = 1;
  while (t--) {
    cin >> n >> k;
    long long x, y;
    for (long long i = 1; i < n; i++) {
      cin >> x >> y;
      v[x].push_back(y);
      v[y].push_back(x);
    }
    dfs(1);
    ans /= 2;
    for (long long i = 1; i <= n; i++) ans += dist[i][k];
    cout << ans << "\n";
  }
}
