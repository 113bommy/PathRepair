#include <bits/stdc++.h>
using namespace std;
vector<long long> g[200100];
bool visited[200100];
long long M = 1e9 + 7;
long long solve(long long src) {
  long long res = 2;
  if (src == 1) res = 1;
  long long i, ans = 1;
  visited[src] = 1;
  for (i = 0; i < g[src].size(); i++) {
    long long v = g[src][i];
    if (visited[v]) continue;
    ans *= res;
    ans %= M;
    res++;
    ans *= solve(v);
    ans %= M;
  }
  return ans;
}
int main() {
  long long t, n, i, j, k, l, m;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  t = 1;
  while (t--) {
    cin >> n;
    for (i = 1; i <= n; i++) {
      cin >> j >> k;
      g[j].push_back(k);
      g[k].push_back(j);
    }
    cout << (solve(1) * n) % M << '\n';
  }
  return 0;
}
