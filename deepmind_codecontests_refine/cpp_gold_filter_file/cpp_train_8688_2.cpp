#include <bits/stdc++.h>
using namespace std;
int h, t, r, n, m;
pair<int, int> a_head[220], a_tail[220];
int dist[220][220];
int in_time[220][220];
int out_time[220][220];
int l_tm, longest;
vector<pair<int, int> > topo;
void dp() {
  memset(dist, -1, sizeof(dist));
  dist[h][t] = 0;
  longest = -1;
  for (int t = topo.size() - 1; t >= 0; --t) {
    pair<int, int> u = topo[t];
    if (dist[u.first][u.second] == -1) {
      continue;
    }
    pair<int, int> v;
    for (int i = 1; i <= min(n, u.first); ++i) {
      v.first = u.first - i + a_head[i].first;
      v.second = u.second + a_head[i].second;
      if (v.first + v.second > r) {
        longest = max(longest, dist[u.first][u.second] + 1);
      }
      dist[v.first][v.second] =
          max(dist[v.first][v.second], dist[u.first][u.second] + 1);
    }
    for (int i = 1; i <= min(m, u.second); ++i) {
      v.first = u.first + a_tail[i].first;
      v.second = u.second - i + a_tail[i].second;
      if (v.first + v.second > r) {
        longest = max(longest, dist[u.first][u.second] + 1);
      }
      dist[v.first][v.second] =
          max(dist[v.first][v.second], dist[u.first][u.second] + 1);
    }
  }
}
bool dfs(pair<int, int> u) {
  ++l_tm;
  in_time[u.first][u.second] = l_tm;
  pair<int, int> v;
  for (int i = 1; i <= min(n, u.first); ++i) {
    v.first = u.first - i + a_head[i].first;
    v.second = u.second + a_head[i].second;
    if (v.first + v.second > r) {
      continue;
    }
    if (in_time[v.first][v.second] == -1) {
      if (!dfs(v)) {
        return false;
      }
    } else {
      if (in_time[v.first][v.second] <= in_time[u.first][u.second] &&
          out_time[v.first][v.second] == -1) {
        return false;
      }
    }
  }
  for (int i = 1; i <= min(m, u.second); ++i) {
    v.first = u.first + a_tail[i].first;
    v.second = u.second - i + a_tail[i].second;
    if (v.first + v.second > r) {
      continue;
    }
    if (in_time[v.first][v.second] == -1) {
      if (!dfs(v)) {
        return false;
      }
    } else {
      if (in_time[v.first][v.second] <= in_time[u.first][u.second] &&
          out_time[v.first][v.second] == -1) {
        return false;
      }
    }
  }
  ++l_tm;
  out_time[u.first][u.second] = l_tm;
  topo.push_back(u);
  return true;
}
int bfs() {
  memset(dist, -1, sizeof(dist));
  queue<pair<int, int> > q;
  q.push(make_pair(h, t));
  dist[h][t] = 0;
  while (!q.empty()) {
    pair<int, int> u = q.front();
    q.pop();
    pair<int, int> v;
    for (int i = 1; i <= min(n, u.first); ++i) {
      v.first = u.first - i + a_head[i].first;
      v.second = u.second + a_head[i].second;
      if (v.first + v.second > r) {
        continue;
      }
      if (dist[v.first][v.second] == -1) {
        dist[v.first][v.second] = dist[u.first][u.second] + 1;
        if (v.first + v.second == 0) {
          return dist[v.first][v.second];
        }
        q.push(v);
      }
    }
    for (int i = 1; i <= min(m, u.second); ++i) {
      v.first = u.first + a_tail[i].first;
      v.second = u.second - i + a_tail[i].second;
      if (v.first + v.second > r) {
        continue;
      }
      if (dist[v.first][v.second] == -1) {
        dist[v.first][v.second] = dist[u.first][u.second] + 1;
        if (v.first + v.second == 0) {
          return dist[v.first][v.second];
        }
        q.push(v);
      }
    }
  }
  return -1;
}
int main() {
  scanf("%d%d%d", &h, &t, &r);
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    a_head[i] = make_pair(x, y);
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    a_tail[i] = make_pair(x, y);
  }
  int shortest = bfs();
  if (shortest != -1) {
    cout << "Ivan" << endl;
    cout << shortest << endl;
    return 0;
  }
  l_tm = 0;
  memset(in_time, -1, sizeof(in_time));
  memset(out_time, -1, sizeof(out_time));
  topo.clear();
  if (!dfs(make_pair(h, t))) {
    cout << "Draw" << endl;
    return 0;
  }
  memset(dist, -1, sizeof(dist));
  dp();
  cout << "Zmey" << endl;
  cout << longest << endl;
  return 0;
}
