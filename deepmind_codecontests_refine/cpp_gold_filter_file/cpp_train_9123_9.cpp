#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long double n, w, m;
  cin >> n >> w >> m;
  long double vol = (n * w) / m;
  vector<vector<pair<long long, long double>>> ans(m);
  long long bottle = 1;
  long double volume = w;
  long long count = 0;
  map<long long, set<long long>> mm;
  for (long long i = 0; i < m; i++) {
    long double gv = vol;
    while (gv > 1e-6) {
      long double pour = min(gv, volume);
      gv -= pour;
      volume -= pour;
      ans[i].push_back({bottle, pour});
      mm[bottle].insert(i);
      if (volume < 1e-6) {
        volume = w;
        bottle++;
      }
    }
  }
  for (auto a : mm) {
    if (a.second.size() > 2) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES" << endl;
  for (long long i = 0; i < m; i++) {
    for (long long j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j].first << " ";
      cout << fixed << setprecision(10) << ans[i][j].second << " ";
    }
    cout << endl;
  }
  return 0;
}
