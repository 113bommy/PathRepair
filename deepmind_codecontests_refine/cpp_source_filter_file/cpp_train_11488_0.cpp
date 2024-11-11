#include <bits/stdc++.h>
using namespace std;
int const N = 10 + 5, M = 100 + 20;
int n, m, k, a[N][M], b[N][M], c[N][M], ans;
string s;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++) cin >> a[i][j] >> b[i][j] >> c[i][j];
  }
  for (int p1 = 0; p1 < n; p1++) {
    for (int p2 = 0; p2 < n; p2++) {
      vector<pair<int, int> > v;
      for (int i = 0; i < m; i++)
        v.push_back({max(0, b[p2][i] - a[p1][i]), c[p1][i]});
      sort(v.begin(), v.end());
      int rem = k, pr = 0;
      for (int i = v.size() - 1; i >= 0; i--) {
        if (rem > v[i].second)
          pr += v[i].first * v[i].second, rem -= v[i].second;
        else
          pr += v[i].first * rem;
      }
      ans = max(ans, pr);
    }
  }
  return cout << ans << endl, 0;
}
