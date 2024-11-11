#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m;
bool space[25][25], vis[25][25];
int dist[600][600];
int make_label(int x, int y) { return x * m + y; }
void bfs(int x, int y) {
  memset(vis, 0, sizeof(vis));
  queue<pair<pair<int, int>, int>> que;
  que.push({{x, y}, 0});
  vis[x][y] = 1;
  int s = make_label(x, y);
  while (!que.empty()) {
    auto cur = que.front();
    que.pop();
    dist[s][make_label(cur.first.first, cur.first.second)] = cur.second;
    for (auto &dir : directions) {
      pair<int, int> next_step = {cur.first.first + dir.first,
                                  cur.first.second + dir.second};
      if (next_step.first >= 0 && next_step.first < n &&
          next_step.second >= 0 && next_step.second < m &&
          !vis[next_step.first][next_step.second] &&
          space[next_step.first][next_step.second]) {
        que.push({next_step, cur.second + 1});
        vis[next_step.first][next_step.second] = 1;
      }
    }
  }
}
struct edge {
  int u, v, w;
  edge() {}
  edge(int u, int v, int w) {
    this->u = u;
    this->v = v;
    this->w = w;
  }
};
struct dinic {
  int n, m;
  vector<edge> edge_set;
  vector<vector<int>> graph;
  dinic() {}
  dinic(int n) {
    this->n = n;
    this->m = 0;
    graph.resize(n);
  }
  void add_directed_edge(int u, int v, int w) {
    edge_set.push_back({u, v, w});
    graph[u].push_back(m);
    m++;
    edge_set.push_back({v, u, 0});
    graph[v].push_back(m);
    m++;
  }
  bool bfs(vector<vector<int>> &layered_graph) {
    queue<pair<int, int>> que;
    vector<int> layer(n, -1);
    que.push({0, 0});
    layer[0] = 0;
    while (!que.empty()) {
      auto cur = que.front();
      que.pop();
      if (cur.first == n - 1) {
        return 1;
      }
      for (int e : graph[cur.first]) {
        if (edge_set[e].w > 0) {
          if (layer[edge_set[e].v] == -1) {
            que.push({edge_set[e].v, cur.second + 1});
            layer[edge_set[e].v] = cur.second + 1;
            layered_graph[cur.first].push_back(e);
          } else if (layer[edge_set[e].v] == cur.second + 1) {
            layered_graph[cur.first].push_back(e);
          }
        }
      }
    }
    return 0;
  }
  bool dfs(vector<int> &path, vector<int> &cur_edge,
           vector<vector<int>> &layered_graph, int u) {
    if (u == n - 1) {
      int min_value = 0;
      for (int e : path) {
        if (min_value == 0 || min_value > edge_set[e].w) {
          min_value = edge_set[e].w;
        }
      }
      for (int e : path) {
        edge_set[e].w -= min_value;
        edge_set[e ^ 1].w += min_value;
        if (edge_set[e].w == 0) {
          layered_graph[edge_set[e].u].resize(
              layered_graph[edge_set[e].u].size() - 1);
        }
      }
      return 1;
    }
    while (cur_edge[u] >= 0) {
      swap(layered_graph[u][cur_edge[u]],
           layered_graph[u][layered_graph[u].size() - 1]);
      cur_edge[u]--;
      int e = layered_graph[u][layered_graph[u].size() - 1];
      if (edge_set[e].w > 0) {
        path.push_back(e);
        if (dfs(path, cur_edge, layered_graph, edge_set[e].v)) {
          return 1;
        }
        path.pop_back();
      }
    }
    return 0;
  }
  int max_flow() {
    vector<vector<int>> layered_graph(n);
    while (bfs(layered_graph)) {
      vector<int> path;
      vector<int> cur_edge(n);
      for (int i = 0; i < n; i++) {
        cur_edge[i] = layered_graph[i].size() - 1;
      }
      while (dfs(path, cur_edge, layered_graph, 0)) {
        path.clear();
      }
      layered_graph.clear();
      layered_graph.resize(n);
    }
    int flow = 0;
    for (int e : graph[0]) {
      flow += edge_set[e ^ 1].w;
    }
    return flow;
  }
};
int main() {
  int male, female;
  cin >> n >> m >> male >> female;
  string s;
  vector<pair<int, int>> valid_point;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++) {
      space[i][j] = s[j] == '.';
      if (space[i][j]) {
        valid_point.push_back({i, j});
      }
    }
  }
  memset(dist, 0x3f, sizeof(dist));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (space[i][j]) {
        bfs(i, j);
      }
    }
  }
  vector<pair<pair<int, int>, int>> males, females;
  int x, y, t;
  cin >> x >> y >> t;
  x--;
  y--;
  if (male == female + 1) {
    females.push_back({{x, y}, t});
  } else if (male == female - 1) {
    males.push_back({{x, y}, t});
  } else {
    cout << "-1" << endl;
    exit(0);
  }
  for (int i = 0; i < male; i++) {
    cin >> x >> y >> t;
    x--;
    y--;
    males.push_back({{x, y}, t});
  }
  for (int i = 0; i < female; i++) {
    cin >> x >> y >> t;
    x--;
    y--;
    females.push_back({{x, y}, t});
  }
  male = females.size();
  female = females.size();
  long long lower = 0, upper = 1e12;
  while (lower < upper) {
    long long mid = (lower + upper) / 2;
    int label1 = male + 1, label2 = label1 + valid_point.size(),
        label3 = label2 + valid_point.size(), label4 = label3 + female;
    dinic solver(label4 + 1);
    for (int i = 1; i <= male; i++) {
      solver.add_directed_edge(0, i, 1);
    }
    for (int i = 1; i <= male; i++) {
      for (int j = label1; j < label2; j++) {
        if (dist[make_label(males[i - 1].first.first,
                            males[i - 1].first.second)]
                [make_label(valid_point[j - label1].first,
                            valid_point[j - label1].second)] < 1000 &&
            1ll *
                    dist[make_label(males[i - 1].first.first,
                                    males[i - 1].first.second)]
                        [make_label(valid_point[j - label1].first,
                                    valid_point[j - label1].second)] *
                    males[i - 1].second <=
                mid) {
          solver.add_directed_edge(i, j, 1);
        }
      }
    }
    for (int i = label1; i < label2; i++) {
      solver.add_directed_edge(i, i + valid_point.size(), 1);
    }
    for (int i = label2; i < label3; i++) {
      for (int j = label3; j < label4; j++) {
        if (dist[make_label(valid_point[i - label2].first,
                            valid_point[i - label2].second)]
                [make_label(females[j - label3].first.first,
                            females[j - label3].first.second)] < 1000 &&
            1ll *
                    dist[make_label(valid_point[i - label2].first,
                                    valid_point[i - label2].second)]
                        [make_label(females[j - label3].first.first,
                                    females[j - label3].first.second)] *
                    females[j - label3].second <=
                mid) {
          solver.add_directed_edge(i, j, 1);
        }
      }
    }
    for (int i = label3; i < label4; i++) {
      solver.add_directed_edge(i, label4, 1);
    }
    if (solver.max_flow() == male) {
      upper = mid;
    } else {
      lower = mid + 1;
    }
  }
  cout << (lower == 1e12 ? -1 : lower) << endl;
  return 0;
}
