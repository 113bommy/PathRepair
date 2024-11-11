#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, i, j, k, x, y, m, curr, c, id;
  cin >> n;
  vector<long long> ct(n), v(n, 0);
  vector<vector<long long>> a(n);
  for (i = 0; i < n; i++) {
    cin >> ct[i];
    a[i].resize(ct[i]);
    cin >> a[i][0] >> x >> y >> m;
    for (j = 1; j < ct[i]; j++) {
      a[i][j] = (a[i][j - 1] * x + y) % m;
    }
  }
  priority_queue<pair<long long, long long>> pq;
  queue<pair<long long, long long>> q;
  vector<pair<long long, long long>> ans;
  c = 0;
  curr = 0;
  for (i = 0; i < n; i++) pq.push({-a[i][0], i});
  while (!pq.empty() || !q.empty()) {
    if (pq.empty()) {
      c++;
      curr = 0;
      while (!q.empty()) {
        pq.push(q.front());
        q.pop();
      }
    }
    while (!pq.empty()) {
      x = -pq.top().first;
      id = pq.top().second;
      pq.pop();
      ans.push_back({x, id});
      curr = x;
      v[id]++;
      if (v[id] < ct[id]) {
        if (a[id][v[id]] < curr)
          q.push({-a[id][v[id]], id});
        else
          pq.push({-a[id][v[id]], id});
      }
    }
  }
  cout << c << "\n";
  for (auto p : ans) cout << p.first << " " << p.second + 1 << "\n";
  return 0;
}
