#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 100, P = 1e9 + 7, INF = 2e18;
const double ESP = 1. / 10000000000.;
long long n, k, m, ans, used[N], t[N];
vector<long long> d[N];
map<long long, long long> mp;
long long dfs(long long v) {
  used[v] = 1;
  long long sum = 0;
  if (mp[v] == 1) {
    sum++;
  }
  for (auto x : d[v]) {
    if (!used[x]) {
      sum += dfs(x);
    }
  }
  ans += min(sum, k / 2);
  return sum;
}
int main() {
  cin >> n >> k;
  for (long long i = 1; i <= k * 2; i++) {
    cin >> t[i];
    mp[t[i]] = 1;
  }
  for (long long i = 1; i < n; i++) {
    long long a, b;
    cin >> a >> b;
    d[a].push_back(b);
    d[b].push_back(a);
  }
  dfs(1);
  cout << ans;
}
