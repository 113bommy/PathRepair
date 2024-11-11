#include <bits/stdc++.h>
using namespace std;
int n, e;
vector<pair<long long, long long> > d;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> e;
  int x, y;
  for (int i = 0; i < e; i++) {
    cin >> x >> y;
    d.push_back(pair<long long, long long>(x, y));
  }
  for (int i = 0; i < e - 1; i++)
    if (d[i + 1].first - d[i].first < abs(d[i + 1].second - d[i].second)) {
      cout << "IMPOSSIBLE";
      return 0;
    }
  long long ma =
      max(d[0].first + d[0].second - 1, n - d[e - 1].first + d[e - 1].second);
  for (int i = 0; i < e - 1; i++)
    ma = max(
        ma,
        (d[i + 1].first - d[i].first - abs(d[i + 1].second - d[i].second)) / 2 +
            max(d[i + 1].second, d[i].second));
  cout << ma;
  return 0;
}
