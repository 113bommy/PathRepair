#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  cin >> s >> t;
  long long ns = s.size(), nt = t.size();
  vector<vector<long long>> v(nt);
  for (long long i = 0; i < nt; i++) {
    for (long long j = 0; j < ns; j++) {
      if (s[j] == t[i]) v[i].push_back(j);
    }
  }
  for (long long i = 1; i < nt; i++) {
    long long x =
        upper_bound(v[i].begin(), v[i].end(), v[i - 1][0]) - v[i].begin();
    auto it = v[i].begin();
    for (long long j = 0; j < x; j++) v[i].erase(it);
  }
  for (long long i = nt - 2; i > -1; i--) {
    long long x =
        lower_bound(v[i].begin(), v[i].end(), v[i + 1][v[i + 1].size() - 1]) -
        v[i].begin();
    auto it =
        lower_bound(v[i].begin(), v[i].end(), v[i + 1][v[i + 1].size() - 1]);
    long long si = v[i].size();
    for (long long j = x; j < si; j++) v[i].erase(it);
  }
  long long maxi = max(v[0][v[0].size() - 1], ns - v[nt - 1][0] - 1);
  for (long long i = 1; i < nt; i++) {
    maxi = max(maxi, (v[i][v[i].size() - 1] - v[i - 1][0] - 1));
  }
  cout << maxi << endl;
  return 0;
}
