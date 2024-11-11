#include <bits/stdc++.h>
using namespace std;
int n, m, p;
int chest[305][305];
vector<pair<int, int> > record[90005];
long long dp[305][305];
int xp, yp;
void input() {
  scanf("%d %d %d", &n, &m, &p);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      scanf("%d", &chest[i][j]);
      if (chest[i][j] == p) {
        xp = i;
        yp = j;
      }
    }
}
int dist(int x1, int y1, int x2, int y2) { return abs(x2 - x1) + abs(y2 - y1); }
void build() {
  int cur = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      record[chest[i][j]].push_back(make_pair(i, j));
    }
}
struct node {
  int r, c;
  int ind;
  int cost;
};
long long cost[305][305];
class mycomp {
 public:
  bool operator()(const node& l, const node& r) const {
    return l.cost > r.cost;
  }
};
void bfs(int color) {
  queue<node> q;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cost[i][j] = 10000000;
  for (int i = 0; i < record[color].size(); i++) {
    pair<int, int> p1 = record[color][i];
    node temp;
    temp.r = p1.first, temp.c = p1.second, temp.ind = i;
    cost[temp.r][temp.c] = dp[p1.first][p1.second];
    q.push(temp);
  }
  int dr[] = {-1, 1, 0, 0};
  int dc[] = {0, 0, -1, 1};
  while (!q.empty()) {
    node top = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int rr = top.r + dr[i];
      int cc = top.c + dc[i];
      if (rr > n || rr <= 0 || cc > m || cc <= 0) continue;
      if (cost[rr][cc] > cost[top.r][top.c] + 1) {
        cost[rr][cc] = cost[top.r][top.c] + 1;
        node temp;
        temp.r = rr, temp.c = cc, temp.ind = top.ind;
        q.push(temp);
      }
    }
  }
  for (int i = 0; i < record[color + 1].size(); i++) {
    pair<int, int> p1 = record[color + 1][i];
    dp[p1.first][p1.second] = cost[p1.first][p1.second];
  }
}
void solve() {
  for (int i = 0; i < record[1].size(); i++) {
    pair<int, int> p1 = record[1][i];
    dp[p1.first][p1.second] = dist(1, 1, p1.first, p1.second);
  }
  for (int i = 2; i <= p; i++) {
    if (record[i].size() * record[i - 1].size() >= n * m) {
      bfs(i - 1);
      continue;
    }
    for (int j = 0; j < record[i].size(); j++) {
      long long ans = 10000000;
      pair<int, int> p1 = record[i][j];
      for (int k = 0; k < record[i - 1].size(); k++) {
        pair<int, int> p2 = record[i - 1][k];
        ans =
            min(ans, (long long)dist(p1.first, p1.second, p2.first, p2.second) +
                         dp[p2.first][p2.second]);
      }
      dp[p1.first][p1.second] = ans;
    }
  }
  cout << dp[xp][yp] << endl;
}
int main() {
  input();
  build();
  solve();
}
