#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long maxn = 2e5 + 5, mod = 1e9 + 7, inf = mod;
long long n;
long long arr[maxn];
vector<long long> g[maxn];
long long S, T;
long long d[maxn];
long long par[maxn][19];
long long s[maxn][19];
long long to[maxn];
pair<long long, long long> solve(long long i, long long p) {
  long long sum = 0;
  long long mn = inf;
  for (long long j : g[i]) {
    if (j != p) {
      pair<long long, long long> t = solve(j, i);
      sum += t.first;
      mn = min(mn, t.second);
    }
  }
  if (mn > d[i]) return {sum + 1, to[i]};
  return {sum, mn};
}
void dfs(long long i, long long p) {
  par[i][0] = p;
  s[i][0] = arr[p];
  for (long long bit = (long long)1; bit <= (long long)19; bit++) {
    par[i][bit] = par[par[i][bit - 1]][bit - 1];
    s[i][bit] = s[i][bit - 1] + s[par[i][bit - 1]][bit - 1];
  }
  long long now = i;
  long long sum = arr[i];
  d[i] = d[p] + 1;
  for (long long bit = (long long)19; bit >= (long long)0; bit--) {
    if (sum + s[now][bit] > S) continue;
    sum += s[now][bit];
    now = par[now][bit];
  }
  to[i] = max(d[i] - T + 1, d[now]);
  for (long long j : g[i]) {
    if (j != p) dfs(j, i);
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> T >> S;
  for (long long i = (long long)1; i <= (long long)n; i++) cin >> arr[i];
  if (*max_element(arr + 1, arr + n + 1) > S) return cout << -1, 0;
  for (long long i = (long long)2; i <= (long long)n; i++) {
    long long p;
    cin >> p;
    g[p].emplace_back(i);
  }
  dfs(1, 1);
  cout << solve(1, 1).first << '\n';
}
