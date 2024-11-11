#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n), so(n);
  for (long long i = 0; i < n; ++i) {
    cin >> v[i];
    so[i] = v[i];
  }
  sort(so.begin(), so.end());
  long long m;
  cin >> m;
  for (long long i = 0; i < m; ++i) {
    long long k, pos;
    cin >> k >> pos;
    map<long long, long long> mp;
    for (long long j = n - k; j < n; ++j) {
      mp[v[j]]++;
    }
    for (long long j = 0; j < n; ++j) {
      if (mp.count(v[j]) and mp[v[j]] > 0) {
        --pos;
        mp[v[j]]--;
      }
      if (pos == 0) {
        cout << v[j] << endl;
        break;
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  { solve(); }
  return 0;
}
