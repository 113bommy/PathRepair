#include <bits/stdc++.h>
using namespace std;
char adj[55][55];
bool visit[55][55];
int n;
vector<pair<int, int>> s_group;
vector<pair<int, int>> e_group;
void bfs(int r, int c, vector<pair<int, int>>& group) {
  queue<pair<int, int>> q;
  q.push(make_pair(r, c));
  visit[r][c] = true;
  group.push_back(make_pair(r, c));
  while (!q.empty()) {
    pair<int, int> node = q.front();
    q.pop();
    int i = node.first, j = node.second;
    if (i + 1 <= n && adj[i + 1][j] == '0') {
      if (!visit[i + 1][j]) {
        q.push(make_pair(i + 1, j));
        group.push_back(make_pair(i + 1, j));
        visit[i + 1][j] = true;
      }
    }
    if (i - 1 >= 1 && adj[i - 1][j] == '0') {
      if (!visit[i - 1][j]) {
        q.push(make_pair(i - 1, j));
        group.push_back(make_pair(i - 1, j));
        visit[i - 1][j] = true;
      }
    }
    if (j + 1 <= n && adj[i][j + 1] == '0') {
      if (!visit[i][j + 1]) {
        q.push(make_pair(i, j + 1));
        group.push_back(make_pair(i, j + 1));
        visit[i][j + 1] = true;
      }
    }
    if (j - 1 >= 1 && adj[i][j - 1] == '0') {
      if (!visit[i][j - 1]) {
        q.push(make_pair(i, j - 1));
        group.push_back(make_pair(i, j - 1));
        visit[i][j - 1] = true;
      }
    }
  }
}
int main() {
  cin >> n;
  int s_row, s_col;
  cin >> s_row >> s_col;
  int e_row, e_col;
  cin >> e_row >> e_col;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
      cin >> adj[i][j];
    }
  bfs(s_row, s_col, s_group);
  memset(visit, 0, sizeof(visit));
  bfs(e_row, e_col, e_group);
  int min_cost = 3000;
  for (int i = 0; i < s_group.size(); ++i)
    for (int j = 0; j < e_group.size(); ++j) {
      int cost = (s_group[i].first - e_group[j].first) *
                     (s_group[i].first - e_group[j].first) +
                 (s_group[i].second - e_group[j].second) *
                     (s_group[i].second - e_group[j].second);
      if (min_cost > cost) min_cost = cost;
    }
  cout << min_cost;
}
