#include <bits/stdc++.h>
using namespace ::std;
const int N = 1000, M = 30000, INF = 2140000000;
int ans = INF;
int n, m;
int s, t;
bool is_cut_edge[M + 5];
bool is_cut_edge2[M + 5];
int w[M + 5];
int c;
int ans1, ans2;
vector<pair<int, int> > ad[N + 5];
vector<int> path, path2;
vector<int> now_path, now_path2;
bool visited[N + 5], visited2[N + 5];
int cut_edge;
int level[N + 5];
int min_edge[N + 5][N + 5];
int cnt_edge[N + 5][N + 5];
pair<int, int> dfs(int now) {
  visited[now] = true;
  if (now == t) path = now_path;
  pair<int, int> ret = pair<int, int>(INF, 0);
  for (int i = 0; i < ad[now].size(); i++) {
    int next = ad[now][i].first;
    int edge_num = ad[now][i].second;
    if (!visited[next]) {
      level[next] = level[now] + 1;
      now_path.push_back(edge_num);
      pair<int, int> next_ret = dfs(next);
      now_path.pop_back();
      if (next_ret.first < ret.first)
        ret = next_ret;
      else if (next_ret.first == ret.first)
        ret.second += next_ret.second;
      if (next_ret.first == level[now] && next_ret.second == 1)
        is_cut_edge[edge_num] = true;
    } else {
      if (ret.first > level[next])
        ret = pair<int, int>(level[next], 1);
      else if (level[next] == ret.first)
        ret.second++;
    }
  }
  return ret;
}
pair<int, int> dfs2(int now) {
  visited2[now] = true;
  if (now == t) path2 = now_path2;
  pair<int, int> ret = pair<int, int>(INF, 0);
  for (int i = 0; i < ad[now].size(); i++) {
    int next = ad[now][i].first;
    int edge_num = ad[now][i].second;
    if (cut_edge == edge_num) continue;
    if (!visited2[next]) {
      level[next] = level[now] + 1;
      now_path2.push_back(edge_num);
      pair<int, int> next_ret = dfs2(next);
      now_path2.pop_back();
      if (next_ret.first < ret.first)
        ret = next_ret;
      else if (next_ret.first == ret.first)
        ret.second += next_ret.second;
      if (next_ret.first == level[now] && next_ret.second == 1)
        is_cut_edge2[edge_num] = true;
    } else {
      if (ret.first > level[next])
        ret = pair<int, int>(level[next], 1);
      else if (level[next] == ret.first)
        ret.second++;
    }
  }
  return ret;
}
int main() {
  scanf("%d %d", &n, &m);
  scanf("%d %d", &s, &t);
  for (int i = 1; i <= m; i++) {
    int v1, v2;
    scanf("%d %d %d", &v1, &v2, &w[i]);
    ad[v1].push_back(pair<int, int>(v2, i));
    ad[v2].push_back(pair<int, int>(v1, i));
    if (min_edge[v1][v2] == 0 || w[min_edge[v1][v2]] > w[i])
      min_edge[v1][v2] = i;
    cnt_edge[v1][v2]++;
    swap(v1, v2);
    if (min_edge[v1][v2] == 0 || w[min_edge[v1][v2]] > w[i])
      min_edge[v1][v2] = i;
    cnt_edge[v1][v2]++;
  }
  pair<int, int> received = dfs(s);
  if (path.size() == 0) {
    printf("0");
    return 0;
  }
  for (int i = 0; i < path.size(); i++) {
    if (is_cut_edge[path[i]]) {
      if (w[path[i]] < ans) {
        ans = w[path[i]];
        c = 1;
        ans1 = path[i];
      }
    } else {
      cut_edge = path[i];
      for (int i = 1; i <= n; i++) visited2[i] = false;
      for (int i = 1; i <= m; i++) is_cut_edge2[i] = false;
      received = dfs2(s);
      for (int j = 0; j < path2.size(); j++)
        if (is_cut_edge2[path2[j]]) {
          if (w[path[i]] + w[path2[j]] < ans) {
            ans = w[path[i]] + w[path2[j]];
            c = 2;
            ans1 = path[i];
            ans2 = path2[j];
          }
        }
    }
  }
  if (ans == INF) {
    printf("-1");
    return 0;
  }
  printf("%d\n%d\n%d ", ans, c, ans1);
  if (c == 2) printf("%d", ans2);
  return 0;
}
