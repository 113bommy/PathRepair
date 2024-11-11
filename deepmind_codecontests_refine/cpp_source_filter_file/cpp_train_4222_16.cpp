#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, x;
  cin >> n;
  pair<long long, long long> p[n + 1];
  map<long long, long long> m, m1;
  for (long long i = 0; i < n; i++) cin >> x, m[x] = i + 1;
  for (long long i = 0; i < n; i++) cin >> x, m1[x] = i + 1;
  for (long long i = 1; i < n + 1; i++) p[i].first = m[i], p[i].second = m1[i];
  sort(p, p + n);
  long long ans = 0;
  vector<long long> v(n + 5);
  for (long long i = 0; i < n + 5; i++) v[i] = 1e18;
  for (long long j = n; j >= 1; j--) {
    long long k = p[j].second;
    *lower_bound(v.begin(), v.end(), k) = k;
  }
  for (long long i = 0; i < n + 3; i++) {
    if (v[i] == 1e18) {
      cout << i;
      return 0;
    }
  }
  return 0;
}
