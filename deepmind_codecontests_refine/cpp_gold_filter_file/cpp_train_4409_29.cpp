#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<pair<int, int>> p;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '*') {
        p.push_back({i + 1, j + 1});
      }
    }
  }
  sort(p.begin(), p.end());
  if (p[0].second == p[2].second && p[1].first == p[2].first &&
      p[0].first != p[1].first) {
    cout << p[0].first << " " << p[1].second;
  } else if (p[0].second == p[1].second && p[2].first == p[1].first &&
             p[0].first != p[2].first) {
    cout << p[0].first << " " << p[2].second;
  } else if (p[1].second == p[2].second && p[0].first == p[1].first &&
             p[0].first != p[2].first) {
    cout << p[2].first << " " << p[0].second;
  } else if (p[0].second == p[2].second && p[0].first == p[1].first &&
             p[1].first != p[2].first) {
    cout << p[2].first << " " << p[1].second;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
