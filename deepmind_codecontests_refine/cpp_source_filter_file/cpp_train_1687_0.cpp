#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 7;
bool a[N];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  vector<long long> p;
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i]) p.push_back(i);
  }
  vector<long long> pri;
  long long sum = p.size();
  for (long long d = 2; d * d <= n; ++d)
    if (sum % d == 0) {
      pri.push_back(d);
      while (sum % d == 0) sum /= d;
    }
  if (sum > 1) pri.push_back(sum);
  const long long INF = 1e18 + 7;
  long long ans = INF;
  for (long long e : pri) {
    long long nn = 0;
    for (long long i = 0; i * e < pri.size(); ++i) {
      vector<long long> t;
      for (long long j = 0; j < e; ++j) t.push_back(p[i * e + j]);
      long long mid = t[e >> 1];
      for (long long e : t) nn += abs(mid - e);
    }
    ans = min(ans, nn);
  }
  if (ans == INF)
    cout << "-1\n";
  else
    cout << ans << '\n';
}
