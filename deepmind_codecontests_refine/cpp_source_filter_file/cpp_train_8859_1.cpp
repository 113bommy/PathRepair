#include <bits/stdc++.h>
using namespace std;
class comp {
 public:
  bool operator()(vector<int> &v1, vector<int> &v2) { return (v1 > v2); }
};
vector<pair<int, int>> nei = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<int> nleft = {0, 0, 0, 1}, nright = {0, 0, 1, 0};
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m, r, c, x, y;
  cin >> n >> m >> r >> c >> x >> y;
  vector<vector<bool>> grid(n + 1, vector<bool>(m + 1, true));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c;
      cin >> c;
      if (c == '*') {
        grid[i][j] = false;
      }
    }
  }
  vector<vector<pair<int, int>>> seen(
      n + 1, vector<pair<int, int>>(m + 1, {LLONG_MAX, LLONG_MAX}));
  priority_queue<vector<int>, vector<vector<int>>, comp> pq;
  pq.push({0, 0, r, c});
  seen[r][c] = {0, 0};
  while (!pq.empty()) {
    vector<int> curr;
    bool flag = true;
    while (!pq.empty()) {
      curr = pq.top();
      if (seen[curr[2]][curr[3]] < make_pair(curr[0], curr[1])) {
        pq.pop();
      } else {
        flag = false;
        break;
      }
    }
    pq.pop();
    if (flag) {
      break;
    }
    for (int k = 0; k < 4; k++) {
      int rr = curr[2] + nei[k].first, cc = curr[3] + nei[k].second;
      if (rr > n || rr < 1 || cc > m || cc < 1 || !grid[rr][cc] ||
          curr[0] + nleft[k] > x ||
          seen[rr][cc] <= make_pair(curr[0] + nleft[k], curr[1] + nright[k])) {
        continue;
      }
      pq.push({curr[0] + nleft[k], curr[1] + nright[k], rr, cc});
      seen[rr][cc] = {curr[0] + nleft[k], curr[1] + nright[k]};
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (seen[i][j].first <= x && seen[i][j].second <= y) {
        ans++;
      }
    }
  }
  cout << ans << endl;
}
