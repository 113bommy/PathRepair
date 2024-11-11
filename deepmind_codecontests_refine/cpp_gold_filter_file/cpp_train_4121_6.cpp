#include <bits/stdc++.h>
using namespace std;
const long long MX = (1 << 20);
long long dp[MX][2], diam[MX];
long long n, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
long long solx[MX], soly[MX];
vector<long long> v[MX];
void Pdfs(long long x, long long p) {
  for (auto nxt : v[x]) {
    if (nxt == p) continue;
    Pdfs(nxt, x);
    dp[x][1] = max(dp[x][1], dp[nxt][0] + 1);
    if (dp[x][1] > dp[x][0]) swap(dp[x][1], dp[x][0]);
    diam[x] = max(diam[x], diam[nxt]);
  }
  diam[x] = max(diam[x], dp[x][0] + dp[x][1]);
  diam[x] = max(diam[x], 1ll);
}
void dfs(long long node, long long par, long long dpar, long long X,
         long long Y) {
  solx[node] = X, soly[node] = Y;
  long long d = dpar;
  for (auto nxt : v[node]) {
    if (nxt == par) continue;
    d++;
    d %= 4;
    dfs(nxt, node, d ^ 1, X + dx[d] * diam[nxt], Y + dy[d] * diam[nxt]);
  }
}
int main() {
  cin >> n;
  for (long long j = 1; j < n; j++) {
    long long a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for (long long j = 1; j <= n; j++) {
    if (v[j].size() > 4) {
      puts("NO");
      return 0;
    }
  }
  Pdfs(1, -1);
  puts("YES");
  dfs(1, -1, -1, 0, 0);
  for (long long j = 1; j <= n; j++) cout << solx[j] << ' ' << soly[j] << endl;
}
