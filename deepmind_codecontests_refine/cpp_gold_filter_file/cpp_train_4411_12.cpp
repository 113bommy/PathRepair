#include <bits/stdc++.h>
using namespace std;
const long long nInf = -1000000000;
const long long pInf = 1000000000;
const long long mod = 1000000007;
const int MAXN = 1e5 + 10;
void getdata();
void preproc();
void solve();
int dists[MAXN], distsin[MAXN];
int n, m;
vector<vector<pair<int, int> > > g;
vector<vector<int> > locked, fr;
bool used[MAXN];
void dfs(int v);
void dijkstra(int v);
int main() {
  int t = 1;
  for (int i = 0; i < t; i++) {
    getdata();
    preproc();
    solve();
  }
  return 0;
}
void getdata() {
  scanf("%d %d", &n, &m);
  g.resize(n);
  locked.resize(n);
  fr.resize(n);
  for (int i = 0; i < m; i++) {
    int x, y, d;
    scanf("%d %d %d", &x, &y, &d);
    x--;
    y--;
    g[x].push_back(make_pair(y, d));
    g[y].push_back(make_pair(x, d));
  }
  for (int i = 0; i < n; i++) {
    int k;
    scanf("%d", &k);
    for (int j = 0; j < k; j++) {
      int t;
      scanf("%d", &t);
      locked[i].push_back(t);
    }
    locked[i].push_back(2 * pInf);
    for (int j = 0; j < k; j++) {
      int j1 = j;
      int next1 = -1;
      while (j1 < k && locked[i][j1] == locked[i][j1 + 1] - 1) j1++;
      if (j1 == (int)locked[i].size())
        next1 = locked[i][k - 1] + 1;
      else
        next1 = locked[i][j1] + 1;
      for (int l = 0; l <= j1 - j; l++) {
        fr[i].push_back(next1);
      }
      j = j1;
    }
  }
}
void preproc() {}
void solve() {
  dfs(0);
  if (!used[n - 1]) {
    printf("-1\n");
    return;
  }
  dijkstra(0);
  printf("%d\n", dists[n - 1]);
}
void dfs(int v) {
  used[v] = true;
  for (int i = 0; i < (int)g[v].size(); i++) {
    int to = g[v][i].first;
    if (!used[to]) dfs(to);
  }
}
void dijkstra(int v) {
  fill(dists, dists + n, 2 * pInf);
  dists[v] = 0;
  multimap<int, int> q;
  q.insert(make_pair(0, v));
  while (!q.empty()) {
    auto it = q.begin();
    int num = (*it).second;
    int dist = (*it).first;
    q.erase(it);
    for (int i = 0; i < (int)g[num].size(); i++) {
      int num1 = g[num][i].first;
      int dist1 = g[num][i].second;
      int wait = 0;
      auto it1 = lower_bound(locked[num].begin(), locked[num].end(), dist);
      if (it1 == locked[num].end())
        wait = 0;
      else if ((*it1) == dist) {
        int num2 = it1 - locked[num].begin();
        wait = fr[num][num2] - locked[num][num2];
      }
      if (dists[num1] > dist + dist1 + wait) {
        dists[num1] = dist + dist1 + wait;
        q.insert(make_pair(dists[num1], num1));
      }
    }
  }
}
