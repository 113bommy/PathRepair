#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  long long mod = 1e9 + 7;
  cin >> n >> m;
  vector<pair<long long, long long> > bus(m);
  vector<long long> end(m);
  vector<long long> a(m), s(m + 1);
  for (long long i = 0; i < m; i++) {
    long long s, t;
    cin >> s >> t;
    bus[i] = make_pair(t, s);
    end[i] = t;
  }
  s[0] = 0;
  sort(end.begin(), end.end());
  sort(bus.begin(), bus.end());
  for (long long i = 0; i < m; i++) {
    long long t =
        lower_bound(end.begin(), end.end(), bus[i].second) - end.begin();
    long long e =
        lower_bound(end.begin(), end.end(), bus[i].first) - end.begin();
    a[i] = (s[e] - s[t] + mod + (bus[i].second == 0 ? 1 : 0)) % mod;
    s[i + 1] = (mod + a[i] + s[i]) % mod;
  }
  long long r = 0;
  for (long long i = m - 1; i >= 0; i--)
    if (bus[i].first == n) r = (r + a[i] + mod) % mod;
  cout << r << endl;
  return 0;
}
