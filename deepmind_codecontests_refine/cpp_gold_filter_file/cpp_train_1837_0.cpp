#include <bits/stdc++.h>
using namespace std;
int n, m, r;
long long cover(int x, int y) {
  return (min(x, n - r) - max(0, x - r + 1) + 1) *
         (min(y, m - r) - max(0, y - r + 1) + 1);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int k;
  cin >> n >> m >> r >> k;
  priority_queue<pair<long long, pair<int, int> > > pq;
  int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  pq.push(make_pair(cover(n / 2, m / 2), make_pair(n / 2, m / 2)));
  long double ans = 0;
  set<pair<int, int> > visited;
  visited.insert(make_pair(n / 2, m / 2));
  while (!pq.empty()) {
    pair<long long, pair<int, int> > p = pq.top();
    pq.pop();
    ans += p.first;
    k--;
    if (k == 0) break;
    for (int i = 0; i < 4; i++) {
      int x1 = p.second.first + dir[i][0], y1 = p.second.second + dir[i][1];
      if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m &&
          visited.find(make_pair(x1, y1)) == visited.end()) {
        visited.insert(make_pair(x1, y1));
        pq.push(make_pair(cover(x1, y1), make_pair(x1, y1)));
      }
    }
  }
  cout << fixed << setprecision(10) << ans / (1ll * (n - r + 1) * (m - r + 1))
       << endl;
  return 0;
}
