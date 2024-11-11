#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  std::ios::sync_with_stdio(false);
  long long n, m, x, y;
  vector<pair<long long, long long> > v;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    v.push_back({x, y});
  }
  long long day = v[0].first, h = v[0].second,
            maxx = v[0].second + v[0].first - 1;
  for (int i = 0; i < v.size(); i++) {
    long long lasth = h;
    while (abs(h - v[i].second) + h - lasth <= v[i].first - day) {
      h++;
    }
    h--;
    if (v[i].first - day < abs(h - v[i].second) + abs(h - lasth)) {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
    day = v[i].first;
    maxx = max(maxx, h);
    h = v[i].second;
    maxx = max(maxx, h);
  }
  maxx = max(maxx, h + n - day);
  cout << maxx << endl;
  return 0;
}
