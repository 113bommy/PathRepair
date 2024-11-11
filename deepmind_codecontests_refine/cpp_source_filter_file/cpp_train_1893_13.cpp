#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long mod = 1e9 + 7;
long long dist[103][103];
void floydwarshall(long long n) {
  long long i, j, k;
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j)
      for (k = 1; k <= n; ++k)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long i, j;
  char ch;
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j)
      cin >> ch, dist[i][j] = (ch == '1' ? 1 : (long long)1e9);
  for (i = 1; i <= n; ++i) dist[i][i] = 0;
  floydwarshall(n);
  long long m;
  cin >> m;
  long long p[m + 1];
  for (i = 1; i <= m; ++i) cin >> p[i];
  vector<long long> ans;
  ans.clear();
  ans.push_back(p[1]);
  long long prev = p[1], ind = 1;
  for (i = 2; i <= m; ++i)
    if (dist[prev][p[i]] != i - ind)
      ans.push_back(p[i - 1]), prev = p[i - 1], ind = i - 1;
  ans.push_back(p[m]);
  cout << ans.size() << '\n';
  for (auto it : ans) cout << it << ' ';
  return 0;
}
