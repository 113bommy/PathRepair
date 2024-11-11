#include <bits/stdc++.h>
using namespace std;
const long long INF = LLONG_MAX;
const long long SZ = 1e4 + 5;
const long long mod = 1e9 + 7;
string s, s1, s2;
long long n, m, k, ans = 0;
long long f1[SZ], f2[SZ];
priority_queue<pair<long long, pair<long long, long long> > > pq;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long cs = 0, tc = 1, x, y, z, i, j, g, p, q, sum = 0, c = 0, t = 0;
  cin >> n >> m;
  for (i = 1; i <= m; i++) {
    cin >> x >> y >> z;
    pq.push({z, {x, y}});
    f1[x]++, f2[y]++;
  }
  for (i = 1; i <= n; i++) {
    if (!f1[i] || !f2[i]) {
      cout << "-1\n";
      return 0;
    }
  }
  while (!pq.empty()) {
    auto p = pq.top();
    pq.pop();
    long long d = p.first, u = p.second.first, v = p.second.second;
    if (f1[u] == 1 || f2[v] == 1) {
      ans = max(ans, d);
      continue;
    }
    f1[u]--, f2[v]--;
  }
  for (i = 1; i <= n; i++) {
    if (!f1[i] || !f2[i]) {
      cout << "-1\n";
      return 0;
    }
  }
  cout << ans << "\n";
  return 0;
}
