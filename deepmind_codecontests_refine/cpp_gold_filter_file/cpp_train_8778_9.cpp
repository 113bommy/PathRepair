#include <bits/stdc++.h>
using namespace std;
bool comp(pair<long long, long long> &p1, pair<long long, long long> &p2) {
  return p1.second > p2.second;
}
int32_t main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed;
  long long n, m;
  cin >> n >> m;
  vector<pair<long long, long long> > v(m);
  for (long long i = 0; i < m; i++) {
    cin >> v[i].first >> v[i].second;
  }
  sort(v.begin(), v.end(), comp);
  long long ans = 0;
  for (long long i = 0; i < m; i++) {
    if (n - v[i].first < 0) {
      ans += n * v[i].second;
      break;
    }
    ans += v[i].first * v[i].second;
    n -= v[i].first;
  }
  cout << ans;
}
