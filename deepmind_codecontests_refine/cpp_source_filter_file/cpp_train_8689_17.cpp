#include <bits/stdc++.h>
using namespace std;
const long long N = 1500, E = N * N * 2, INF = 1e9 + 7, TINF = 1e12, T = N - 3;
char s[500][500];
int from[E], to[E], cap[E], prv[E], e;
long long head[N], ptr[N], q[N], d[N];
long long n, m, x1, x2, num, Num[500][500], dis[500][500];
vector<pair<pair<int, int>, long long>> v1, v2;
void add_edge(int u, int v, int uv, int vu = 0) {
  from[e] = u, to[e] = v, cap[e] = uv, prv[e] = head[u], head[u] = e++;
  from[e] = v, to[e] = u, cap[e] = vu, prv[e] = head[v], head[v] = e++;
}
bool bfs(int source, int sink) {
  memset(d, 63, sizeof d);
  d[source] = 0;
  int h = 0, t = 0;
  q[t++] = source;
  while (h < t) {
    int v = q[h++];
    for (int i = head[v]; i != -1; i = prv[i]) {
      int u = to[i];
      if (cap[i] && d[u] > d[v] + 1) {
        q[t++] = u;
        d[u] = d[v] + 1;
      }
    }
  }
  return (d[sink] < 1e9);
}
int dfs(int v, int sink, int flow = INF) {
  if (v == sink || flow == 0) return flow;
  int ans = 0;
  for (; ptr[v] != -1; ptr[v] = prv[ptr[v]]) {
    int i = ptr[v], u = to[i];
    if (d[u] == d[v] + 1) {
      int x = dfs(u, sink, min(flow, cap[i]));
      cap[i] -= x;
      cap[i ^ 1] += x;
      flow -= x;
      ans += x;
      if (flow == 0) break;
    }
  }
  return ans;
}
int max_flow(int source, int sink) {
  int ans = 0;
  while (bfs(source, sink)) {
    memcpy(ptr, head, sizeof head);
    ans += dfs(source, sink);
  }
  return ans;
}
void make(long long mid) {
  int source = N - 1, sink = N - 2;
  memset(head, -1, sizeof head);
  e = 0;
  for (int i = 0; i < num; i++) add_edge(i, T - i, 1);
  for (int i = 0; i < x1; i++) add_edge(source, num + i, 1);
  for (int i = 0; i < x2; i++) add_edge(i + x1 + num, sink, 1);
  for (int i = 0; i < x1; i++) {
    for (int r = 1; r <= n; r++) {
      for (int c = 1; c <= m; c++) {
        if (s[r][c] == '#') continue;
        if (dis[Num[v1[i].first.first][v1[i].first.second]][Num[r][c]] !=
                dis[499][498] &&
            dis[Num[v1[i].first.first][v1[i].first.second]][Num[r][c]] *
                    v1[i].second <=
                mid) {
          add_edge(num + i, Num[r][c], 1);
        }
      }
    }
  }
  for (int i = 0; i < x2; i++) {
    for (int r = 1; r <= n; r++) {
      for (int c = 1; c <= m; c++) {
        if (s[r][c] == '#') continue;
        if (dis[Num[v2[i].first.first][v2[i].first.second]][Num[r][c]] !=
                dis[499][498] &&
            dis[Num[v2[i].first.first][v2[i].first.second]][Num[r][c]] *
                    v2[i].second <=
                mid) {
          add_edge(T - Num[r][c], num + x1 + i, 1);
        }
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> x1 >> x2;
  int source = N - 1, sink = N - 2;
  for (int i = 0; i <= n + 1; i++)
    for (int j = 0; j <= m + 1; j++) s[i][j] = '#';
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> s[i][j];
  int X[] = {0, 1, 0, -1}, Y[] = {1, 0, -1, 0};
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) Num[i][j] = num++;
  memset(dis, 63, sizeof dis);
  for (int i = 0; i < 500; i++) dis[i][i] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      for (int k = 0; k < 4; k++)
        if (s[i][j] != '#' && s[i + X[k]][j + Y[k]] != '#')
          dis[Num[i][j]][Num[i + X[k]][j + Y[k]]] = 1;
  for (int k = 0; k < num; k++)
    for (int i = 0; i < num; i++)
      for (int j = 0; j < num; j++)
        dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
  int f1, f2, f3;
  cin >> f1 >> f2 >> f3;
  for (int i = 0; i < x1; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    v1.push_back({{x, y}, z});
  }
  for (int i = 0; i < x2; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    v2.push_back({{x, y}, z});
  }
  if (x1 < x2) {
    x1++;
    v1.push_back({{f1, f2}, f3});
  } else {
    x2++;
    v2.push_back({{f1, f2}, f3});
  }
  if (v2.size() != v1.size()) {
    cout << "-1" << endl;
    return 0;
  }
  long long l = -1, r = TINF, MXF;
  while (r - l > 1) {
    long long mid = (r + l) / 2;
    make(mid);
    MXF = max_flow(source, sink);
    if (MXF == x1)
      r = mid;
    else
      l = mid;
  }
  if (r == TINF) {
    cout << "-1" << endl;
    return 0;
  }
  cout << r << endl;
  return 0;
}
