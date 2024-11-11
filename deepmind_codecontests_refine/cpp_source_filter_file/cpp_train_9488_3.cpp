#include <bits/stdc++.h>
using namespace std;
const long long maxn = (long long)1e9 + 7;
const long double EPS = 1e-9;
const long long INF = (long long)1e18 + 18;
const long long mod = (long long)1e9 + 7;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, m, sum = 0;
  cin >> n >> m;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    sum += v[i];
  }
  if (sum < m) {
    cout << -1 << '\n';
    return 0;
  }
  long long p = INF;
  sort(v.begin(), v.end(), greater<long long>());
  long long l = 1, h = n;
  while (h > l) {
    long long i = (l + h) / 2;
    vector<long long> a(i);
    for (long long j = 0; j < v.size(); j++) {
      long long q = j / i;
      long long r = j % i;
      a[r] += max((v[j] - q), 0LL);
    }
    long long cute = accumulate(a.begin(), a.end(), 0LL);
    if (cute >= m) {
      h = i;
      p = min(i, p);
    } else
      l = i + 1;
  }
  cout << p << '\n';
}
