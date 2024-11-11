#include <bits/stdc++.h>
using namespace std;
const int N = 55;
const int inf = 1e9 + 5;
const int mod = 1e9 + 7;
int n, m;
vector<vector<pair<int, int> > > g;
int dist[N][N];
int dp[N][N];
int criminals[N];
int good_dfs(int v, int mm, int ans, int p, int vv) {
  int cnt = 0;
  for (auto to : g[v]) {
    if (to.first == p) continue;
    if (ans - to.second >= 0) {
      cnt += good_dfs(to.first, mm, ans - to.second, v, vv);
      if (cnt >= inf) return inf;
    } else {
      return inf;
    }
  }
  if (g[v].size() == 1 && v != vv) {
    for (int i = mm; i >= 0; --i) {
      if (ans >= dp[v][i]) {
        cnt += mm - i - 1;
        if (i == mm) {
          cnt -= (1 << 17);
        }
        break;
      }
    }
  }
  return cnt;
}
int bad_dfs(int v, int mm, int cmp, int ans, int p) {
  int cnt = 0;
  for (auto to : g[v]) {
    if (to.first == p) continue;
    if (ans - to.second >= 0) {
      cnt += bad_dfs(to.first, mm, cmp, ans - to.second, v);
      if (cnt >= inf) return inf;
    } else {
      return inf;
    }
  }
  if (g[v].size() == 1) {
    int flag = 0;
    for (int i = mm; i >= mm - cmp; --i) {
      if (ans >= dp[v][i]) {
        flag = 1;
        cnt += mm - i - 1;
        if (i == mm) {
          cnt -= (1 << 17);
        }
        break;
      }
    }
    if (!flag) return inf;
  }
  return cnt;
}
int s;
int comp[N];
int used[N];
int dfs(int v, int p, int id) {
  used[v] = 1;
  int ans = criminals[v];
  for (auto to : g[v]) {
    if (to.first == p) continue;
    ans += dfs(to.first, v, id);
  }
  return ans;
}
vector<int> leafs;
int main() {
  cin >> n;
  g.resize(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      dist[i][j] = inf * (i != j);
    }
  }
  for (int i = 0; i < n - 1; ++i) {
    int x, y, w;
    cin >> x >> y >> w;
    --x;
    --y;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
    dist[x][y] = w;
    dist[y][x] = w;
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (g[i].size() == 1) leafs.push_back(i);
  }
  cin >> s;
  --s;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    criminals[--x]++;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= m; ++j) {
      dp[i][j] = (1 << 17);
    }
  }
  for (int mm = 1; mm <= m; ++mm) {
    for (auto v : leafs) {
      int ans = (1 << 17);
      int l = 0;
      int r = (1 << 17);
      while (l <= r) {
        int mid = (l + r) / 2;
        if (good_dfs(v, mm, mid, -1, v) < mm) {
          ans = mid;
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }
      dp[v][mm] = ans;
    }
  }
  int number = 0;
  map<int, int> mp;
  for (auto it : g[s]) {
    comp[number] = dfs(it.first, s, number);
    mp[it.first] = number;
    number++;
  }
  memset(used, 0, sizeof(used));
  used[s] = 1;
  int main_ans = inf;
  for (auto v : g[s]) {
    int ans = (1 << 17);
    int l = 0;
    int r = (1 << 17);
    int id = mp[v.first];
    int cmp = comp[id];
    while (l <= r) {
      int mid = (l + r) / 2;
      if (bad_dfs(v.first, m, cmp, mid, s) < cmp) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    main_ans = min(main_ans, ans + v.second);
  }
  cout << main_ans << endl;
  return 0;
}
