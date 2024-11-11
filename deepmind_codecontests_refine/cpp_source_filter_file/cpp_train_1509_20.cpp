#include <bits/stdc++.h>
const int INF = 1e9 + 100;
const long long lINF = 1e18;
const double EPS = 1e-12;
using namespace std;
const int N = 2200;
int n, m, s, t;
long long p[N], dist[N];
int short_dist_i[N], short_dist_j[N];
long long cnt[N][N], sum[N][N], mni[N][N], mnj[N][N], mxi[N][N], mxj[N][N];
vector<pair<int, long long> > graph[N];
void dijk(int b, int* short_dist) {
  for (int i = 0; i < n; i++) {
    dist[i] = lINF;
  }
  set<pair<long long, int> > magic;
  dist[b] = 0;
  magic.insert(make_pair(0, b));
  while (magic.size()) {
    int cur = magic.begin()->second;
    magic.erase(magic.begin());
    for (auto& i : graph[cur]) {
      int ndist = dist[cur] + i.second;
      if (ndist < dist[i.first]) {
        magic.erase(make_pair(dist[i.first], i.first));
        dist[i.first] = ndist;
        magic.insert(make_pair(dist[i.first], i.first));
      }
    }
  }
  vector<long long> sorted(n);
  for (int i = 0; i < n; i++) {
    sorted[i] = dist[i];
  }
  sort((sorted).begin(), (sorted).end());
  sorted.resize(
      distance(sorted.begin(), unique((sorted).begin(), (sorted).end())));
  for (int i = 0; i < n; i++) {
    short_dist[i] =
        (int)(lower_bound((sorted).begin(), (sorted).end(), dist[i]) -
              sorted.begin());
  }
}
int main() {
  scanf("%d%d%d%d", &n, &m, &s, &t);
  s--, t--;
  for (int i = 0; i < n; i++) {
    scanf("%lld", &p[i]);
  }
  for (int i = 0; i < m; i++) {
    int v, u, w;
    scanf("%d%d%d", &v, &u, &w);
    v--, u--;
    graph[v].emplace_back(u, w);
    graph[u].emplace_back(v, w);
  }
  dijk(s, short_dist_i);
  dijk(t, short_dist_j);
  for (int i = 0; i < n; i++) {
    cnt[short_dist_i[i]][short_dist_j[i]]++;
    sum[short_dist_i[i]][short_dist_j[i]] += p[i];
  }
  for (int i = n; i >= 0; i--) {
    for (int j = 0; j <= n; j++) {
      cnt[i][j] += cnt[i + 1][j];
      sum[i][j] += sum[i + 1][j];
    }
  }
  for (int j = n; j >= 0; j--) {
    for (int i = 0; i <= n; i++) {
      cnt[i][j] += cnt[i][j + 1];
      sum[i][j] += sum[i][j + 1];
    }
  }
  for (int i = 0; i <= n; i++) {
    cnt[n + 1][i] = cnt[i][n + 1] = INF;
  }
  for (int i = n; i >= 0; i--) {
    for (int j = n; j >= 0; j--) {
      mni[i][j] = mni[i + 1][j];
      mnj[i][j] = mnj[i][j + 1];
      if (cnt[i][j] != cnt[i + 1][j]) {
        mni[i][j] = i + 1;
      }
      if (cnt[i][j] != cnt[i][j + 1]) {
        mnj[i][j] = j + 1;
      }
    }
  }
  long long dpi = 0, dpj = 0;
  for (int i = n; i >= 0; i--) {
    for (int j = n; j >= 0; j--) {
      dpi = sum[i][j] - mxi[mni[i][j]][j];
      dpj = sum[i][j] - mxj[i][mnj[i][j]];
      mxi[i][j] = min(mxi[i + 1][j], sum[i][j] + dpj);
      mxj[i][j] = min(mxj[i][j + 1], sum[i][j] + dpi);
    }
  }
  if (dpi > 0) {
    printf("Break a heart");
  } else if (dpi == 0) {
    printf("Flowers");
  } else if (dpi < 0) {
    printf("Cry");
  }
  return 0;
}
