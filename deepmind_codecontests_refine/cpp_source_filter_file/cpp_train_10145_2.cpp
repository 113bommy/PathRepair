#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long>> a[100005];
long long v[100005];
bool b[100005];
priority_queue<pair<pair<long long, long long>, bool>> h;
int main() {
  long long n, m, k, i, x, y, w, second = 0;
  cin >> n >> m >> k;
  for (i = 1; i <= m; ++i) {
    cin >> x >> y >> w;
    a[x].push_back({y, w});
    a[y].push_back({x, w});
  }
  for (i = 1; i <= k; ++i) {
    cin >> x >> w;
    if (!b[x] || (b[i] && b[x] > w)) {
      v[x] = w;
      b[x] = 1;
      h.push({{-w, x}, 0});
    } else
      ++second;
  }
  h.push({{0, 1}, 1});
  while (h.size()) {
    w = -h.top().first.first;
    i = h.top().first.second;
    y = h.top().second;
    h.pop();
    if (v[i] != -1) {
      v[i] = -1;
      for (auto it : a[i]) {
        if (!v[it.first] || (w + it.second <= v[it.first])) {
          v[it.first] = w + it.second;
          h.push({{-v[it.first], it.first}, 1});
        }
      }
    } else if (b[i] && !y)
      ++second;
  }
  cout << second;
  return 0;
}
