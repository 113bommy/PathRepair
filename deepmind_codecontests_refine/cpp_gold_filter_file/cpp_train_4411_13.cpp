#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const int MAXN = 100000 + 1;
vector<vector<pair<int, int> > > g;
long long dst[MAXN];
vector<int> t[MAXN];
vector<int> wait[MAXN];
int binarySearch(int ind, int val) {
  int l = 0, r = (int)t[ind].size() - 1;
  while (l < r) {
    int m = (l + r) >> 1;
    if (val > t[ind][m]) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  return l;
}
int main() {
  int N, M;
  scanf("%d%d", &N, &M);
  g.resize(N);
  for (int i = 0; i < M; ++i) {
    int u, v, d;
    scanf("%d%d%d", &u, &v, &d);
    g[u - 1].push_back(make_pair(v - 1, d));
    g[v - 1].push_back(make_pair(u - 1, d));
  }
  for (int i = 0; i < N; ++i) {
    int K;
    scanf("%d", &K);
    t[i].resize(K);
    for (int j = 0; j < K; ++j) {
      scanf("%d", &t[i][j]);
    }
    sort(t[i].begin(), t[i].end());
  }
  for (int i = 0; i < N; ++i) {
    if (t[i].empty()) continue;
    wait[i].resize((int)t[i].size());
    wait[i].back() = 1;
    for (int j = (int)wait[i].size() - 2; j >= 0; --j)
      if (t[i][j] == t[i][j + 1] - 1) {
        wait[i][j] = wait[i][j + 1] + 1;
      } else {
        wait[i][j] = 1;
      }
  }
  for (int i = 1; i < N; ++i) {
    dst[i] = INF;
  }
  if (!t[0].empty() && t[0][0] == 0) {
    dst[0] = wait[0][0];
  }
  set<pair<long long, int> > q;
  q.insert(make_pair(dst[0], 0));
  while (!q.empty()) {
    int v = q.begin()->second;
    q.erase(q.begin());
    for (int i = 0; i < (int)g[v].size(); ++i) {
      int to = g[v][i].first, len = g[v][i].second;
      int timeForWaiting = 0;
      if (!wait[v].empty()) {
        int ind = binarySearch(v, dst[v]);
        if (t[v][ind] == dst[v]) {
          timeForWaiting = wait[v][ind];
        }
      }
      if (dst[v] + len + timeForWaiting < dst[to]) {
        q.erase(make_pair(dst[to], to));
        dst[to] = dst[v] + len + timeForWaiting;
        q.insert(make_pair(dst[to], to));
      }
    }
  }
  if (dst[N - 1] == INF) {
    puts("-1");
  } else {
    printf("%I64d", dst[N - 1]);
  }
  return 0;
}
