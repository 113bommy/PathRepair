#include <bits/stdc++.h>
using namespace std;
const long long N = 200 + 30, Mod = 1e9 + 7;
const long long SQ = 330;
long long a[N][N];
vector<long long> ans;
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  long long n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) ans.push_back(i);
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int k = 1; k < n; k++) {
    vector<pair<long long, long long> > v;
    long long cnt = 0;
    for (int i = 1; i <= m; i++) {
      cnt += a[i][n];
      cnt -= a[i][k];
      v.push_back({a[i][n] - a[i][k], i});
    }
    if (cnt <= 0) {
      ans.clear();
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    long long res = 0;
    long long po = 0;
    while (cnt > 0) {
      cnt -= (v[po].first);
      po++;
      res++;
    }
    if (res < ans.size()) {
      ans.clear();
      for (int i = 0; i < po; i++) ans.push_back(v[po].second);
    }
  }
  cout << ans.size() << endl;
  for (auto u : ans) cout << u << ' ';
  return (0);
}
