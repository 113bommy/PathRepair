#include <bits/stdc++.h>
using namespace std;
const int maxn = 110, mod = 1e9 + 7;
const long long inf = 1e18;
int a[maxn][maxn];
vector<pair<int, int> > v;
vector<int> ans;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie();
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
    for (int j = 0; j < n - 1; j++) {
      a[i][j] -= a[i][n - 1];
    }
  }
  for (int i = 0; i < m; i++) {
    ans.push_back(i);
  }
  for (int i = 0; i < n - 1; i++) {
    v.clear();
    for (int j = 0; j < m; j++) {
      v.push_back({a[j][i], j});
    }
    sort(v.begin(), v.end(), greater<pair<int, int> >());
    int sm = 0, pt = 0;
    while (pt < int((v).size()) && sm >= 0) {
      sm += v[pt].first;
      pt++;
    }
    if (sm < 0) pt--;
    if (int((ans).size()) > m - pt) {
      ans.clear();
      while (pt < int((v).size())) ans.push_back(v[pt].second), pt++;
    }
  }
  cout << int((ans).size()) << "\n";
  for (int x : ans) {
    cout << x + 1 << " ";
  }
  return cout << endl, 0;
}
