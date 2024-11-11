#include <bits/stdc++.h>
using namespace std;
vector<long long> prime_factors[100005];
long long pr[100005], ans[100005];
void solve() {
  for (long long i = 2; i <= sqrt(100000); i++) {
    if (pr[i] == 0) {
      prime_factors[i].push_back(i);
      for (long long j = i * 2; j <= 100000; j += i)
        pr[j] = 1, prime_factors[j].push_back(i);
    }
  }
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  for (long long i = 0; i < n; i++) {
    long long mx = -1;
    for (long long j = 0; j < prime_factors[a[i]].size(); j++)
      mx = max(mx, ans[prime_factors[a[i]][j]]);
    for (long long j = 0; j < prime_factors[a[i]].size(); j++)
      ans[prime_factors[a[i]][j]] = mx + 1;
  }
  long long res = 0;
  for (long long i = 2; i <= 100000; i++) res = max(res, ans[i]);
  res = (res < 1) ? 1 : res;
  cout << res << '\n';
  return;
}
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  long long T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
