#include <bits/stdc++.h>
using namespace std;
long long power(long long b, long long e, long long m) {
  if (e == 0) return 1;
  if (e & 1) return b * power(b * b % m, e / 2, m) % m;
  return power(b * b % m, e / 2, m);
}
long long power(long long b, long long e) {
  if (e == 0) return 1;
  if (e & 1) return b * power(b * b, e / 2);
  return power(b * b, e / 2);
}
int _runtimeTerror_() {
  long long n, i;
  string s;
  cin >> n >> s;
  vector<pair<long long, long long>> v;
  for (i = 0; i < n; ++i) {
    if (s[i] == 'G') {
      long long j = i;
      while (i < n && s[i] == 'G') ++i;
      v.push_back({j, i - 1});
    }
  }
  if ((long long)v.size() == 0) {
    cout << 0;
    return 0;
  }
  long long kk = (long long)v.size();
  if (kk == 1) {
    cout << v[0].second - v[0].first + 1;
    return 0;
  }
  long long ans = 0;
  for (i = 0; i < kk - 1; ++i) {
    ans = max(ans, v[i].second - v[i].first + 1);
    if (v[i + 1].first - v[i].second == 2) {
      if ((long long)v.size() > 2) {
        ans = max(ans, v[i + 1].second - v[i].first + 1);
      } else
        ans = max(ans, v[i + 1].second - v[i].first);
    }
    if ((long long)v.size() > 1) ans = max(ans, v[i].second - v[i].first + 2);
  }
  ans = max(ans, v[kk - 1].second - v[kk - 1].first + 1);
  cout << ans;
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  while (TESTS--) _runtimeTerror_();
  return 0;
}
