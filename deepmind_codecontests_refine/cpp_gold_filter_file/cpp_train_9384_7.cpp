#include <bits/stdc++.h>
using namespace std;
const int maxn = 6e5 + 10;
long long d1[maxn], d2[maxn][2];
vector<pair<int, int> > g[maxn];
vector<pair<int, int> > allq;
vector<int> que[maxn], cur_query;
long long res[maxn];
long long dist_temp[maxn][2];
int cnt[maxn];
int n;
bool vis[maxn];
int last[maxn];
void preprocess() {
  priority_queue<pair<long long, int>, vector<pair<long long, int> >,
                 greater<pair<long long, int> > >
      q;
  for (int i = 0; i < n; i++) {
    q.push(pair<long long, int>(d1[i], i));
  }
  while (!q.empty()) {
    pair<int, int> u = q.top();
    q.pop();
    int x = u.second;
    if (u.first > d1[x]) continue;
    for (auto temp : g[x]) {
      long long w = d2[temp.second][0] + d2[temp.second][1];
      if (d1[x] + w < d1[temp.first]) {
        d1[temp.first] = d1[x] + w;
        q.push(pair<int, int>(d1[temp.first], temp.first));
      }
    }
  }
}
pair<int, int> cur_cetroid;
int cur_sz, cur_id;
void get_cetroid(int o, int p = -1) {
  int temp = 0, all = 0;
  for (auto u : g[o]) {
    if (u.first != p && !vis[u.first]) {
      get_cetroid(u.first, o);
      temp = max(temp, cnt[u.first]);
      all += cnt[u.first];
    }
  }
  temp = max(temp, cur_sz - all - 1);
  cur_cetroid = min(cur_cetroid, pair<int, int>(temp, o));
}
void dfs1(int o, int p = -1) {
  cnt[o] = 1;
  for (auto u : g[o]) {
    if (u.first != p && !vis[u.first]) {
      dfs1(u.first, o);
      cnt[o] += cnt[u.first];
    }
  }
}
void dfs2(int o, int p = -1, int e = -1) {
  if (p == -1) {
    dist_temp[(o << 1)][0] = dist_temp[(o << 1 | 1)][1] = 0;
    dist_temp[(o << 1 | 1)][0] = dist_temp[(o << 1)][1] = d1[o];
  } else {
    for (int k = 0; k < 2; k++) {
      long long t0 = dist_temp[(p << 1)][k] + d2[e][0];
      long long t1 = dist_temp[(p << 1 | 1)][k] + d2[e][1];
      dist_temp[(o << 1)][k] = min(t0, t1 + d1[o]);
      dist_temp[(o << 1 | 1)][k] = min(t1, t0 + d1[o]);
    }
  }
  for (auto u : que[o]) {
    if (res[u] != -1) continue;
    if (last[u] == cur_id) {
      cur_query.push_back(u);
    } else {
      last[u] = cur_id;
    }
  }
  for (auto u : g[o]) {
    if (!vis[u.first] && p != u.first) {
      dfs2(u.first, o, u.second);
    }
  }
}
void centroid(int o = 0) {
  dfs1(o);
  cur_cetroid = make_pair(INT_MAX, -1);
  cur_sz = cnt[o];
  get_cetroid(o);
  int temp_cetroid = cur_cetroid.second;
  vis[temp_cetroid] = 1;
  for (auto u : g[temp_cetroid]) {
    if (!vis[u.first]) {
      centroid(u.first);
    }
  }
  vis[temp_cetroid] = 0;
  cur_id++;
  cur_query.clear();
  dfs2(temp_cetroid);
  for (int i : cur_query) {
    int u = allq[i].first, v = allq[i].second;
    res[i] = min(dist_temp[u][0] + dist_temp[v][0],
                 dist_temp[u][1] + dist_temp[v][1]);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld", &d1[i]);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    long long w1, w2;
    scanf("%d%d%lld%lld", &a, &b, &w1, &w2);
    --a;
    --b;
    d2[i][0] = w1;
    d2[i][1] = w2;
    g[a].push_back(pair<int, int>(b, i));
    g[b].push_back(pair<int, int>(a, i));
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a;
    --b;
    allq.push_back(pair<int, int>(a, b));
    que[a / 2].push_back(i);
    que[b / 2].push_back(i);
  }
  preprocess();
  for (int i = 0; i < q; i++) res[i] = -1;
  centroid();
  for (int i = 0; i < q; i++) printf("%lld\n", res[i]);
  return 0;
}
