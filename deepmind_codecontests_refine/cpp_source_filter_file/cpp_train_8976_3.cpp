#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const long long INF = 1e18 + 7;
int dis[10010][1010];
int pa[10010][1010];
bitset<1010> inq[10010];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> v(m);
  for (int& t : v) cin >> t;
  sort((v).begin(), (v).end());
  int g, r;
  cin >> g >> r;
  deque<pair<int, int> > q;
  for (int i = 0; i < m; i++) fill(dis[i], dis[i] + g + 1, inf);
  dis[0][0] = 0;
  q.emplace_back(0, 0);
  while (!q.empty()) {
    int i = q.front().first, j = q.front().second;
    q.pop_front();
    if (i == m - 1) continue;
    inq[i][j] = 0;
    if (j == g) {
      if (dis[i][0] > dis[i][j] + 1) {
        dis[i][0] = dis[i][j] + 1;
        if (!inq[i][0]) {
          if (!q.empty() &&
              pair<int, int>(dis[i][0], 0) <
                  pair<int, int>(dis[q.front().first][q.front().second],
                                 q.front().second))
            q.emplace_front(i, 0);
          else
            q.emplace_back(i, 0);
          inq[i][0] = 1;
        }
      }
      continue;
    }
    if (i != 0) {
      int tm = j + v[i] - v[i - 1];
      if (tm >= g) {
        if (dis[i - 1][tm] > dis[i][j]) {
          dis[i - 1][tm] = dis[i][j];
          if (!inq[i - 1][tm]) {
            if (!q.empty() &&
                pair<int, int>(dis[i - 1][tm], tm) <
                    pair<int, int>(dis[q.front().first][q.front().second],
                                   q.front().second))
              q.emplace_front(i - 1, tm);
            else
              q.emplace_back(i - 1, tm);
            inq[i - 1][tm] = 1;
          }
        }
      }
    }
    int tm = j + v[i + 1] - v[i];
    if (tm > g) continue;
    if (dis[i + 1][tm] > dis[i][j]) {
      dis[i + 1][tm] = dis[i][j];
      if (!inq[i + 1][tm]) {
        if (!q.empty() &&
            pair<int, int>(dis[i + 1][tm], tm) <
                pair<int, int>(dis[q.front().first][q.front().second],
                               q.front().second))
          q.emplace_front(i + 1, tm);
        else
          q.emplace_back(i + 1, tm);
        inq[i + 1][tm] = 1;
      }
    }
  }
  long long mn = INF;
  for (int i = 0; i <= g; i++)
    mn = min(mn, (long long)dis[m - 1][i] * (g + r) + i);
  if (mn >= (long long)inf * (g + r)) mn = -1;
  cout << mn << endl;
  return 0;
}
