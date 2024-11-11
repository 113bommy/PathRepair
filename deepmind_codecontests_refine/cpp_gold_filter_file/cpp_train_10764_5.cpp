#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, m, k, d[N][N], num[N], par[N], level[N];
pair<int, int> e[N];
struct dd {
  int r, x, y;
} c[N];
vector<int> ke[N];
bool cmp(dd a, dd b) { return (a.r > b.r); }
bool incircle(int i, int x, int y) {
  long long R = c[i].r, a = c[i].x, b = c[i].y;
  long long tmp = (a - x) * (a - x) + (b - y) * (b - y);
  return (tmp < R * R);
}
void Dij(int x) {
  for (int i = 0; i <= m; ++i) d[x][i] = 1e9;
  priority_queue<pair<int, int>, vector<pair<int, int> >,
                 greater<pair<int, int> > >
      q;
  q.push({0, x});
  d[x][x] = 0;
  while (!q.empty()) {
    int u = q.top().second;
    int du = q.top().first;
    if (du != d[x][u]) continue;
    q.pop();
    for (int i = 0; i < ke[u].size(); ++i) {
      int v = ke[u][i];
      if (d[x][v] > d[x][u] + 1) {
        d[x][v] = d[x][u] + 1;
        q.push({d[x][v], v});
      }
    }
  }
}
void Init() {
  sort(c + 1, c + m + 1, cmp);
  for (int i = 1; i <= m; ++i) {
    level[i] = max(1, level[i]);
    for (int j = i + 1; j <= m; ++j) {
      if (incircle(i, c[j].x, c[j].y))
        if (level[j] < level[i] + 1) {
          level[j] = level[i] + 1;
          par[j] = i;
        }
    }
  }
  for (int i = 1; i <= n; ++i)
    for (int j = m; j >= 1; --j) {
      if (!incircle(j, e[i].first, e[i].second)) continue;
      if (level[num[i]] < level[j]) num[i] = j;
    }
  for (int i = 1; i <= m; ++i) {
    int u = i, v = par[i];
    ke[u].push_back(v);
    ke[v].push_back(u);
  }
  for (int i = 0; i <= m; ++i) Dij(i);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) cin >> e[i].first >> e[i].second;
  for (int i = 1; i <= m; ++i) cin >> c[i].r >> c[i].x >> c[i].y;
  Init();
  for (int i = 1; i <= k; ++i) {
    int a, b;
    cin >> a >> b;
    cout << d[num[a]][num[b]] << "\n";
  }
  return 0;
}
