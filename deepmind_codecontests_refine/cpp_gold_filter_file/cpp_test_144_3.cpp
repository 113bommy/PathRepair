#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const long long N = 1e9;
const long long MOD = 1e9 + 7;
const long long inf = 2e9;
const long double eps = 1e-12;
const long double EPS = 1e-10;
long long rx[] = {1, -1, 0, 0};
long long ry[] = {0, 0, 1, -1};
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, k;
    cin >> n >> m >> k;
    if (n % m == 0) {
      while (k--) {
        long long d = n / m;
        for (long long i = 0; i < n / d; ++i) {
          cout << d << ' ';
          for (long long j = i * d; j < (i + 1) * d; ++j) cout << j + 1 << ' ';
          cout << '\n';
        }
      }
      continue;
    }
    vector<long long> v(n), cnt(n);
    long long g1 = n / m, g2 = n / m + 1;
    long long k1 = (m - n % m) * g1;
    for (long long i = 0; i < n; ++i) {
      v[i] = i;
      if (i < k1)
        cnt[i] = 0;
      else
        cnt[i] = 1;
    }
    while (k--) {
      bool ok = 1;
      for (long long i = 0; i < n; ++i) {
        if (i == k1) {
          ok = 0;
        }
        if (ok && i % g1 == 0) cout << '\n' << g1 << ' ';
        if (!ok && (i - k1) % g2 == 0) cout << '\n' << g2 << ' ';
        cout << v[i] + 1 << ' ';
      }
      cout << '\n';
      vector<pair<long long, long long> > a;
      for (long long i = 0; i < n; ++i) a.push_back({cnt[i], i});
      sort(a.rbegin(), a.rend());
      for (long long i = 0; i < n; ++i) {
        v[i] = a[i].second;
        if (i >= k1) cnt[v[i]]++;
      }
    }
  }
  return 0;
}
