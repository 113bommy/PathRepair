#include <bits/stdc++.h>
using namespace std;
long long n, m, k, mod = 1e9 + 7;
map<long long, long long> mp;
string s;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  srand(time(0));
  cin >> n >> k;
  vector<long long> a(n + 2);
  vector<long long> b(k + 2);
  for (long long i = 1; i <= n; ++i) cin >> a[i], a[i] -= i;
  a[0] = -2e9;
  a[n + 1] = 2e9;
  b[k + 1] = n + 1;
  for (long long i = 1; i <= k; ++i) cin >> b[i];
  long long ans = 0;
  for (long long i = 0; i <= k; ++i) {
    long long l = b[i];
    long long r = b[i + 1];
    if (a[l] > a[r]) {
      cout << -1;
      exit(0);
    }
    vector<long long> v;
    for (long long j = l + 1; j < r; ++j) {
      if (a[j] > a[r] || a[j] < a[l]) continue;
      auto x = lower_bound(v.begin(), v.end(), a[j]);
      if (x == v.end())
        v.push_back(a[j]);
      else
        *x = a[j];
    }
    ans += r - l - 1 - v.size();
  }
  cout << ans;
}
