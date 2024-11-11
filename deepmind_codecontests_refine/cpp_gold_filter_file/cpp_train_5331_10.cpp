#include <bits/stdc++.h>
using namespace std;
long long arr[105][105];
vector<long long> ans[105];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  while (t--) {
    long long n, m;
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> arr[i][j];
      }
    }
    for (int i = 0; i < m - 1; i++) {
      long long x = 0;
      vector<pair<long long, long long> > v;
      for (int j = 0; j < n; j++) {
        x += arr[j][i] - arr[j][m - 1];
        pair<long long, long long> p;
        p.first = arr[j][i] - arr[j][m - 1];
        p.second = j;
        v.push_back(p);
      }
      if (x >= 0) {
        cout << 0 << "\n";
        return 0;
      }
      sort((v).begin(), (v).end());
      for (int j = 0; j < n; j++) {
        x -= v[j].first;
        ans[i].push_back(v[j].second);
        if (x >= 0) {
          break;
        }
      }
    }
    long long mn = 1e18;
    for (int i = 0; i < m - 1; i++) {
      mn = min(mn, (long long)ans[i].size());
    }
    for (int i = 0; i < m - 1; i++) {
      if (mn == (long long)ans[i].size()) {
        cout << ans[i].size() << "\n";
        for (int j = 0; j < ans[i].size(); j++) {
          cout << ans[i][j] + 1 << " ";
        }
        break;
      }
    }
  }
  return 0;
}
